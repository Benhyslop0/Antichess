#include <QAapplication>
#include "chessboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChessBoard w;  // Create an instance of ChessBoard
    w.show();  // Show the ChessBoard as the main window

    return a.exec();  // Enter the Qt event loop
}