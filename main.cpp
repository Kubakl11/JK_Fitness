#include "jk_fitness.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JK_Fitness w;
    w.show();
    return a.exec();

}
