#include "chessboard.h"
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "pawn.h"
chessboard::chessboard(QWidget *parent)
    : QMainWindow(parent), a_grid(new grid(clkco))
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
    //grid a_grid;
    int squareSize = width() / 8;
    int row = event->position().y() / squareSize;
    int col = event->position().x() / squareSize;


    qDebug() << "Clicked on square: (" << row << ", " << col << ")";

    if(clkco == 0){
        firstclkro =row;
        firstclkco =col;

        clkco = 1;

    }
    else if(clkco ==1){
        a_grid->grid_pressed(firstclkro,firstclkco,row,col,squareSize);

    }



}
//checking for what piece has been clicked
int grid::grid_pressed(int row,int col,int nrow,int ncol,int squareSize){
    Pawn p;
    bool wthere = false;
    bool bthere = false;
    int pos = arr[row][col];
    int en = arr[nrow][ncol];

    for(int i = 1 ; i<= 6 ; i++ ){
        if(i == en){
            bthere = true;
        }
    }
    for(int i = 7 ; i<= 12 ; i++ ){
        if(i == en){
            wthere = true;
        }
    }
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
        //a good example of how grid asks pawn if it can move to a position
        p.posassign(row,col,nrow,ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if(!p.movement(pos)){
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else{
            if(nrow == row+1 && wthere == true && (ncol == col+1 || ncol == col-1)){
                updated_grid(row,col,nrow,ncol,pos);
                qDebug()<<"haha i have taken";
            }
            else if(wthere ==true ||bthere ==true){
                qDebug()<<"cant move there mate";
            }
            else{
                updated_grid(row,col,nrow,ncol,pos);
            }

        }

        break;
    }
    //checking white
    switch(pos){
    case 7 :

        p.posassign(row,col,nrow,ncol);
        p.movement(pos);
        if(!p.movement(pos)){
            clkco = 0;
        }
        else {
            //can it be attacking?
            if(nrow == row-1 && bthere == true && (ncol == col+1 || ncol == col-1)){
                updated_grid(row,col,nrow,ncol,pos);
                qDebug()<<"haha i have taken";
            }
            else if(wthere ==true ||bthere ==true){
                qDebug()<<"cant move there mate";
            }
            else{
                updated_grid(row,col,nrow,ncol,pos);
            }


        }
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
int grid::updated_grid(int rowold,int colold,int rownew,int colnew,int piecenum){

    arr[rowold][colold]=0;
    arr[rownew][colnew] = piecenum;
    clkco = 0;
    return 0;
}