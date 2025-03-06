
#include "chessboard.h"
#include <iostream>
int main()
{
    std::string input;
    int row;
    int col;
    int nrow;
    int ncol;
    bool gameover = false;
    chessboard w;  // Create an instance of ChessBoard
    // Show the ChessBoard as the main window
    
    while (!gameover)
    {
        w.printBoard();
        std::cout << "\n\n\n\n\n\nMove From: ";
        std::cin >> input;
        row = input[0]-'A';
        col = input[1]-'1';
        std::cout << "Move To: ";
        std::cin >> input;
        std::cout << "\n\n\n\n\n\n";
        nrow = input[0]-'A';
        ncol = input[1]-'1';
        w.grid_pressed(row, col, nrow, ncol);
       
    }
    return 0;
}
