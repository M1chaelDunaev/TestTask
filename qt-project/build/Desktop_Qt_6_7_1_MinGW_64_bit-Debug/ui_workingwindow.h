/********************************************************************************
** Form generated from reading UI file 'workingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKINGWINDOW_H
#define UI_WORKINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WorkingWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *Status;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QTextEdit *OutputWindow;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *StartPause;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *WorkingWindow)
    {
        if (WorkingWindow->objectName().isEmpty())
            WorkingWindow->setObjectName("WorkingWindow");
        WorkingWindow->resize(537, 602);
        WorkingWindow->setMinimumSize(QSize(537, 602));
        WorkingWindow->setMaximumSize(QSize(537, 602));
        verticalLayout_3 = new QVBoxLayout(WorkingWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(WorkingWindow);
        label->setObjectName("label");
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));
        label->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Arial\";"));

        horizontalLayout->addWidget(label);

        Status = new QLabel(WorkingWindow);
        Status->setObjectName("Status");
        Status->setMinimumSize(QSize(0, 31));
        Status->setMaximumSize(QSize(16777215, 31));
        Status->setStyleSheet(QString::fromUtf8("font: 700 16pt \"Arial\";"));

        horizontalLayout->addWidget(Status);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_3 = new QLabel(WorkingWindow);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));

        verticalLayout->addWidget(label_3);

        OutputWindow = new QTextEdit(WorkingWindow);
        OutputWindow->setObjectName("OutputWindow");
        OutputWindow->setMinimumSize(QSize(515, 440));
        OutputWindow->setMaximumSize(QSize(515, 440));
        OutputWindow->setReadOnly(true);

        verticalLayout->addWidget(OutputWindow);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        StartPause = new QPushButton(WorkingWindow);
        StartPause->setObjectName("StartPause");
        StartPause->setMinimumSize(QSize(240, 40));
        StartPause->setMaximumSize(QSize(240, 40));
        StartPause->setCursor(QCursor(Qt::PointingHandCursor));
        StartPause->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: none;\n"
"border-radius: 4px;\n"
"background-color: rgb(205, 205, 205);\n"
"font: 11pt \"Arial\";}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(220, 220, 220);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(StartPause);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(WorkingWindow);

        QMetaObject::connectSlotsByName(WorkingWindow);
    } // setupUi

    void retranslateUi(QDialog *WorkingWindow)
    {
        WorkingWindow->setWindowTitle(QCoreApplication::translate("WorkingWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WorkingWindow", "Status:", nullptr));
        Status->setText(QString());
        label_3->setText(QCoreApplication::translate("WorkingWindow", "Output messages:", nullptr));
        OutputWindow->setHtml(QCoreApplication::translate("WorkingWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        StartPause->setText(QCoreApplication::translate("WorkingWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkingWindow: public Ui_WorkingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKINGWINDOW_H
