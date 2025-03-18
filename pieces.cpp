#include "pieces.h"
#include <iostream>

std::pair<int, int> Piece::get_pos() {
    return cur_pos;
}

void Piece::set_pos(int x, int y) {
    cur_pos.first = x;
    cur_pos.second = y;
}

PieceType Piece::get_type() {
    return type;
}

PieceColor Piece::get_colour() {
    return colour;
}

bool Pawn::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }

}

bool Rook::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else {
        return false;
    }
}

bool Knight::check_movement(int x, int y) {
    if (cur_pos.first == x + 2 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 2 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 2 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 2 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 2) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 2) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 2) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 2) {
        return true;
    }
    else {
        return false;
    }
}

bool Queen::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Bishop::check_movement(int x, int y) {
    if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool King::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

/*Pawn::Pawn() {};
//assigning values based on the pawns possition
void Pawn::posassign(int cx, int cy, int nx, int ny) {
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

                return false;
            }
        }
        else {
            if (wantrow == currow + 1) {
                return true;
            }
            else {

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

                return false;
            }
        }
        else {
            if (wantrow == currow - 1) {
                return true;
            }
            else {

                return false;
            }
        }
        break;
    }
    return true;
}

bool Pawn::row(int row) {
    if (row == 0 || row == 7) {
        return true;
    }
    else {
        return false;
    }
}


King::King() {};
bool King::movement() {
    if (currow == wantrow && curcol == wantcol + 1) {
        return true;
    }
    else if (currow == wantrow && curcol == wantcol - 1) {
        return true;
    }
    else if (currow == wantrow + 1 && curcol == wantcol) {
        return true;
    }
    else if (currow == wantrow - 1 && curcol == wantcol) {
        return true;
    }
    else if (currow == wantrow + 1 && curcol == wantcol + 1) {
        return true;
    }
    else if (currow == wantrow + 1 && curcol == wantcol - 1) {
        return true;
    }
    else if (currow == wantrow - 1 && curcol == wantcol + 1) {
        return true;
    }
    else if (currow == wantrow - 1 && curcol == wantcol - 1) {
        return true;
    }
    else {
        return false;
    }

}
void King::posassign(int cx, int cy, int nx, int ny) {
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}


Queen::Queen() {};

bool Queen::movement(chessboard brd)
{
    for (int i = 0; i <= 7; i++) {
        //left
        if (currow == wantrow && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        // right
        else if (currow == wantrow && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        //up
        else if (currow == wantrow + i && curcol == wantcol) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        //down
        else if (currow == wantrow - i && curcol == wantcol) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }

    }
    return false;


}

void Queen::posassign(int cx, int cy, int nx, int ny)
{
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}





Rook::Rook() {}


bool Rook::movement(chessboard brd)
{
    for (int i = 1; i <= 7; i++) {
        //left
        if (currow == wantrow && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        // right
        else if (currow == wantrow && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        //up
        else if (currow == wantrow + i && curcol == wantcol) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        //down
        else if (currow == wantrow - i && curcol == wantcol) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}



void Rook::posassign(int cx, int cy, int nx, int ny)
{
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
};

Bishop::Bishop() {}
bool Bishop::movement(chessboard brd)
{
    for (int i = 0; i <= 7; i++) {

        if (currow == wantrow + i && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow - j][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol + i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol - j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol - i) {
            for (int j = 1; j < i; j++) {
                int pos = brd.arr[currow + j][curcol + j];
                if (pos > 0) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
};

void Bishop::posassign(int cx, int cy, int nx, int ny)
{
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}


Knight::Knight() {
}
void Knight::posassign(int cx, int cy, int nx, int ny) {
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}

bool Knight::movement() {
    if (wantrow == currow + 2 && wantcol == curcol + 1) {
        return true;
    }
    else if (wantrow == currow + 2 && wantcol == curcol - 1) {
        return true;
    }
    else if (wantrow == currow - 2 && wantcol == curcol + 1) {
        return true;
    }
    else if (wantrow == currow - 2 && wantcol == curcol - 1) {
        return true;
    }
    else if (wantrow == currow + 1 && wantcol == curcol + 2) {
        return true;
    }
    else if (wantrow == currow + 1 && wantcol == curcol - 2) {
        return true;
    }
    else if (wantrow == currow - 1 && wantcol == curcol + 2) {
        return true;
    }
    else if (wantrow == currow - 1 && wantcol == curcol - 2) {
        return true;
    }
    else {
        return false;
    }

}*/