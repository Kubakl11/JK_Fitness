#ifndef EXPORTPDF_H
#define EXPORTPDF_H

#include <QMainWindow>
#include "ui_exportpdf.h"
#include "src/backend/pdfhandler.h"
#include <iostream>

namespace Ui {
class exportPDF;
}

class exportPDF : public QMainWindow
{
    Q_OBJECT

public:
    explicit exportPDF(QWidget *parent = nullptr);
    // vypocitane hodnoty od klienta
    explicit exportPDF(QWidget *parent, QString name, double weight, double height, double bodyfat, int age, QString comboBoxSomatotyp, QString RB_gender, QString RB_activity, QString RB_goal, QString RB_training, double LeanBodyMass, double BasalMetabolism, int Calories, int Protein, int Carbohydrates, int Fats);
    ~exportPDF();
    FitnessPerson fp;
private slots:
    void on_pushButton_export_clicked();
    void on_pushButton_clicked();
private:
    Ui::exportPDF *ui;
};

#endif // EXPORTPDF_H
