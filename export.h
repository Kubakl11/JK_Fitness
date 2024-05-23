#ifndef EXPORT_H
#define EXPORT_H

#include <QMainWindow>

namespace Ui {
class exportData;
}

class exportData : public QMainWindow
{
    Q_OBJECT

public:
    explicit exportData(QWidget *parent = nullptr);
    ~exportData();

private:
    Ui::exportData *ui;
};

#endif // EXPORT_H
