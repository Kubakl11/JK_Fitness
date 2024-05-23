#ifndef EXPORT2_H
#define EXPORT2_H

#include <QDialog>

namespace Ui {
class NewWindow;
}

class NewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();

private:
    Ui::NewWindow *ui;
};

#endif // NEWWINDOW_H

