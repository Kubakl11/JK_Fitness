#include "export.h"
#include "ui_export.h"

exportData ::exportData(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exportData)
{
    ui->setupUi(this);
}

exportData ::~exportData()
{
    delete ui;
}
