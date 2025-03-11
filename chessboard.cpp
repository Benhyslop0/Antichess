#include "chessboard.h"
#include <iostream>
#include <stdio.h>
#include "pieces.h"



//checking for what piece has been clicked
int chessboard::grid_pressed(int row, int col, int nrow, int ncol, chessboard board,bool bplaying,bool wplaying) {
    Pawn p;
    Queen q;
    King k;
    Bishop b;
    Rook r;
    Knight n;
    bool wthere = false;
    bool bthere = false;
    int pos = arr[row][col];
    int en = arr[nrow][ncol];

    for (int i = 1; i <= 6; i++) {
        if (i == en) {
            bthere = true;
        }
    }
    for (int i = 7; i <= 12; i++) {
        if (i == en) {
            wthere = true;
        }
    }
    if (wplaying == true && pos > 6) {
        std::cout << "Not your piece!";
        return 0;
    }
    else if (bplaying == true && pos < 7) {
        std::cout << "Not your piece!";
        return 0;
    }
    //checking black
    switch (pos) {
    case 1:
        //is a rook
        r.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!r.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (bthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }
        break;
    case 2:
        //is a knight
        n.posassign(row, col, nrow, ncol);

        //white knights movement checker
        if (!n.movement()) {
            clkco = 0;
        }

        //board checking it's not taking its own teammate
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
                std::cout << "haha i have taken";
            }
            else if (wthere == true) {
                std::cout << "cant move there mate";
            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }
        }
        break;
    case 3:
        //is a bishop
        b.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!b.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (bthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }
        break;
    case 4:
        //is a queen
        q.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!q.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (bthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }


        break;
        //is queen
    case 5:
        k.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!k.movement()) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (bthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }

        break;
        //is a king

    case 6:
        //is a pawn
        //a good example of how grid asks pawn if it can move to a position
        p.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!p.movement(pos)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (nrow == row + 1 && wthere == true && (ncol == col + 1 || ncol == col - 1)) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (wthere == true || bthere == true) {
            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }

        break;
    }
    //checking white
    switch (pos) {
    case 7:

        p.posassign(row, col, nrow, ncol);
        p.movement(pos);
        if (!p.movement(pos)) {
            clkco = 0;
        }
        else {
            //can it be attacking?
            if (nrow == row - 1 && bthere == true && (ncol == col + 1 || ncol == col - 1)) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (wthere == true || bthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }


        }
        //is a pawn
        break;
    case 8:
        //is a rook
        r.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!r.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
            }
            else if (wthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }
        break;
    case 9:
        //is a knight
        n.posassign(row, col, nrow, ncol);

        //white knights movement checker
        if (!n.movement()) {
            clkco = 0;
        }

        //board checking it's not taking its own teammate
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
                std::cout << "haha i have taken";
            }
            else if (wthere == true) {
                std::cout << "cant move there mate";
            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }
        }
        break;
    case 10:
        //is a bishop
        b.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!b.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
            }
            else if (wthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }
        break;
    case 11:
        //is a queen
        q.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!q.movement(board)) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (wthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }
        break;
    case 12:
        //is a king
        k.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!k.movement()) {
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
            }
            else if (wthere == true) {

            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
            }

        }

        break;
        break;
    }

    return 0;
}
int chessboard::updated_grid(int rowold, int colold, int rownew, int colnew, int piecenum) {

    arr[rowold][colold] = 0;
    arr[rownew][colnew] = piecenum;
    clkco = 0;
    return 0;
}
void chessboard::printBoard() {
    std::cout << "\n    A    B    C    D    E    F    G    H\n  ----------------------------------------\n";
    for (int i = 0; i < 8; i++) {

        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; j++) {
            int pos = arr[i][j];
            switch (pos) {
            case 0:
                std::cout << "    |";
                break;
            case 1:
                std::cout << " br |";
                break;
            case 2:
                std::cout << " bn |";
                break;
            case 3:
                std::cout << " bb |";
                break;
            case 4:
                std::cout << " bq |";
                break;
            case 5:
                std::cout << " bk |";
                break;
            case 6:
                std::cout << " bp |";
                break;
            case 7:
                std::cout << " wp |";
                break;
            case 8:
                std::cout << " wr |";
                break;
            case 9:
                std::cout << " wn |";
                break;
            case 10:
                std::cout << " wb |";
                break;
            case 11:
                std::cout << " wq |";
                break;
            case 12:
                std::cout << " wk |";
                break;
            }
        }
        std::cout << i + 1 << " \n |----------------------------------------\n";

    }
    std::cout << "    A    B    C    D    E    F    G    H";

};


void chessboard::piece_is_taken(int piecenum) {
    if (piecenum == 1) {
        btaken--;
    }
    else if (piecenum == 2) {
        btaken--;
    }
    else if (piecenum == 3) {
        btaken--;
    }
    else if (piecenum == 4) {
        btaken--;
    }
    else if (piecenum == 5) {
        btaken--;
    }
    else if (piecenum == 6) {
        btaken--;
    }
    else if (piecenum == 7) {
        wtaken--;
    }
    else if (piecenum == 8) {
        wtaken--;
    }
    else if (piecenum == 9) {
        wtaken--;
    }
    else if (piecenum == 10) {
        wtaken--;
    }
    else if (piecenum == 11) {
        wtaken--;
    }
    else if (piecenum == 12) {
        wtaken--;
    }
}

bool chessboard::is_white_gone() {
    if (wtaken == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool chessboard::is_black_gone() {
    if (btaken == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool cantake(chessboard brd,bool bturn, bool wturn) {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            int pos = brd.arr[i][j];
            if (wturn == true && pos >= 1 and pos = < 6) {
                for (int k = 0; k <= 7; k++) {
                    for (int l = 0; l <= 7; l++) {
                        if(brd.grid_pressed(i,j,k, l, brd, wturn, bturn))
                       





                    }
                }
            }
        }
    }
}

