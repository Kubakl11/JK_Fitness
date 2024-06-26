#include "exportpdf.h"
#include "ui_exportpdf.h"
#include "src/backend/pdfhandler.h"
#include <iostream>
exportPDF::exportPDF(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exportPDF)
{
    ui->setupUi(this);
    //connect(ui->pushButton_export, &QPushButton::clicked, this, &exportPDF::on_pushButton_export_clicked); not needed

}

void exportPDF::on_pushButton_export_clicked()
{
    //std::cout << "Generating pdf...";
    qDebug("Generating pdf...");
    PDFHandler pdf = PDFHandler(this);
}


exportPDF::~exportPDF()
{
    delete ui;
}
