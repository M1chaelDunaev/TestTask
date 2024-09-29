#ifndef WORKINGWINDOW_H
#define WORKINGWINDOW_H

#include <QDialog>
#include<functional>

namespace Ui {
class WorkingWindow;
}

struct Config;
class MainWindow;
class QFile;
class QByteArray;

enum class Modes
{
    SIMULATION,
    REAL_WORK
};

enum class Status
{
    WORKING,
    PAUSED,
    COMPLITED
};

class WorkingWindow : public QDialog
{
    Q_OBJECT
    Ui::WorkingWindow *ui;
    Config* config;
    Modes mode;
    Status status;

    QTimer* timer; // Таймер для появления точек в ui->Status (Working...)

    uint messageCount = 0; // Счетчик для сообщений

    void init(MainWindow* _mv);

    void executeOperation();

    void updateUI();

    void printMessage(const QString& _message);

    QString tryRemoveAndGetStatus(QFile* _file);

    bool validateFileName(const QString& _filename);

    QByteArray getByteArray(); // Конвертирует битовую маску в QByteArray

    void applyMask(QFile* _file, const std::function<char(char, char)>& _operation); // Общая функция, принимающая лямбду для конкретной побитовой операции

    void saveOutputFile(const QString& _outputFileName, const QByteArray& _newFileData);

    QString getNativeFileName(QFile* file);

public:
    explicit WorkingWindow(MainWindow* _mw, Config* _config, Modes _mode = Modes::SIMULATION);
    ~WorkingWindow();

    void execute();

signals:

    void start(); // Сигнал для запуска таймера в MainWindow
    void pause(); // Сигнал для остановки таймера в MainWindow

private slots:
    void on_StartPause_clicked();
};


#endif // WORKINGWINDOW_H
