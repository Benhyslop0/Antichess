#pragma once
#include <QLabel>
#include <QMainWindow>
struct grid {
public:
    int arr[8][8] = {
        {1,2,3,4,5,3,2,1},
        {6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {7,7,7,7,7,7,7,7},
        {8,9,10,11,12,10,9,8} //top is white (1-6),bottom is black (7-12),no mans land is defined by 0s
    };
    grid(int& clkco) :clkco(clkco) {}
    void grid_pressed(int row, int col, int nrow, int ncol, int squareSize);
    void updated_grid(int rowold, int colold, int rownew, int colnew, int piecenum);
private:

    int& clkco;
};


QT_BEGIN_NAMESPACE
namespace Ui {
    class chessboard;
}
QT_END_NAMESPACE

class chessboard : public QMainWindow
{
    Q_OBJECT

public:
    chessboard(QWidget* parent = nullptr);
    ~chessboard();
    void paintEvent(QPaintEvent* event) override;  // Function to paint the chessboard
    void mousePressEvent(QMouseEvent* event) override; //gets mousepressed event

private:
    Ui::chessboard* ui;
    // making grid like this just now because i forgot inheritance

    //variables to distinguish the first click on a piece and the second
    int firstclkro, firstclkco;
    int clkco = 0;
    grid* a_grid;

};


