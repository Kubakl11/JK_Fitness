#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QButtonGroup>
#include "exportpdf.h"


namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_btnSubmit_clicked();

    void onComboBoxIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Form *ui;
    QComboBox *comboBox;
    QLabel *label_SMT;
    exportPDF *exportPDF;
    void CalculateData();

    QString name;
    double weight;
    int height;
    double bodyfat;
    int age;
    QString comboBoxSomatotyp;
    QString RB_gender;
    QString RB_activity;
    QString RB_goal;
    QString RB_training;

    QButtonGroup *genderGroup;
    QButtonGroup *activityGroup;
    QButtonGroup *goalGroup;
    QButtonGroup *trainingGroup;


    // hodnoty pro pouziti na dalsi strance
    double LeanBodyMass;
    double BasalMetabolism;
    int Calories;
    int Protein;
    int Carbohydrates;
    int Fats;

};

#endif // FORM_H
