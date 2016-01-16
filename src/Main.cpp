#include <include/Main.hpp>

int main(int argc, char *argv[]) {

    QApplication APPLICATION(argc, argv);
    QMainWindow WINDOW;
    QSplitter* SPLITTER{new QSplitter{}};
    SplitWidget* L1{new SplitWidget{SPLITTER}};
    QLabel* Label1{new QLabel{"NIMPaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", L1}};
    QLabel* Label2{new QLabel{"NIMP2bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", SPLITTER}};

    WINDOW.resize(860, 640);
    WINDOW.setWindowTitle("NIMP");
    WINDOW.setWindowIcon(QIcon("icon.png"));
    WINDOW.setCentralWidget(SPLITTER);
    SPLITTER->setChildrenCollapsible(false);
    SPLITTER->setHandleWidth(1);

    WINDOW.show();

    return APPLICATION.exec();
}
