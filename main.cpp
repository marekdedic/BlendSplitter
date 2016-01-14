#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication APPLICATION(argc, argv);
    QMainWindow WINDOW{0};

    WINDOW.resize(860, 640);
    WINDOW.setWindowTitle("NIMP App");

    WINDOW.show();

    return APPLICATION.exec();
}
