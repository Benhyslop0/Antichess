#include "king.h"
#include <iostream>
King::King(){
}
bool King::movement(){
    if(currow == wantrow && curcol == wantcol+1){
        return true;
    }
    else if(currow == wantrow && curcol == wantcol-1){
        return true;
    }
    else if(currow == wantrow+1 && curcol == wantcol){
        return true;
    }
    else if(currow == wantrow-1 && curcol == wantcol){
        return true;
    }
    else if(currow == wantrow+1 && curcol == wantcol+1){
        return true;
    }
    else if(currow == wantrow+1 && curcol == wantcol-1){
        return true;
    }
    else if(currow == wantrow-1 && curcol == wantcol+1){
        return true;
    }
    else if(currow == wantrow-1 && curcol == wantcol-1){
        return true;
    }
    else{
        return false;
    }

}
void King::posassign(int cx,int cy,int nx, int ny){
    std::cout<<"i have updated the current pos";//was trying to debug
    currow = cx;
    curcol = cy;
    wantrow = nx;
    wantcol = ny;
}