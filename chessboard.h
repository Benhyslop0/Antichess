
#ifndef CHESSBOARD_H
#define CHESSBOARD_H


class chessboard
{
public:
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
    
    int grid_pressed(int row,int col,int nrow,int ncol,int squareSize);
    int updated_grid(int rowold,int colold,int rownew,int colnew,int piecenum);
    void printBoard();
private:

    int clkco;
};
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");
};

