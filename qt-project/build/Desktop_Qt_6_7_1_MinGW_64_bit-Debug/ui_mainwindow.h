/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *ConfigurationLayout;
    QLabel *label;
    QWidget *Configuration;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *MaskLayout;
    QVBoxLayout *MaskTypeLayout;
    QLabel *label_2;
    QComboBox *FileMaskType;
    QVBoxLayout *EnterMaskLayout;
    QLabel *label_3;
    QLineEdit *FileMask;
    QHBoxLayout *RemoveInputFilesLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *RemoveInputFiles;
    QPushButton *DontRemoveInputsFiles;
    QVBoxLayout *BehaviorIfExistLayout;
    QLabel *label_5;
    QComboBox *BehaviorIfExist;
    QHBoxLayout *TimerLayout;
    QCheckBox *UseTimer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *TimerInterval;
    QLabel *label_7;
    QVBoxLayout *OperationLayout;
    QLabel *label_10;
    QComboBox *OperationType;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *OutputDirectoryLayout;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *OutputDirectory;
    QPushButton *SelectDirectory;
    QVBoxLayout *BitmaskLayout;
    QLabel *EnterBitmask;
    QLineEdit *Bitmask;
    QHBoxLayout *StartStopLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Start;
    QSpacerItem *horizontalSpacer_2;
    QLabel *ErrorDisplay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(811, 795);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName("verticalLayout_3");
        ConfigurationLayout = new QVBoxLayout();
        ConfigurationLayout->setSpacing(2);
        ConfigurationLayout->setObjectName("ConfigurationLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(100, 22));
        label->setMaximumSize(QSize(16777215, 22));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";\n"
"font:  700 12pt  \"Arial\";"));
        label->setAlignment(Qt::AlignCenter);

        ConfigurationLayout->addWidget(label);

        Configuration = new QWidget(centralwidget);
        Configuration->setObjectName("Configuration");
        Configuration->setMinimumSize(QSize(0, 0));
        Configuration->setMaximumSize(QSize(16777215, 21323));
        Configuration->setStyleSheet(QString::fromUtf8("QWidget#Configuration\n"
"{border: 2px solid black;\n"
"border-radius: 8px;}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(Configuration);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(16, -1, 16, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName("verticalLayout");
        MaskLayout = new QVBoxLayout();
        MaskLayout->setObjectName("MaskLayout");
        MaskTypeLayout = new QVBoxLayout();
        MaskTypeLayout->setSpacing(4);
        MaskTypeLayout->setObjectName("MaskTypeLayout");
        label_2 = new QLabel(Configuration);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        MaskTypeLayout->addWidget(label_2);

        FileMaskType = new QComboBox(Configuration);
        FileMaskType->addItem(QString());
        FileMaskType->addItem(QString());
        FileMaskType->addItem(QString());
        FileMaskType->setObjectName("FileMaskType");
        FileMaskType->setMinimumSize(QSize(0, 30));
        FileMaskType->setMaximumSize(QSize(16777215, 30));
        FileMaskType->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"background-color: rgb(230, 230, 230);\n"
"font: 10pt \"Arial\";"));

        MaskTypeLayout->addWidget(FileMaskType);


        MaskLayout->addLayout(MaskTypeLayout);

        EnterMaskLayout = new QVBoxLayout();
        EnterMaskLayout->setSpacing(4);
        EnterMaskLayout->setObjectName("EnterMaskLayout");
        label_3 = new QLabel(Configuration);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        EnterMaskLayout->addWidget(label_3);

        FileMask = new QLineEdit(Configuration);
        FileMask->setObjectName("FileMask");
        FileMask->setMinimumSize(QSize(0, 30));
        FileMask->setMaximumSize(QSize(16777215, 30));
        FileMask->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"font: 10pt \"Arial\";"));

        EnterMaskLayout->addWidget(FileMask);


        MaskLayout->addLayout(EnterMaskLayout);


        verticalLayout->addLayout(MaskLayout);

        RemoveInputFilesLayout = new QHBoxLayout();
        RemoveInputFilesLayout->setSpacing(30);
        RemoveInputFilesLayout->setObjectName("RemoveInputFilesLayout");
        label_4 = new QLabel(Configuration);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(130, 20));
        label_4->setMaximumSize(QSize(130, 20));
        label_4->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        RemoveInputFilesLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        RemoveInputFiles = new QPushButton(Configuration);
        RemoveInputFiles->setObjectName("RemoveInputFiles");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RemoveInputFiles->sizePolicy().hasHeightForWidth());
        RemoveInputFiles->setSizePolicy(sizePolicy);
        RemoveInputFiles->setMinimumSize(QSize(0, 26));
        RemoveInputFiles->setCursor(QCursor(Qt::PointingHandCursor));
        RemoveInputFiles->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 4px;\n"
"background-color: rgb(205, 205, 205);\n"
"font: 11pt \"Arial\";"));

        horizontalLayout->addWidget(RemoveInputFiles);

        DontRemoveInputsFiles = new QPushButton(Configuration);
        DontRemoveInputsFiles->setObjectName("DontRemoveInputsFiles");
        sizePolicy.setHeightForWidth(DontRemoveInputsFiles->sizePolicy().hasHeightForWidth());
        DontRemoveInputsFiles->setSizePolicy(sizePolicy);
        DontRemoveInputsFiles->setMinimumSize(QSize(0, 26));
        DontRemoveInputsFiles->setCursor(QCursor(Qt::PointingHandCursor));
        DontRemoveInputsFiles->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 4px;\n"
"background-color: rgb(205, 205, 205);\n"
"font: 11pt \"Arial\";"));

        horizontalLayout->addWidget(DontRemoveInputsFiles);


        RemoveInputFilesLayout->addLayout(horizontalLayout);


        verticalLayout->addLayout(RemoveInputFilesLayout);

        BehaviorIfExistLayout = new QVBoxLayout();
        BehaviorIfExistLayout->setSpacing(4);
        BehaviorIfExistLayout->setObjectName("BehaviorIfExistLayout");
        BehaviorIfExistLayout->setSizeConstraint(QLayout::SetNoConstraint);
        label_5 = new QLabel(Configuration);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 20));
        label_5->setMaximumSize(QSize(16777215, 20));
        label_5->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        BehaviorIfExistLayout->addWidget(label_5);

        BehaviorIfExist = new QComboBox(Configuration);
        BehaviorIfExist->addItem(QString());
        BehaviorIfExist->addItem(QString());
        BehaviorIfExist->setObjectName("BehaviorIfExist");
        BehaviorIfExist->setMinimumSize(QSize(0, 30));
        BehaviorIfExist->setMaximumSize(QSize(16777215, 30));
        BehaviorIfExist->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"background-color: rgb(230, 230, 230);\n"
"font: 10pt \"Arial\";"));

        BehaviorIfExistLayout->addWidget(BehaviorIfExist);


        verticalLayout->addLayout(BehaviorIfExistLayout);

        TimerLayout = new QHBoxLayout();
        TimerLayout->setSpacing(30);
        TimerLayout->setObjectName("TimerLayout");
        UseTimer = new QCheckBox(Configuration);
        UseTimer->setObjectName("UseTimer");
        UseTimer->setMinimumSize(QSize(85, 30));
        UseTimer->setMaximumSize(QSize(85, 30));
        UseTimer->setStyleSheet(QString::fromUtf8("font: 11pt \"Arial\";"));

        TimerLayout->addWidget(UseTimer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_6 = new QLabel(Configuration);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(51, 30));
        label_6->setMaximumSize(QSize(51, 30));
        label_6->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_2->addWidget(label_6);

        TimerInterval = new QLineEdit(Configuration);
        TimerInterval->setObjectName("TimerInterval");
        TimerInterval->setEnabled(false);
        TimerInterval->setMinimumSize(QSize(0, 30));
        TimerInterval->setMaximumSize(QSize(16777215, 30));
        TimerInterval->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"font: 10pt \"Arial\";"));
        TimerInterval->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TimerInterval->setClearButtonEnabled(false);

        horizontalLayout_2->addWidget(TimerInterval);

        label_7 = new QLabel(Configuration);
        label_7->setObjectName("label_7");
        label_7->setMinimumSize(QSize(85, 30));
        label_7->setMaximumSize(QSize(85, 30));
        label_7->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        horizontalLayout_2->addWidget(label_7);


        TimerLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(TimerLayout);

        OperationLayout = new QVBoxLayout();
        OperationLayout->setSpacing(4);
        OperationLayout->setObjectName("OperationLayout");
        label_10 = new QLabel(Configuration);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(16777215, 20));
        label_10->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        OperationLayout->addWidget(label_10);

        OperationType = new QComboBox(Configuration);
        OperationType->addItem(QString());
        OperationType->addItem(QString());
        OperationType->addItem(QString());
        OperationType->addItem(QString());
        OperationType->setObjectName("OperationType");
        OperationType->setMinimumSize(QSize(0, 30));
        OperationType->setMaximumSize(QSize(16777215, 30));
        OperationType->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"background-color: rgb(230, 230, 230);\n"
"font: 10pt \"Arial\";"));

        OperationLayout->addWidget(OperationType);


        verticalLayout->addLayout(OperationLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        ConfigurationLayout->addWidget(Configuration);


        verticalLayout_3->addLayout(ConfigurationLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName("verticalLayout_2");
        OutputDirectoryLayout = new QVBoxLayout();
        OutputDirectoryLayout->setSpacing(4);
        OutputDirectoryLayout->setObjectName("OutputDirectoryLayout");
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(0, 20));
        label_8->setMaximumSize(QSize(16777215, 20));
        label_8->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        OutputDirectoryLayout->addWidget(label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        OutputDirectory = new QLineEdit(centralwidget);
        OutputDirectory->setObjectName("OutputDirectory");
        OutputDirectory->setEnabled(true);
        OutputDirectory->setMinimumSize(QSize(0, 30));
        OutputDirectory->setMaximumSize(QSize(16777215, 30));
        OutputDirectory->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"font: 10pt \"Arial\";"));
        OutputDirectory->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        OutputDirectory->setReadOnly(true);

        horizontalLayout_4->addWidget(OutputDirectory);

        SelectDirectory = new QPushButton(centralwidget);
        SelectDirectory->setObjectName("SelectDirectory");
        SelectDirectory->setMinimumSize(QSize(120, 32));
        SelectDirectory->setMaximumSize(QSize(120, 32));
        SelectDirectory->setCursor(QCursor(Qt::PointingHandCursor));
        SelectDirectory->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: none;\n"
"border-radius: 4px;\n"
"background-color: rgb(205, 205, 205);\n"
"font: 11pt \"Arial\";}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(220, 220, 220);\n"
"}\n"
""));

        horizontalLayout_4->addWidget(SelectDirectory);


        OutputDirectoryLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(OutputDirectoryLayout);

        BitmaskLayout = new QVBoxLayout();
        BitmaskLayout->setSpacing(4);
        BitmaskLayout->setObjectName("BitmaskLayout");
        EnterBitmask = new QLabel(centralwidget);
        EnterBitmask->setObjectName("EnterBitmask");
        EnterBitmask->setMinimumSize(QSize(0, 20));
        EnterBitmask->setMaximumSize(QSize(16777215, 20));
        EnterBitmask->setStyleSheet(QString::fromUtf8("border: none;\n"
"font: 11pt \"Arial\";"));

        BitmaskLayout->addWidget(EnterBitmask);

        Bitmask = new QLineEdit(centralwidget);
        Bitmask->setObjectName("Bitmask");
        Bitmask->setEnabled(true);
        Bitmask->setMinimumSize(QSize(0, 30));
        Bitmask->setMaximumSize(QSize(16777215, 30));
        Bitmask->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 4px;\n"
"font: 10pt \"Arial\";"));
        Bitmask->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Bitmask->setReadOnly(false);

        BitmaskLayout->addWidget(Bitmask);


        verticalLayout_2->addLayout(BitmaskLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        StartStopLayout = new QHBoxLayout();
        StartStopLayout->setObjectName("StartStopLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        StartStopLayout->addItem(horizontalSpacer);

        Start = new QPushButton(centralwidget);
        Start->setObjectName("Start");
        Start->setMinimumSize(QSize(240, 40));
        Start->setMaximumSize(QSize(240, 40));
        Start->setCursor(QCursor(Qt::PointingHandCursor));
        Start->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: none;\n"
"border-radius: 4px;\n"
"background-color: rgb(205, 205, 205);\n"
"font: 11pt \"Arial\";}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(220, 220, 220);\n"
"}\n"
""));

        StartStopLayout->addWidget(Start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        StartStopLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(StartStopLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        ErrorDisplay = new QLabel(centralwidget);
        ErrorDisplay->setObjectName("ErrorDisplay");
        ErrorDisplay->setMinimumSize(QSize(0, 40));
        ErrorDisplay->setMaximumSize(QSize(16777215, 40));
        ErrorDisplay->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Arial\";\n"
"color: rgb(214, 0, 0)"));
        ErrorDisplay->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(ErrorDisplay);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select file mask type:", nullptr));
        FileMaskType->setItemText(0, QCoreApplication::translate("MainWindow", "Regular expression", nullptr));
        FileMaskType->setItemText(1, QCoreApplication::translate("MainWindow", "File extension", nullptr));
        FileMaskType->setItemText(2, QCoreApplication::translate("MainWindow", "Exact filename", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Enter file mask:", nullptr));
        FileMask->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Remove input files?", nullptr));
        RemoveInputFiles->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        DontRemoveInputsFiles->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Select behavior if output file already exist:", nullptr));
        BehaviorIfExist->setItemText(0, QCoreApplication::translate("MainWindow", "Rewrite", nullptr));
        BehaviorIfExist->setItemText(1, QCoreApplication::translate("MainWindow", "Add counter", nullptr));

        UseTimer->setText(QCoreApplication::translate("MainWindow", "Use timer", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Interval:", nullptr));
        TimerInterval->setInputMask(QString());
        TimerInterval->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "milliseconds", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Select operation type:", nullptr));
        OperationType->setItemText(0, QCoreApplication::translate("MainWindow", "XOR", nullptr));
        OperationType->setItemText(1, QCoreApplication::translate("MainWindow", "AND", nullptr));
        OperationType->setItemText(2, QCoreApplication::translate("MainWindow", "OR", nullptr));
        OperationType->setItemText(3, QCoreApplication::translate("MainWindow", "NOT", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Select output directory:", nullptr));
        OutputDirectory->setInputMask(QString());
        OutputDirectory->setText(QString());
        SelectDirectory->setText(QCoreApplication::translate("MainWindow", "Select Directory", nullptr));
        EnterBitmask->setText(QCoreApplication::translate("MainWindow", "Enter bitmask(unsigned integer less than", nullptr));
        Bitmask->setInputMask(QString());
        Bitmask->setText(QString());
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        ErrorDisplay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
