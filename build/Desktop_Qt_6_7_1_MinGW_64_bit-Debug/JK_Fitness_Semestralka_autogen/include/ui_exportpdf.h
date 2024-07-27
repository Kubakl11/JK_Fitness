/********************************************************************************
** Form generated from reading UI file 'exportpdf.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTPDF_H
#define UI_EXPORTPDF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportPDF
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QWidget *layoutWidget;
    QFormLayout *formLayout_2;
    QLabel *nameLBL;
    QLineEdit *Line_Name;
    QLabel *ageLBL;
    QLineEdit *Line_Gender;
    QLabel *heightLBL;
    QLineEdit *Line_Age;
    QLabel *label_3;
    QLineEdit *Line_Height;
    QLabel *label_4;
    QLineEdit *Line_Bodyfat;
    QLineEdit *Line_Somatotyp;
    QLabel *label_6;
    QLineEdit *Line_Goal;
    QLabel *label_7;
    QLineEdit *Line_Activity;
    QLabel *label_5;
    QLabel *label_11;
    QLineEdit *Line_Training;
    QLabel *label_12;
    QLineEdit *Line_Weight;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *nameLBL_2;
    QLineEdit *Line_LBM;
    QLabel *ageLBL_2;
    QLineEdit *Line_BM;
    QLabel *heightLBL_2;
    QLineEdit *Line_Cal;
    QLabel *weightLBL_2;
    QLineEdit *Line_Protein;
    QLabel *label_10;
    QLineEdit *Line_Carb;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *Line_Fats;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *exportPDF)
    {
        if (exportPDF->objectName().isEmpty())
            exportPDF->setObjectName("exportPDF");
        exportPDF->resize(805, 923);
        centralwidget = new QWidget(exportPDF);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 30, 171, 20));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 60, 261, 325));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLBL = new QLabel(layoutWidget);
        nameLBL->setObjectName("nameLBL");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nameLBL);

        Line_Name = new QLineEdit(layoutWidget);
        Line_Name->setObjectName("Line_Name");
        Line_Name->setMaximumSize(QSize(16777, 16777215));
        Line_Name->setMaxLength(2500);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Line_Name);

        ageLBL = new QLabel(layoutWidget);
        ageLBL->setObjectName("ageLBL");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, ageLBL);

        Line_Gender = new QLineEdit(layoutWidget);
        Line_Gender->setObjectName("Line_Gender");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Line_Gender);

        heightLBL = new QLabel(layoutWidget);
        heightLBL->setObjectName("heightLBL");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, heightLBL);

        Line_Age = new QLineEdit(layoutWidget);
        Line_Age->setObjectName("Line_Age");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, Line_Age);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_3);

        Line_Height = new QLineEdit(layoutWidget);
        Line_Height->setObjectName("Line_Height");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, Line_Height);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_4);

        Line_Bodyfat = new QLineEdit(layoutWidget);
        Line_Bodyfat->setObjectName("Line_Bodyfat");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, Line_Bodyfat);

        Line_Somatotyp = new QLineEdit(layoutWidget);
        Line_Somatotyp->setObjectName("Line_Somatotyp");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, Line_Somatotyp);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_6);

        Line_Goal = new QLineEdit(layoutWidget);
        Line_Goal->setObjectName("Line_Goal");

        formLayout_2->setWidget(7, QFormLayout::FieldRole, Line_Goal);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_7);

        Line_Activity = new QLineEdit(layoutWidget);
        Line_Activity->setObjectName("Line_Activity");

        formLayout_2->setWidget(8, QFormLayout::FieldRole, Line_Activity);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_5);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_11);

        Line_Training = new QLineEdit(layoutWidget);
        Line_Training->setObjectName("Line_Training");

        formLayout_2->setWidget(9, QFormLayout::FieldRole, Line_Training);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_12);

        Line_Weight = new QLineEdit(layoutWidget);
        Line_Weight->setObjectName("Line_Weight");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, Line_Weight);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(220, 470, 236, 220));
        formLayout_3 = new QFormLayout(layoutWidget_2);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        nameLBL_2 = new QLabel(layoutWidget_2);
        nameLBL_2->setObjectName("nameLBL_2");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, nameLBL_2);

        Line_LBM = new QLineEdit(layoutWidget_2);
        Line_LBM->setObjectName("Line_LBM");
        Line_LBM->setMaximumSize(QSize(16777, 16777215));
        Line_LBM->setMaxLength(2500);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, Line_LBM);

        ageLBL_2 = new QLabel(layoutWidget_2);
        ageLBL_2->setObjectName("ageLBL_2");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, ageLBL_2);

        Line_BM = new QLineEdit(layoutWidget_2);
        Line_BM->setObjectName("Line_BM");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Line_BM);

        heightLBL_2 = new QLabel(layoutWidget_2);
        heightLBL_2->setObjectName("heightLBL_2");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, heightLBL_2);

        Line_Cal = new QLineEdit(layoutWidget_2);
        Line_Cal->setObjectName("Line_Cal");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, Line_Cal);

        weightLBL_2 = new QLabel(layoutWidget_2);
        weightLBL_2->setObjectName("weightLBL_2");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, weightLBL_2);

        Line_Protein = new QLineEdit(layoutWidget_2);
        Line_Protein->setObjectName("Line_Protein");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, Line_Protein);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_10);

        Line_Carb = new QLineEdit(layoutWidget_2);
        Line_Carb->setObjectName("Line_Carb");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, Line_Carb);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName("label_8");

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName("label_9");

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_9);

        Line_Fats = new QLineEdit(layoutWidget_2);
        Line_Fats->setObjectName("Line_Fats");

        formLayout_3->setWidget(5, QFormLayout::FieldRole, Line_Fats);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 440, 171, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 700, 131, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 700, 93, 41));
        exportPDF->setCentralWidget(centralwidget);
        menubar = new QMenuBar(exportPDF);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 805, 26));
        exportPDF->setMenuBar(menubar);
        statusbar = new QStatusBar(exportPDF);
        statusbar->setObjectName("statusbar");
        exportPDF->setStatusBar(statusbar);

        retranslateUi(exportPDF);

        QMetaObject::connectSlotsByName(exportPDF);
    } // setupUi

    void retranslateUi(QMainWindow *exportPDF)
    {
        exportPDF->setWindowTitle(QCoreApplication::translate("exportPDF", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("exportPDF", "Input data:", nullptr));
        nameLBL->setText(QCoreApplication::translate("exportPDF", "Name", nullptr));
        ageLBL->setText(QCoreApplication::translate("exportPDF", "Gender", nullptr));
        heightLBL->setText(QCoreApplication::translate("exportPDF", "Age", nullptr));
        label_3->setText(QCoreApplication::translate("exportPDF", "Height", nullptr));
        Line_Height->setText(QString());
        label_4->setText(QCoreApplication::translate("exportPDF", "Bodyfat", nullptr));
        label_6->setText(QCoreApplication::translate("exportPDF", "Goal", nullptr));
        label_7->setText(QCoreApplication::translate("exportPDF", "Activity", nullptr));
        label_5->setText(QCoreApplication::translate("exportPDF", "Somatotyp", nullptr));
        label_11->setText(QCoreApplication::translate("exportPDF", "Type of training", nullptr));
        label_12->setText(QCoreApplication::translate("exportPDF", "Weight", nullptr));
        nameLBL_2->setText(QCoreApplication::translate("exportPDF", "Lean body mass:", nullptr));
        ageLBL_2->setText(QCoreApplication::translate("exportPDF", "Basal metabolism:", nullptr));
        heightLBL_2->setText(QCoreApplication::translate("exportPDF", "Total calories intake:", nullptr));
        weightLBL_2->setText(QCoreApplication::translate("exportPDF", "Protein:", nullptr));
        label_10->setText(QCoreApplication::translate("exportPDF", "Carbohydrates:", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("exportPDF", "Fats:", nullptr));
        label->setText(QCoreApplication::translate("exportPDF", "Computed data:", nullptr));
        pushButton->setText(QCoreApplication::translate("exportPDF", "Measured data", nullptr));
        pushButton_2->setText(QCoreApplication::translate("exportPDF", "Full export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exportPDF: public Ui_exportPDF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTPDF_H
