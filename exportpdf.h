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
    ~exportPDF();

private:
    Ui::exportPDF *ui;
private slots:
    void on_pushButton_export_clicked();
};

#endif // EXPORTPDF_H
