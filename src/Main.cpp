#include "include/Main.hpp"

int main(int argc, char *argv[]) {

    QApplication* APPLICATION{new QApplication{argc, argv}};
    QMainWindow* WINDOW{new QMainWindow{}};
    Splitter* SPLITTER{new Splitter{}};

    WINDOW->setCentralWidget(SPLITTER);

    WINDOW->resize(860, 640);
    WINDOW->setWindowTitle("NIMP");
    WINDOW->setWindowIcon(QIcon(":/icons/app_icon"));

    QLabel* Label1{new QLabel{"NIMPaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}};
    QLabel* Label2{new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"}};
    SPLITTER->addWidget(Label1);
    SPLITTER->addWidget(Label2);

    WINDOW->setStyleSheet("QSplitter::handle{background: black;}");

    WINDOW->show();

    return APPLICATION->exec();
}
