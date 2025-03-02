#ifndef PAWN_H
#define PAWN_H


class Pawn
{
public:
    Pawn();
    void posassign(int cx,int cy,int nx, int ny);
    bool movement(int piecenum);
private:
    int piecenum;
    int currow,curcol,wantrow,wantcol;

};

#endif // PAWN_H
