#include "form.h"
#include "ui_form.h"
#include <QPixmap>
#include <QVBoxLayout>

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    // Načtení obrázku
    QPixmap pic("C:/Users/Kuba/Desktop/cvut/2. Semestr/C++/JK_Fitness_Semestralka/logo1.png");

    // Nastavení pixmapy do existujícího QLabelu vytvořeného ve vašem .ui souboru
    ui->lbl_picture_1->setPixmap(pic);
    ui->lbl_picture_1->setAlignment(Qt::AlignCenter); // Zarovná obrázek na střed

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(ui->lbl_picture_1); // Pokud QLabel není již přidán
    setLayout(layout);
}

Form::~Form()
{
    delete ui;
}
void Form::on_pushButton_clicked()
{ 
}

void Form::on_btnSubmit_clicked()
{
    exportPDF = new class exportPDF(this);
    exportPDF->show();
}
void Form::onComboBoxIndexChanged(int index)
{
    // Zpracování změny výběru v combo boxu
    QString selectedOption = comboBox->currentText();
    // Udělejte něco s vybranou možností, např. zobrazte ji v konzoli
    qDebug() << "Vybrána možnost: " << selectedOption;
}

void Form::on_comboBox_currentIndexChanged(int index)
{

}

