#include "infosys.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InfoSys w;
    w.show();
    return a.exec();

}
