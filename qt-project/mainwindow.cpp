#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workingwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    config = new Config;
    timer = new QTimer(this);
    workingWindow = new WorkingWindow(this, config);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete config;
    delete workingWindow;
}

void MainWindow::init()
{
    // Установка валидаторов
    ui->Bitmask->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d+"), ui->Bitmask));
    ui->TimerInterval->setValidator(new QRegularExpressionValidator(QRegularExpression("\\d+"), ui->TimerInterval));

    // Коннекты
    connect(timer, &QTimer::timeout, this, &MainWindow::executeOperation);

    // Настройка UI
    ui->EnterBitmask->setText("Enter bitmask(unsigned integer less than " + QString::number(std::numeric_limits<quint64>::max()) + "):");
    ui->DontRemoveInputsFiles->setStyleSheet(StyleSheets::B_SelectedStyle());
}

void MainWindow::resetInputs()
{
    ui->FileMask->setStyleSheet(StyleSheets::LE_DefaulStyle());
    ui->TimerInterval->setStyleSheet(StyleSheets::LE_DefaulStyle());
    ui->OutputDirectory->setStyleSheet(StyleSheets::LE_DefaulStyle());
    ui->Bitmask->setStyleSheet(StyleSheets::LE_DefaulStyle());

    ui->ErrorDisplay->setText("");
}

bool MainWindow::validateInputs()
{
    // Валидация ввода маски входящих файлов
    if(ui->FileMask->text().isEmpty())
    {
        ui->FileMask->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("This field can not be empty");
        return false;
    }

    // Валидация интервала таймера
    if(config->useTimer && ui->TimerInterval->text().isEmpty())
    {
        ui->TimerInterval->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("This field can not be empty");
        return false;
    }

    // Валидация output директории
    if(ui->OutputDirectory->text().isEmpty())
    {
        ui->OutputDirectory->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("This field can not be empty");
        return false;
    }

    // Валидация битовой маски
    QString currentBitmask = ui->Bitmask->text();

    if(currentBitmask.isEmpty())
    {
        ui->Bitmask->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("This field can not be empty");
        return false;
    }

    QString maxBitmask(QString::number(std::numeric_limits<quint64>::max()));

    // Сравниваем размеры строк
    if(currentBitmask.size() > maxBitmask.size())
    {
        ui->Bitmask->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("Bitmask must be less than " + QString::number(std::numeric_limits<quint64>::max()));
        return false;
    }

    // Если размеры равны,  можно использовать лексикографическое сравнение
    if(currentBitmask.size() == maxBitmask.size() && currentBitmask > maxBitmask)
    {
        ui->Bitmask->setStyleSheet(StyleSheets::LE_ErrorStyle());
        ui->ErrorDisplay->setText("Bitmask must be less than " + QString::number(std::numeric_limits<quint64>::max()));
        return false;
    }

    return true;
}

void MainWindow::updateConfig()
{
    config->fileMask = ui->FileMask->text();
    config->outputDirectory = ui->OutputDirectory->text();
    config->bitmask = ui->Bitmask->text().toULongLong();

    if(config->useTimer)
        config->timerInterval = ui->TimerInterval->text().toUInt();

}

void MainWindow::on_FileMaskType_currentIndexChanged(int index)
{
    // Меняем значение в config
    config->fileMaskType = static_cast<FileMaskTypes>(index);
}


void MainWindow::on_BehaviorIfExist_currentIndexChanged(int index)
{
    // Меняем значение в config
    config->outputExistBehavior = static_cast<OutputExist>(index);
}

void MainWindow::on_OperationType_currentIndexChanged(int index)
{
    // Меняем значение в config
    config->operationType = static_cast<OperationTypes>(index);
}

void MainWindow::on_RemoveInputFiles_clicked()
{
    // Меняем значение в config
    config->removeFiles = true;

    // Обновляем стили
    ui->RemoveInputFiles->setStyleSheet(StyleSheets::B_SelectedStyle());
    ui->DontRemoveInputsFiles->setStyleSheet(StyleSheets::B_DefaultStyle());
}


void MainWindow::on_DontRemoveInputsFiles_clicked()
{
    // Меняем значение в config
    config->removeFiles = false;

    // Обновляем стили
    ui->RemoveInputFiles->setStyleSheet(StyleSheets::B_DefaultStyle());
    ui->DontRemoveInputsFiles->setStyleSheet(StyleSheets::B_SelectedStyle());
}


void MainWindow::on_UseTimer_stateChanged(int arg1)
{
    if(static_cast<Qt::CheckState>(arg1) == Qt::Checked)
    {
        ui->TimerInterval->setEnabled(true);
        config->useTimer = true;
    }

    else if(static_cast<Qt::CheckState>(arg1) == Qt::Unchecked)
    {
        ui->TimerInterval->setEnabled(false);
        config->useTimer = false;
    }
}

void MainWindow::on_SelectDirectory_clicked()
{
    ui->OutputDirectory->setText(QFileDialog::getExistingDirectory());
}


void MainWindow::on_Start_clicked()
{
    resetInputs();

    if(!validateInputs())
        return;

    updateConfig();

    if(config->useTimer)
    {
        timer->setInterval(config->timerInterval);
        timer->start();
    }

    executeOperation();
    workingWindow->exec();
}


QString StyleSheets::LE_DefaulStyle()
{
    return "border: 1px solid black; border-radius: 4px; font: 10pt \"Arial\";";
}

QString StyleSheets::LE_ErrorStyle()
{
    return "border: 1px solid red; border-radius: 4px; font: 10pt \"Arial\";";
}

QString StyleSheets::B_DefaultStyle()
{
    return "border: none; border-radius: 4px; background-color: rgb(205, 205, 205); font: 11pt \"Arial\";";
}

QString StyleSheets::B_SelectedStyle()
{
    return "border: 2px solid black; border-radius: 4px; background-color: rgb(205, 205, 205); font: 11pt \"Arial\";";
}


