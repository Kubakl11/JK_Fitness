#include "exportpdf.h"
#include "ui_exportpdf.h"

exportPDF::exportPDF(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exportPDF)
{
    ui->setupUi(this);
}

exportPDF::~exportPDF()
{
    delete ui;
}
