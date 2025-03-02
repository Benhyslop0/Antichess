#pragma once

#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QMainWindow>


class Pawn : public QLabel {
    Q_OBJECT
public:
    void posassign(int cx, int cy, int nx, int ny);
    bool movement(int piecenum);
    explicit Pawn(QWidget* parent = nullptr);
private:
    int piecenum;
    int currow, curcol, wantrow, wantcol;

};
