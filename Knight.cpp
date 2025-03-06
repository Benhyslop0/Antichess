#include "Knight.h"

Knight::Knight() {
}
void Knight::posassign(int cx, int cy, int nx, int ny) {
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}

bool Knight::movement(){
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

}