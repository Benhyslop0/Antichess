#include "pieces.h"
#include <iostream>


Pawn::Pawn() {};
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

bool Queen::movement()
{
    for (int i = 0; i <= 7; i++) {
        if (currow == wantrow && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow && curcol == wantcol - i) {
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol) {
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol - i) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol - i) {
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


bool Rook::movement()
{
    for (int i = 0; i <= 7; i++) {
        if (currow == wantrow && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow && curcol == wantcol - i) {
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol) {
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
bool Bishop::movement()
{
    for (int i = 0; i <= 7; i++) {
        if (currow == wantrow + i && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow + i && curcol == wantcol - i) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol + i) {
            return true;
        }
        else if (currow == wantrow - i && curcol == wantcol - i) {
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
