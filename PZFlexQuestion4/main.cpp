#include "mainwindow.h"
#include "notepad.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Notepad *notepad = new Notepad();

    return a.exec();
}
