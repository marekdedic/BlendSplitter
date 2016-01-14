#include <QMainWindow>
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication APPLICATION(argc, argv);
    QMainWindow WINDOW{0};

    WINDOW.resize(860, 640);
    WINDOW.setWindowTitle("NIMP App");
    WINDOW.setWindowIcon(QIcon("icon.png"));

    WINDOW.show();

    return APPLICATION.exec();
}
