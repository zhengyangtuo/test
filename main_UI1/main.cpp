#include "importantareamainui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImportantAreaMainUi w;
    w.show();
    return a.exec();
}
