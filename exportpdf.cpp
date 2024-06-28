#include "exportpdf.h"
#include "ui_exportpdf.h"

exportPDF::exportPDF(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exportPDF)
{
    ui->setupUi(this);
}

exportPDF::exportPDF(QWidget *parent, QString name, double weight, double height, double bodyfat, int age, QString comboBoxSomatotyp, QString RB_gender, QString RB_activity, QString RB_goal, QString RB_training, double LeanBodyMass, double BasalMetabolism, int Calories, int Protein, int Carbohydrates, int Fats) :
    QMainWindow(parent),
    ui(new Ui::exportPDF)
{
    ui->setupUi(this);

    //hodnoty přijaté od klienta
    ui->Line_Name->setText(name);
    ui->Line_Weight->setText(QString::number(weight));
    ui->Line_Height->setText(QString::number(height));
    ui->Line_Bodyfat->setText(QString::number(bodyfat));
    ui->Line_Age->setText(QString::number(age));
    ui->Line_Somatotyp->setText(comboBoxSomatotyp);
    ui->Line_Gender->setText(RB_gender);
    ui->Line_Activity->setText(RB_activity);
    ui->Line_Goal->setText(RB_goal);
    ui->Line_Training->setText(RB_training);


    // nastavení hodnot vypočitaných v form.cpp
    ui->Line_LBM->setText(QString::number(LeanBodyMass));
    ui->Line_BM->setText(QString::number(BasalMetabolism));
    ui->Line_Cal->setText(QString::number(Calories));
    ui->Line_Protein->setText(QString::number(Protein));
    ui->Line_Carb->setText(QString::number(Carbohydrates));
    ui->Line_Fats->setText(QString::number(Fats));

    }
exportPDF::~exportPDF()
{
    delete ui;
}
