#ifndef JK_FITNESS_H
#define JK_FITNESS_H

#include <QMainWindow>
#include "form.h"
#include <QWidget>
#include <QPixmap>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui {
class JK_Fitness;
}
QT_END_NAMESPACE

class JK_Fitness : public QMainWindow
{
    Q_OBJECT

public:
    JK_Fitness(QWidget *parent = nullptr);
    ~JK_Fitness();

protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_pushButton_clicked();

private:
    Ui::JK_Fitness *ui;
    Form *Form;
};
#endif // JK_FITNESS_H
