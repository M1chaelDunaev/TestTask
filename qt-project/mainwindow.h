#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "config.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


namespace StyleSheets
{
QString LE_DefaulStyle();

QString LE_ErrorStyle();

QString B_DefaultStyle();

QString B_SelectedStyle();
}

class WorkingWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow* ui;
    Config* config;
    QTimer* timer;

    WorkingWindow* workingWindow;

    void init();

    void resetInputs();

    bool validateInputs();
    void updateConfig();

    void executeOperation() {emit executionRequest();}

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void start() { timer->start(); }
    void pause() { timer->stop(); }

signals:

    void executionRequest(); // Запрос на выполнение операции

private slots:

    void on_FileMaskType_currentIndexChanged(int index);
    void on_BehaviorIfExist_currentIndexChanged(int index);
    void on_RemoveInputFiles_clicked();
    void on_DontRemoveInputsFiles_clicked();
    void on_UseTimer_stateChanged(int arg1);
    void on_SelectDirectory_clicked();
    void on_Start_clicked();
    void on_OperationType_currentIndexChanged(int index);
};
#endif // MAINWINDOW_H
