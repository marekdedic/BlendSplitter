#include "include/Main.hpp"

int main(int argc, char *argv[]) {

    QApplication* APPLICATION{new QApplication{argc, argv}};
    QMainWindow* WINDOW{new QMainWindow{}};
    QLabel* Label1{new QLabel{"NIMPaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"}};
    QLabel* Label2{new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"}};

    WINDOW->resize(860, 640);
    WINDOW->setWindowTitle("NIMP");
    WINDOW->setWindowIcon(QIcon("icon.png"));
    WINDOW->setCentralWidget(Splitter::getInstance());
    Splitter::getInstance()->addWidget(Label1);
    Splitter::getInstance()->addWidget(Label2);

    WINDOW->setStyleSheet("QSplitter::handle{background: black;}");

    WINDOW->show();

    return APPLICATION->exec();
}
