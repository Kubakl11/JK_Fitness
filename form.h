#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QComboBox>
#include <QLabel>

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
};

#endif // FORM_H
