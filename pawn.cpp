#include "pawn.h"
#include <QDebug>
#include <QMouseEvent>
#include <QWidget>
#include<QLabel>
#include <QMainWindow>


Pawn::Pawn(QWidget* parent) : QLabel(parent) {
}

//assigning values based on the pawns possition
void Pawn::posassign(int cx, int cy, int nx, int ny) {
    qDebug() << "i have updated the current pos";//was trying to debug
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}
//boolean function so the pawn itself is checking if it can move
bool Pawn::movement(int piecenum) {


    switch (piecenum) {

        // Black Pawn
    case 6:
        if (currow == 1) {
            if (wantrow == currow + 2 || wantrow == currow + 1) {
                return true;
            }
            else {
                qDebug() << "black Pawn can't go there";
                return false;
            }
        }
        else {
            if (wantrow == currow + 1) {
                return true;
            }
            else {
                qDebug() << "the black one can't go there";
                return false;
            }
        }
        break;

        // White Pawn
    case 7:
        if (currow == 6) {
            if (wantrow == currow - 2 || wantrow == currow - 1) {
                return true;
            }
            else {
                qDebug() << "white Pawn can't go there";
                return false;
            }
        }
        else {
            if (wantrow == currow - 1) {
                return true;
            }
            else {
                qDebug() << "the white one can't go there";
                return false;
            }
        }
        break;
    }
    return true;
}
