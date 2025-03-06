#ifndef KNIGHT_H
#define KNIGHT_H

class Knight {
public:
    Knight();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

#endif // KNIGHT_H