#ifndef EXPORTPDF_H
#define EXPORTPDF_H

#include <QMainWindow>

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

private:
    Ui::exportPDF *ui;
};

#endif // EXPORTPDF_H
