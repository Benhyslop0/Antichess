#pragma once
#include "chessboard.h"
class Pawn
{
public:
    Pawn();
    void posassign(int cx, int cy, int nx, int ny);
    bool movement(int piecenum);
private:
    int currow, curcol, wantrow, wantcol;

};


class King {
public:
    King();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};


class Queen {
public:
    Queen();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

class Rook {
public:
    Rook();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

class Bishop {
public:
    Bishop();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};



class Knight {
public:
    Knight();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

