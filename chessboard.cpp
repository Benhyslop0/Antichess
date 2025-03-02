#include "chessboard.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "pawn.h"
chessboard::chessboard(QWidget* parent)
    : QMainWindow(parent), a_grid(new grid(clkco))
{

    setWindowTitle("Chess Board");  
    setFixedSize(800, 800);  

    for (int col = 0; col < 8; ++col) {
        //pawns
        Pawn* whitePawn = new Pawn(this);
        Pawn* blackPawn = new Pawn(this);

      

    }
}

chessboard::~chessboard() {}


void chessboard::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    int squareSize = width() / 8;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0)
                painter.setBrush(Qt::white);
            else
                painter.setBrush(Qt::black);
            painter.drawRect(col * squareSize, row * squareSize, squareSize, squareSize);

            if (a_grid->arr[row][col] == 6) { //black 
             
                //QPixmap pixmap(""); 
                //painter.drawPixmap(col * squareSize, row * squareSize, squareSize, squareSize, pixmap);
                painter.setBrush(Qt::blue);
                painter.drawRect(col * squareSize, row * squareSize, squareSize / 2, squareSize / 2);
            }
            else if (a_grid->arr[row][col] == 7) { //white
              
               // QPixmap pixmap(""); 
               // painter.drawPixmap(col * squareSize, row * squareSize, squareSize, squareSize, pixmap);
               painter.setBrush(Qt::red);  
               painter.drawRect(col * squareSize, row * squareSize, squareSize/2, squareSize/2);
            }
        }
    }
}
