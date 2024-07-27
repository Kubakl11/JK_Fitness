#include "form.h"
#include "ui_form.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <cmath>
#include <QMessageBox>
#include <QFont>

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // Load the image into lbl_picture_2
    QPixmap pic2("C:/Users/Kuba/Desktop/cvut/2. Semestr/C++/JK_Fitness_Semestralka/logo1.png");
    ui->lbl_picture->setPixmap(pic2);
    ui->lbl_picture->setAlignment(Qt::AlignCenter); // Center the image







    // Inicializace button groups
    genderGroup = new QButtonGroup(this);
    genderGroup->addButton(ui->genderBTN_M);
    genderGroup->addButton(ui->genderBTN_FM);

    activityGroup = new QButtonGroup(this);
    activityGroup->addButton(ui->activityBTN_No);
    activityGroup->addButton(ui->activityBTN_Light);
    activityGroup->addButton(ui->activityBTN_Middle);
    activityGroup->addButton(ui->activityBTN_Intense);

    goalGroup = new QButtonGroup(this);
    goalGroup->addButton(ui->goalBTN_Gain);
    goalGroup->addButton(ui->goalBTN_Lose);
    goalGroup->addButton(ui->goalBTN_Maintain);

    trainingGroup = new QButtonGroup(this);
    trainingGroup->addButton(ui->trainingBTN_BW);
    trainingGroup->addButton(ui->trainingBTN_STR);
}

Form::~Form()
{
    delete ui;
}
void Form::on_pushButton_clicked()
{
}

void Form::CalculateData()
{
    // text arrays in UI
    name = ui->Line_Name->text(); // Uložení hodnoty z textového pole Line_Name do proměnné name
    weight = ui->Line_Weight->text().toDouble(); // Uložení hodnoty z textového pole weightLineEdit do proměnné weight
    height = ui->Line_Height->text().toInt(); // Uložení hodnoty z textového pole heightLineEdit do proměnné height
    bodyfat = ui->Line_BF->text().toDouble();
    age = ui->Line_Age->text().toInt();

    // Debug output
    qDebug() << "Name:" << name;
    qDebug() << "Weight:" << weight;
    qDebug() << "Height:" << height;
    qDebug() << "Bodyfat:" << bodyfat;
    qDebug() << "Age:" << age;

    // Combobox somatotyp
    comboBoxSomatotyp = ui->CBX_Soma->currentText();

    // Debug output for combobox
    qDebug() << "Somatotyp:" << comboBoxSomatotyp;

    // Gender radio button
    if(ui->genderBTN_M->isChecked()) {
        RB_gender = ui->genderBTN_M->text();
    } else if(ui->genderBTN_FM->isChecked()) {
        RB_gender = ui->genderBTN_FM->text();
    }

    // Activity radio button
    if (ui->activityBTN_No->isChecked()) {
        RB_activity = ui->activityBTN_No->text();
    } else if (ui->activityBTN_Light->isChecked()) {
        RB_activity = ui->activityBTN_Light->text();
    }
    else if (ui->activityBTN_Middle->isChecked()) {
        RB_activity = ui->activityBTN_Middle->text();
    }
    else if (ui->activityBTN_Intense->isChecked()) {
        RB_activity = ui->activityBTN_Intense->text();
    }

    // Goal radio button
    if (ui->goalBTN_Gain->isChecked()) {
        RB_goal = ui->goalBTN_Gain->text();
    } else if (ui->goalBTN_Lose->isChecked()) {
        RB_goal = ui->goalBTN_Lose->text();
    }
    else if (ui->goalBTN_Maintain->isChecked()) {
        RB_goal = ui->goalBTN_Maintain->text();
    }

    // Training radio button
    if(ui->trainingBTN_BW->isChecked()) {
        RB_training = ui->trainingBTN_BW->text();
    } else if(ui->trainingBTN_STR->isChecked()) {
        RB_training = ui->trainingBTN_STR->text();
    }

    // Debug output for radio buttons
    qDebug() << "Gender:" << RB_gender;
    qDebug() << "Activity:" << RB_activity;
    qDebug() << "Goal:" << RB_goal;
    qDebug() << "Training:" << RB_training;


    // Převod textových hodnot z comboboxu a radio buttonů na numerické hodnoty
    double soma = 1.0;
    if (comboBoxSomatotyp == "Ektomorph") {
        soma = 1.1;
    } else if (comboBoxSomatotyp == "Ektomezomorph") {
        soma = 1.05;
    } else if (comboBoxSomatotyp == "Mezomorph") {
        soma = 1.0;
    } else if (comboBoxSomatotyp == "Endomezomorph") {
        soma = 0.95;
    } else if (comboBoxSomatotyp == "Endomorph") {
        soma = 0.9;
    }

    double activ = 1.2;
    if (RB_activity == "No activity") {
        activ = 1.2;
    } else if (RB_activity == "Light activity") {
        activ = 1.4;
    } else if (RB_activity == "Middle activity") {
        activ = 1.6;
    } else if (RB_activity == "Intensive activity") {
        activ = 2.0;
    }

    double G = 1.0;
    if (RB_goal == "Loosing weight") {
        G = 0.85;
    } else if (RB_goal == "Weight maintenance") {
        G = 1.0;
    } else if (RB_goal == "Gain weight") {
        G = 1.2;
    }

    // Lean body mass (LBM)
    double LBM = weight * (1 - (bodyfat / 100));
    qDebug() << "LBM:" << LBM;

    // Basal metabolism (BM)
    double BM;
    if (RB_gender == "Male") {
        BM = 66 + (13.7 * LBM) + (5 * height) - (6.8 * age);
    } else if (RB_gender == "Female") {
        BM = 655 + (9.6 * LBM) + (1.8 * height) - (4.7 * age);
    }

    // Activity factor
    double A = BM * activ;

    // Goal adjustment
    double B = A * G;

    // Somatotype adjustment
    double C = B * soma;

    // Final calorie intake
    double Cal = C;

    // Protein intake
    double P = LBM * 3; // grams of protein
    double Prot = P * 4; // calories from protein

    // Carbohydrate intake
    double CarbF = Cal - Prot; // remaining calories for carbs and fats
    double Ca = CarbF * 0.65; // calories from carbohydrates
    double Carb = Ca / 4; // grams of carbohydrates

    // Fat intake
    double Fa = Cal - Ca - Prot; // calories from fats
    double F = Fa / 9; // grams of fats

    // hodnoty pro pouziti na dasli strance
    LeanBodyMass = LBM;
    BasalMetabolism = BM;
    Calories = static_cast<int>(std::ceil(Cal));
    Protein = static_cast<int>(std::ceil(P));
    Carbohydrates = static_cast<int>(std::ceil(Carb));
    Fats = static_cast<int>(std::ceil(F));

    // Debug output for calculated values
    qDebug() << "LeanBodyMass:" << LeanBodyMass;
    qDebug() << "BasalMetabolism:" << BasalMetabolism;
    qDebug() << "Calories:" << Calories;
    qDebug() << "Protein:" << Protein;
    qDebug() << "Carbohydrates:" << Carbohydrates;
    qDebug() << "Fats:" << Fats;
}



void Form::on_btnSubmit_clicked()
{
    // Check if required fields are filled
    if (ui->Line_Name->text().isEmpty() ||
        ui->Line_Weight->text().isEmpty() ||
        ui->Line_Height->text().isEmpty() ||
        ui->Line_BF->text().isEmpty() ||
        ui->Line_Age->text().isEmpty() ||
        (!ui->genderBTN_M->isChecked() && !ui->genderBTN_FM->isChecked()) ||
        (!ui->activityBTN_No->isChecked() && !ui->activityBTN_Light->isChecked() &&
         !ui->activityBTN_Middle->isChecked() && !ui->activityBTN_Intense->isChecked()) ||
        (!ui->goalBTN_Gain->isChecked() && !ui->goalBTN_Lose->isChecked() && !ui->goalBTN_Maintain->isChecked()) ||
        (!ui->trainingBTN_BW->isChecked() && !ui->trainingBTN_STR->isChecked())) {

        QMessageBox::warning(this, "Input Error", "Please fill in all the required fields.");
        return; // Do not proceed to open the next window
    }

    CalculateData();
    exportPDF = new class exportPDF(this, name, weight, height, bodyfat, age, comboBoxSomatotyp, RB_gender, RB_activity, RB_goal, RB_training, LeanBodyMass, BasalMetabolism, Calories, Protein, Carbohydrates, Fats);
    exportPDF->show();
}
void Form::onComboBoxIndexChanged(int index)
{
    // Zpracování změny výběru v combo boxu
    QString selectedOption = comboBox->currentText();

    qDebug() << "Vybrána možnost: " << selectedOption;
}

void Form::on_comboBox_currentIndexChanged(int index)
{

}
