#include "workingwindow.h"
#include "ui_workingwindow.h"
#include "mainwindow.h"
#include "filegenerator.h"
#include <QDir>
#include <QRegularExpression>

WorkingWindow::WorkingWindow(MainWindow* _mw, Config* _config, Modes _mode)
    : QDialog(nullptr), ui(new Ui::WorkingWindow), config(_config), mode(_mode)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    init(_mw);
}

WorkingWindow::~WorkingWindow()
{
    delete ui;
}
void WorkingWindow::init(MainWindow* _mv)
{
    setWindowTitle("WorkingWindow");

    // Создаем папку для сгенирированных input файлов
    QDir dir;
    dir.mkdir("generated_inputs");

    // Настраиваем таймер
    timer->setInterval(500);
    connect(timer, &QTimer::timeout, this, &WorkingWindow::updateUI);

    //Выполняем остальные коннекты
    connect(_mv, &MainWindow::executionRequest, this, &WorkingWindow::execute);
    connect(this, &WorkingWindow::start, _mv, &MainWindow::start);
    connect(this, &WorkingWindow::pause, _mv, &MainWindow::pause);
}

void WorkingWindow::executeOperation()
{
    QFile* file = FileGenerator::generate(config);
    QString removingStatus;
    // Проверка закрыт ли файл
    if(file->isOpen())
    {
        removingStatus = tryRemoveAndGetStatus(file);

        printMessage("Operation Failed: Input file was no closed.\n" + removingStatus);
        delete file;
        return;
    }

    // Проверка на соответствие маске
    if(!validateFileName(file->fileName()))
    {
        removingStatus = tryRemoveAndGetStatus(file);

        printMessage("Operation Failed: Input file name does not match the mask\n" + removingStatus);
        delete file;
        return;
    }

    // Файл был закрыт и его имя прошло валидацию по текущей маске

    file->open(QFile::ReadWrite);

    QString operation;
    switch(config->operationType)
    {
    case OperationTypes::XOR:
    {
        applyMask(file, [](char _first, char _second){return _first ^ _second;});
        operation = "Operation XOR was successfully complited\n";
        break;
    }
    case OperationTypes::AND:
    {
        applyMask(file, [](char _first, char _second){return _first & _second;});
        operation = "Operation AND was successfully complited\n";
        break;
    }
    case OperationTypes::OR:
    {
        applyMask(file, [](char _first, char _second){return _first | _second;});
        operation = "Operation OR was successfully complited\n";
        break;
    }
    default: // OperationTypes::NOT
    {
        applyMask(file, [](char _first, char _second){return ~_first; }); // _second не используется т.к побитовое НЕ - унарный оператор
        operation = "Operation NOT was successfully complited\n";
    }
    }

    // К этому моменту output файл уже сохранен

    removingStatus = tryRemoveAndGetStatus(file);

    printMessage(operation + removingStatus);
    delete file;
}


void WorkingWindow::updateUI()
{
    ui->StartPause->setEnabled(true);

    if(status == Status::WORKING)
    {
        ui->StartPause->setText("Pause");

        ui->Status->setStyleSheet("color: green; font: 700 16pt \"Arial\"");

        //Working... индексы точек/пробелов 7 8 9

        QString status = ui->Status->text();

        if(status[7].isSpace())
        {
            status[7] = '.';
            ui->Status->setText(status);
            return;
        }

        if(status[8].isSpace())
        {
            status[8] = '.';
            ui->Status->setText(status);
            return;
        }

        if(status[9].isSpace())
        {
            status[9] = '.';
            ui->Status->setText(status);
            return;
        }

        // Попадаем сюда когда по индексами 7 8 9 находятся точки

        // Присваиваем всем 3-м элементам пробелы
        status[7] = status[8] = status[9] = ' ';
        ui->Status->setText(status);
        return;
    }
    else if(status == Status::PAUSED)
    {
        ui->StartPause->setText("Start");
        ui->Status->setStyleSheet("color: red; font: 700 16pt \"Arial\"");
        ui->Status->setText("Paused");
    }
    else
    {
        ui->StartPause->setEnabled(false);
        ui->StartPause->setText("Operation Complited");
        ui->Status->setStyleSheet("color: green; font: 700 16pt \"Arial\"");
        ui->Status->setText("Complited");
    }
}

void WorkingWindow::printMessage(const QString& _message)
{
    QString finalMessage = "Message #" + QString::number(messageCount++) + "\n" + _message;
    ui->OutputWindow->setText(ui->OutputWindow->toPlainText() + "\n\n" + finalMessage);
}

QString WorkingWindow::tryRemoveAndGetStatus(QFile *_file)
{
    if(config->removeFiles)
    {
        _file->remove();
       return "Input file was removed";
    }

    return "Input file was not removed";
}

bool WorkingWindow::validateFileName(const QString &_filename)
{
    if(config->fileMaskType == FileMaskTypes::REGULAR_EXPRESSION)
    {
        QRegularExpression regex(config->fileMask);

        // Если имя файла не соответствует регулярному выражению
        if(!regex.match(_filename).hasMatch())
            return false;
    }
    else if(config->fileMaskType == FileMaskTypes::FILE_EXTENSION)
    {
        // Если последние n - символов имени файлы, не совпадают с маской(n - размер маски)
        if(_filename.sliced(_filename.size() - config->fileMask.size(), config->fileMask.size()) != config->fileMask)
            return false;
    }
    else
    {
        if(_filename != config->fileMask)
            return false;
    }

    return true; // Имя файла прошло валидацию
}

QByteArray WorkingWindow::getByteArray()
{
    QByteArray maskBytes;
    QDataStream stream(&maskBytes, QIODevice::WriteOnly);

    stream << config->bitmask;

    return maskBytes;
}

void WorkingWindow::applyMask(QFile *_file, const std::function<char (char, char)> &_operation)
{
    QByteArray mask = getByteArray();
    QByteArray fileData = _file->readAll();

    //Побайтово применяем маску к данным файла
    for(uint i = 0; i < fileData.size(); ++i)
    {
        fileData[i] = _operation(fileData[i], mask[i % mask.size()]);
    }

    // Сохраняем output файл
    saveOutputFile(getNativeFileName(_file), fileData);
}

void WorkingWindow::saveOutputFile(const QString &_outputFileName, const QByteArray &_newFileData)
{
    QFile file(config->outputDirectory + '/' + _outputFileName);


    if(config->outputExistBehavior == OutputExist::REWRITE)
    {
        file.open(QFile::WriteOnly); // WriteOnly использует Truncate
    }
    else //OutputExist::MODIFY_ADD_COUNTER
    {
        int counter = 1;

        // Добавляем счетчик имени файла
        while(file.exists())
        {
            file.setFileName(config->outputDirectory + '/' + "(" + QString::number(counter++) + ")" + _outputFileName);
        }

        file.open(QFile::WriteOnly);
    }

    QDataStream dstream(&file);

    dstream << _newFileData; //  Записываем новые данные в output file

    file.close();
}

QString WorkingWindow::getNativeFileName(QFile *file)
{
    QString fullName = file->fileName();
    QString nativeName;

    //Копируем все символы с конца и до первого '/'
    for(int i = fullName.size() - 1; i >= 0; --i)
    {
        if(fullName[i] == '/')
            break;

        nativeName.push_front(fullName[i]);
    }

    return nativeName;
}

void WorkingWindow::execute()
{
    if(mode == Modes::SIMULATION)
    {
        // Если операция выполняется по таймеру
        if(config->useTimer)
        {
            status = Status::WORKING;
            ui->Status->setText("Working   ");

            if(!timer->isActive())
                timer->start();

            executeOperation();
            return;
        }


        // Если операция выполняется один раз
        executeOperation();
        status = Status::COMPLITED;
        updateUI();
    }
    else
    {
        // Здесь должна быть логика работы не в режиме симуляции
    }
}

void WorkingWindow::on_StartPause_clicked()
{
    if(status == Status::WORKING)
    {
        status = Status::PAUSED;
        timer->stop();
        emit pause();

        updateUI();
        return;
    }

    if(status == Status::PAUSED)
    {
        status = Status::WORKING;
        ui->Status->setText("Working   ");
        timer->start();
        emit start();
    }
}

