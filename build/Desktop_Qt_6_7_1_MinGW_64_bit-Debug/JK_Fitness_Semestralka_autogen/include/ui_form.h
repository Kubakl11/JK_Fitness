/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *lbl_userData;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *nameLBL;
    QLineEdit *Line_Name;
    QLabel *ageLBL;
    QLineEdit *Line_Age;
    QLabel *heightLBL;
    QLineEdit *Line_Height;
    QLabel *weightLBL;
    QLineEdit *Line_Weight;
    QLabel *label_4;
    QLineEdit *Line_BF;
    QLabel *label_3;
    QComboBox *CBX_Soma;
    QSpacerItem *verticalSpacer_5;
    QLabel *lbl_gender;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *genderBTN_M;
    QRadioButton *genderBTN_FM;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *lbl_activ;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *activityBTN_No;
    QRadioButton *activityBTN_Light;
    QRadioButton *activityBTN_Middle;
    QRadioButton *activityBTN_Intense;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbl_goal;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *goalBTN_Lose;
    QRadioButton *goalBTN_Gain;
    QRadioButton *goalBTN_Maintain;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QLabel *lbl_training;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *trainingBTN_BW;
    QRadioButton *trainingBTN_STR;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QPushButton *btnSubmit;
    QLabel *lbl_picture;

    void setupUi(QDialog *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 794);
        Form->setMinimumSize(QSize(200, 200));
        Form->setMaximumSize(QSize(4000, 4000));
        verticalLayout_4 = new QVBoxLayout(Form);
        verticalLayout_4->setObjectName("verticalLayout_4");
        lbl_userData = new QLabel(Form);
        lbl_userData->setObjectName("lbl_userData");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font.setPointSize(15);
        font.setBold(true);
        lbl_userData->setFont(font);
        lbl_userData->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbl_userData);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        nameLBL = new QLabel(Form);
        nameLBL->setObjectName("nameLBL");
        QFont font1;
        font1.setPointSize(11);
        nameLBL->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nameLBL);

        Line_Name = new QLineEdit(Form);
        Line_Name->setObjectName("Line_Name");
        Line_Name->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Line_Name->sizePolicy().hasHeightForWidth());
        Line_Name->setSizePolicy(sizePolicy);
        Line_Name->setMaximumSize(QSize(500, 16777215));
        QFont font2;
        font2.setKerning(true);
        Line_Name->setFont(font2);
        Line_Name->setMaxLength(999);
        Line_Name->setCursorPosition(0);
        Line_Name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        Line_Name->setClearButtonEnabled(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Line_Name);

        ageLBL = new QLabel(Form);
        ageLBL->setObjectName("ageLBL");
        ageLBL->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, ageLBL);

        Line_Age = new QLineEdit(Form);
        Line_Age->setObjectName("Line_Age");
        Line_Age->setMaximumSize(QSize(500, 16777215));
        Line_Age->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Line_Age);

        heightLBL = new QLabel(Form);
        heightLBL->setObjectName("heightLBL");
        heightLBL->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, heightLBL);

        Line_Height = new QLineEdit(Form);
        Line_Height->setObjectName("Line_Height");
        Line_Height->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, Line_Height);

        weightLBL = new QLabel(Form);
        weightLBL->setObjectName("weightLBL");
        weightLBL->setFont(font1);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, weightLBL);

        Line_Weight = new QLineEdit(Form);
        Line_Weight->setObjectName("Line_Weight");
        Line_Weight->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, Line_Weight);

        label_4 = new QLabel(Form);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        Line_BF = new QLineEdit(Form);
        Line_BF->setObjectName("Line_BF");
        Line_BF->setMaximumSize(QSize(500, 16777215));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, Line_BF);

        label_3 = new QLabel(Form);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_3);

        CBX_Soma = new QComboBox(Form);
        CBX_Soma->addItem(QString());
        CBX_Soma->addItem(QString());
        CBX_Soma->addItem(QString());
        CBX_Soma->addItem(QString());
        CBX_Soma->addItem(QString());
        CBX_Soma->addItem(QString());
        CBX_Soma->setObjectName("CBX_Soma");
        CBX_Soma->setMaximumSize(QSize(500, 16777215));
        CBX_Soma->setFont(font1);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, CBX_Soma);


        verticalLayout_2->addLayout(formLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_5);

        lbl_gender = new QLabel(Form);
        lbl_gender->setObjectName("lbl_gender");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Malgun Gothic")});
        font3.setPointSize(12);
        font3.setBold(true);
        lbl_gender->setFont(font3);
        lbl_gender->setLayoutDirection(Qt::LeftToRight);
        lbl_gender->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbl_gender);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        genderBTN_M = new QRadioButton(Form);
        genderBTN_M->setObjectName("genderBTN_M");
        genderBTN_M->setFont(font1);

        horizontalLayout->addWidget(genderBTN_M);

        genderBTN_FM = new QRadioButton(Form);
        genderBTN_FM->setObjectName("genderBTN_FM");
        genderBTN_FM->setFont(font1);

        horizontalLayout->addWidget(genderBTN_FM);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_4);

        lbl_activ = new QLabel(Form);
        lbl_activ->setObjectName("lbl_activ");
        lbl_activ->setFont(font3);
        lbl_activ->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbl_activ);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        activityBTN_No = new QRadioButton(Form);
        activityBTN_No->setObjectName("activityBTN_No");
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(false);
        activityBTN_No->setFont(font4);
        activityBTN_No->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(activityBTN_No);

        activityBTN_Light = new QRadioButton(Form);
        activityBTN_Light->setObjectName("activityBTN_Light");
        activityBTN_Light->setFont(font1);

        horizontalLayout_3->addWidget(activityBTN_Light);

        activityBTN_Middle = new QRadioButton(Form);
        activityBTN_Middle->setObjectName("activityBTN_Middle");
        activityBTN_Middle->setFont(font1);

        horizontalLayout_3->addWidget(activityBTN_Middle);

        activityBTN_Intense = new QRadioButton(Form);
        activityBTN_Intense->setObjectName("activityBTN_Intense");
        activityBTN_Intense->setFont(font1);

        horizontalLayout_3->addWidget(activityBTN_Intense);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_3);

        lbl_goal = new QLabel(Form);
        lbl_goal->setObjectName("lbl_goal");
        lbl_goal->setFont(font3);
        lbl_goal->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbl_goal);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        goalBTN_Lose = new QRadioButton(Form);
        goalBTN_Lose->setObjectName("goalBTN_Lose");
        goalBTN_Lose->setFont(font1);

        horizontalLayout_4->addWidget(goalBTN_Lose);

        goalBTN_Gain = new QRadioButton(Form);
        goalBTN_Gain->setObjectName("goalBTN_Gain");
        goalBTN_Gain->setFont(font1);

        horizontalLayout_4->addWidget(goalBTN_Gain);

        goalBTN_Maintain = new QRadioButton(Form);
        goalBTN_Maintain->setObjectName("goalBTN_Maintain");
        goalBTN_Maintain->setFont(font1);

        horizontalLayout_4->addWidget(goalBTN_Maintain);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_2);

        lbl_training = new QLabel(Form);
        lbl_training->setObjectName("lbl_training");
        lbl_training->setFont(font3);
        lbl_training->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lbl_training);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        trainingBTN_BW = new QRadioButton(Form);
        trainingBTN_BW->setObjectName("trainingBTN_BW");
        trainingBTN_BW->setFont(font1);

        horizontalLayout_6->addWidget(trainingBTN_BW);

        trainingBTN_STR = new QRadioButton(Form);
        trainingBTN_STR->setObjectName("trainingBTN_STR");
        trainingBTN_STR->setFont(font1);

        horizontalLayout_6->addWidget(trainingBTN_STR);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_10->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_10);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer);

        btnSubmit = new QPushButton(Form);
        btnSubmit->setObjectName("btnSubmit");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        btnSubmit->setFont(font5);

        verticalLayout_4->addWidget(btnSubmit);

        lbl_picture = new QLabel(Form);
        lbl_picture->setObjectName("lbl_picture");

        verticalLayout_4->addWidget(lbl_picture);

        QWidget::setTabOrder(Line_Name, Line_Age);
        QWidget::setTabOrder(Line_Age, Line_Height);
        QWidget::setTabOrder(Line_Height, Line_Weight);
        QWidget::setTabOrder(Line_Weight, Line_BF);
        QWidget::setTabOrder(Line_BF, CBX_Soma);
        QWidget::setTabOrder(CBX_Soma, genderBTN_M);
        QWidget::setTabOrder(genderBTN_M, genderBTN_FM);
        QWidget::setTabOrder(genderBTN_FM, activityBTN_No);
        QWidget::setTabOrder(activityBTN_No, activityBTN_Light);
        QWidget::setTabOrder(activityBTN_Light, activityBTN_Middle);
        QWidget::setTabOrder(activityBTN_Middle, activityBTN_Intense);
        QWidget::setTabOrder(activityBTN_Intense, goalBTN_Lose);
        QWidget::setTabOrder(goalBTN_Lose, goalBTN_Gain);
        QWidget::setTabOrder(goalBTN_Gain, goalBTN_Maintain);
        QWidget::setTabOrder(goalBTN_Maintain, trainingBTN_BW);
        QWidget::setTabOrder(trainingBTN_BW, trainingBTN_STR);
        QWidget::setTabOrder(trainingBTN_STR, btnSubmit);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QDialog *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Dialog", nullptr));
        lbl_userData->setText(QCoreApplication::translate("Form", "User data", nullptr));
        nameLBL->setText(QCoreApplication::translate("Form", "Name", nullptr));
        ageLBL->setText(QCoreApplication::translate("Form", "Age", nullptr));
        heightLBL->setText(QCoreApplication::translate("Form", "Height (cm)", nullptr));
        weightLBL->setText(QCoreApplication::translate("Form", "Weight (kg)", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Body fat (%)", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Somatotyp", nullptr));
        CBX_Soma->setItemText(0, QCoreApplication::translate("Form", "Choose somatotyp", nullptr));
        CBX_Soma->setItemText(1, QCoreApplication::translate("Form", "Ektomorph", nullptr));
        CBX_Soma->setItemText(2, QCoreApplication::translate("Form", "Mezomorph", nullptr));
        CBX_Soma->setItemText(3, QCoreApplication::translate("Form", "Ektomezomorph", nullptr));
        CBX_Soma->setItemText(4, QCoreApplication::translate("Form", "Endomezomorph", nullptr));
        CBX_Soma->setItemText(5, QCoreApplication::translate("Form", "Endomorph", nullptr));

        lbl_gender->setText(QCoreApplication::translate("Form", "Gender", nullptr));
        genderBTN_M->setText(QCoreApplication::translate("Form", "Male", nullptr));
        genderBTN_FM->setText(QCoreApplication::translate("Form", "Female", nullptr));
        lbl_activ->setText(QCoreApplication::translate("Form", "Activity", nullptr));
        activityBTN_No->setText(QCoreApplication::translate("Form", "No activity", nullptr));
        activityBTN_Light->setText(QCoreApplication::translate("Form", "Light activity", nullptr));
        activityBTN_Middle->setText(QCoreApplication::translate("Form", "Middle activity", nullptr));
        activityBTN_Intense->setText(QCoreApplication::translate("Form", "Intensive activity", nullptr));
        lbl_goal->setText(QCoreApplication::translate("Form", "Goal", nullptr));
        goalBTN_Lose->setText(QCoreApplication::translate("Form", "Lose weight", nullptr));
        goalBTN_Gain->setText(QCoreApplication::translate("Form", "Gain weight", nullptr));
        goalBTN_Maintain->setText(QCoreApplication::translate("Form", "Weight maintenaince", nullptr));
        lbl_training->setText(QCoreApplication::translate("Form", "Type of training", nullptr));
        trainingBTN_BW->setText(QCoreApplication::translate("Form", "Bodyweight training", nullptr));
        trainingBTN_STR->setText(QCoreApplication::translate("Form", "Strenght training", nullptr));
        btnSubmit->setText(QCoreApplication::translate("Form", "Submit", nullptr));
        lbl_picture->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
