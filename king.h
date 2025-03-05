#ifndef KING_H
#define KING_H

class King {
public:
    King();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

#endif // KING_H