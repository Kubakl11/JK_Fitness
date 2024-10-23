#include "jk_fitness.h"
#include "./ui_jk_fitness.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QPixmap>
#include <QKeyEvent>
#include <QLineEdit>

JK_Fitness::JK_Fitness(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JK_Fitness)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QPushButton { background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px; margin: 5px; }"
        "QPushButton:hover { background-color: #45a049; }"
        "QLineEdit { border: 2px solid #ccc; border-radius: 4px; padding: 0 8px; selection-background-color: darkgray; font-size: 16px; }"
        "QLabel#label, QLabel#label_2 { font-size: 16px; }"
        "QGroupBox#groupBox { font-size: 22px; }"
        );
    ui->lineEdit_passw->setEchoMode(QLineEdit::Password);
    ui->lineEdit_username->setFocus();
    connect(ui->lineEdit_passw, &QLineEdit::returnPressed, this, &JK_Fitness::on_pushButton_clicked);


    QPixmap pic("C:/Users/Kuba/Desktop/cvut/2. Semestr/C++/JK_Fitness_Semestralka/logo1.png");

    // Nastavení pixmap do existujícího QLabelu vytvořeného ve vašem .ui souboru
    ui->lbl_picture->setPixmap(pic);
    ui->lbl_picture->setAlignment(Qt::AlignCenter); // Zarovná obrázek na střed

    // Vytvoření nového QLabelu
    QLabel *lbl_picture = new QLabel;
    lbl_picture->setPixmap(pic);
    lbl_picture->setAlignment(Qt::AlignCenter); // Zarovná obrázek na střed
    lbl_picture -> setFixedSize(pic.size());

    QIcon icon(":/src/img/JK_fitness_logo.ico");
    this->setWindowIcon(icon);

}

JK_Fitness::~JK_Fitness()
{
    delete ui;
}

void JK_Fitness::on_pushButton_clicked()
{
    ui->lineEdit_passw->setProperty("smallText", true);
    QString username = ui ->lineEdit_username -> text();
    QString password = ui ->lineEdit_passw -> text();


    if (username == "o" && password == "k")
    {
        QMessageBox::information(this, "Login","Login succesfull!" );

        Form = new class Form();
        Form->show();
        this->hide ();
        return;
    }
    else QMessageBox::warning(this, "Login","Wrong username or password!" );
    {

        ui->lineEdit_username->clear();
        ui->lineEdit_passw->clear();
    }
}

void JK_Fitness::keyPressEvent(QKeyEvent *event)
{
    QMainWindow::keyPressEvent(event);
}
