/********************************************************************************
** Form generated from reading UI file 'jk_fitness.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JK_FITNESS_H
#define UI_JK_FITNESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JK_Fitness
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_passw;
    QPushButton *pushButton;
    QLabel *lbl_picture;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JK_Fitness)
    {
        if (JK_Fitness->objectName().isEmpty())
            JK_Fitness->setObjectName("JK_Fitness");
        JK_Fitness->resize(781, 573);
        QFont font;
        font.setPointSize(6);
        JK_Fitness->setFont(font);
        JK_Fitness->setTabShape(QTabWidget::Rounded);
        JK_Fitness->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(JK_Fitness);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(160, 30, 481, 271));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft JhengHei UI")});
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setHintingPreference(QFont::PreferVerticalHinting);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(130, 40, 260, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei")});
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setHintingPreference(QFont::PreferVerticalHinting);
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setMinimumSize(QSize(160, 0));
        lineEdit_username->setLayoutDirection(Qt::LeftToRight);
        lineEdit_username->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_username);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        lineEdit_passw = new QLineEdit(layoutWidget);
        lineEdit_passw->setObjectName("lineEdit_passw");
        lineEdit_passw->setMinimumSize(QSize(160, 0));
        lineEdit_passw->setLayoutDirection(Qt::LeftToRight);
        lineEdit_passw->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_passw);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setHintingPreference(QFont::PreferVerticalHinting);
        pushButton->setFont(font3);

        verticalLayout->addWidget(pushButton);

        lbl_picture = new QLabel(centralwidget);
        lbl_picture->setObjectName("lbl_picture");
        lbl_picture->setGeometry(QRect(210, 310, 388, 207));
        lbl_picture->setMinimumSize(QSize(388, 207));
        lbl_picture->setMaximumSize(QSize(5000, 5600));
        lbl_picture->setLayoutDirection(Qt::LeftToRight);
        lbl_picture->setAlignment(Qt::AlignCenter);
        JK_Fitness->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JK_Fitness);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 781, 20));
        JK_Fitness->setMenuBar(menubar);
        statusbar = new QStatusBar(JK_Fitness);
        statusbar->setObjectName("statusbar");
        JK_Fitness->setStatusBar(statusbar);

        retranslateUi(JK_Fitness);

        QMetaObject::connectSlotsByName(JK_Fitness);
    } // setupUi

    void retranslateUi(QMainWindow *JK_Fitness)
    {
        JK_Fitness->setWindowTitle(QCoreApplication::translate("JK_Fitness", "JK_Fitness", nullptr));
        groupBox->setTitle(QCoreApplication::translate("JK_Fitness", "JK Fitness login", nullptr));
        label_2->setText(QCoreApplication::translate("JK_Fitness", "Username", nullptr));
        label->setText(QCoreApplication::translate("JK_Fitness", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("JK_Fitness", "Login", nullptr));
        lbl_picture->setText(QCoreApplication::translate("JK_Fitness", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JK_Fitness: public Ui_JK_Fitness {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JK_FITNESS_H
