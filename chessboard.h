#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class chessboard;
}
QT_END_NAMESPACE

class chessboard : public QMainWindow
{
    Q_OBJECT

public:
    chessboard(QWidget *parent = nullptr);
    ~chessboard();

private:
    Ui::chessboard *ui;
protected:
    void paintEvent(QPaintEvent *event) override;  // Function to paint the chessboard
    void mousePressEvent(QMouseEvent *event) override; //gets mousepressed event
};

struct grid {
    int arr[8][8]={
        {1,2,3,4,5,3,2,1},
        {6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {7,7,7,7,7,7,7,7},
        {8,9,10,11,12,10,9,8} //top is white (1-6),bottom is black (7-12),no mans land is defined by 0s
    };
    int grid_pressed(int row, int col);

};
#endif // CHESSBOARD_H