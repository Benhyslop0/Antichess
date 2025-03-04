
#include "chessboard.h"

int main()
{
    bool gameover = false;
    chessboard w;  // Create an instance of ChessBoard
     // Show the ChessBoard as the main window
    while(!gameover)
    {
        w.printBoard();
        //w.grid_pressed(0,0,1,0,3);
        //w.printBoard();
        gameover = true;
    }
    return 0;
}