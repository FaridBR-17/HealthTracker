/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *vboxLayout;
    QLabel *welcomeLabel;
    QComboBox *userSelector;
    QListWidget *listWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtWeight;
    QLabel *label1;
    QLineEdit *txtSys;
    QLabel *label2;
    QLineEdit *txtDia;
    QLabel *label3;
    QLineEdit *txtGlucose;
    QHBoxLayout *hboxLayout;
    QPushButton *btnAdd;
    QPushButton *btnAnalysis;
    QPushButton *btnExport;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        vboxLayout = new QVBoxLayout(centralwidget);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));

        vboxLayout->addWidget(welcomeLabel);

        userSelector = new QComboBox(centralwidget);
        userSelector->setObjectName(QString::fromUtf8("userSelector"));

        vboxLayout->addWidget(userSelector);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        vboxLayout->addWidget(listWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtWeight = new QLineEdit(centralwidget);
        txtWeight->setObjectName(QString::fromUtf8("txtWeight"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtWeight);

        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label1);

        txtSys = new QLineEdit(centralwidget);
        txtSys->setObjectName(QString::fromUtf8("txtSys"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtSys);

        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label2);

        txtDia = new QLineEdit(centralwidget);
        txtDia->setObjectName(QString::fromUtf8("txtDia"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtDia);

        label3 = new QLabel(centralwidget);
        label3->setObjectName(QString::fromUtf8("label3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label3);

        txtGlucose = new QLineEdit(centralwidget);
        txtGlucose->setObjectName(QString::fromUtf8("txtGlucose"));

        formLayout->setWidget(3, QFormLayout::FieldRole, txtGlucose);


        vboxLayout->addLayout(formLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        hboxLayout->addWidget(btnAdd);

        btnAnalysis = new QPushButton(centralwidget);
        btnAnalysis->setObjectName(QString::fromUtf8("btnAnalysis"));

        hboxLayout->addWidget(btnAnalysis);

        btnExport = new QPushButton(centralwidget);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));

        hboxLayout->addWidget(btnExport);


        vboxLayout->addLayout(hboxLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenido", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Peso", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Sist\303\263lica", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Diast\303\263lica", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Glucosa", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnAnalysis->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        btnExport->setText(QCoreApplication::translate("MainWindow", "Exportar CSV", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
