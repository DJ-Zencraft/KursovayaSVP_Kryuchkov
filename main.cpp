#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Расчёт поверхности тела человека");
    w.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    w.setMinimumSize(1250, 600);
    w.setMaximumSize(1255, 605);
    w.show();

    return a.exec();
}
