#include "chessboard.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

chessboard::chessboard(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Chess Board");  // title of the window
    setFixedSize(800, 800);  // 800x800 pixels window
}

chessboard::~chessboard() {}

void chessboard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Drawing a basic 8x8 chessboard
    int squareSize = width() / 8;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0)
                painter.setBrush(Qt::white);
            else
                painter.setBrush(Qt::black);
            painter.drawRect(col * squareSize, row * squareSize, squareSize, squareSize);
        }
    }
}

void chessboard::mousePressEvent(QMouseEvent *event)
{
    int squareSize = width() / 8;
    int row = event->position().y() / squareSize;
    int col = event->position().x() / squareSize;
    qDebug() << "Clicked on square: (" << row << ", " << col << ")";
}
int grid::grid_pressed(int row,int col){
    int pos = arr[row][col];
    //checking black
    switch(pos){
    case 1 :
        //is a rook
        break;
    case 2 :
        //is a knight
        break;
    case 3 :
        //is a bishop
        break;
    case 4 :
        //is a king
        break;
    case 5 :
        //is a queen
        break;
    case 6 :
        //is a pawn
        break;
    }
    //checking white
    switch(pos){
    case 7 :
        //is a pawn
        break;
    case 8 :
        //is a rook
        break;
    case 9 :
        //is a knight
        break;
    case 10 :
        //is a bishop
        break;
    case 11 :
        //is a queen
        break;
    case 12 :
        //is a queen
        break;
    }

    return 0;
}