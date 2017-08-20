#include "mainwindow.h"
#include <QApplication>
#include "fileprocessor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    FileProcessor p;
    p.show();


    return a.exec();
}
