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
};

#endif // EXPORTPDF_H
