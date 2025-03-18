#include "chessboard.h"
#include "pieces.h"
#include <iostream>
int main()
{
    std::string input;
    int row,col,nrow,ncol,countr = 0;
    
    bool gameover = false;
    bool wplaying = true;
    bool bplaying = false;
    bool invalid_move = true;
    chessboard w;  // Create an instance of ChessBoard
    // Show the ChessBoard as the main window

    while (!gameover)
    {
        w.printBoard();
        if (wplaying) {
            std::cout << "\n\n\n\n\n\nWhite's turn\n";
        }
        else {
            std::cout << "\n\n\n\n\n\nBlack's turn\n";
        };

        invalid_move = true;
        
        while (invalid_move == true) {
            std::cout << "\n\n\n\n\n\nMove From: ";
            std::cin >> input;
            row = input[1] - '1';
            col = input[0] - 'A';
            std::cout << "Move To: ";
            std::cin >> input;
            std::cout << "\n\n\n\n\n\n";
            nrow = input[1] - '1';
            ncol = input[0] - 'A';
            //bool takecheck = w.cantake(w,wplaying,bplaying);
            if (/*(w.arr[nrow][ncol] == 0 and takecheck == true) or*/ (w.grid_pressed(row, col, nrow, ncol, wplaying, bplaying) == 0 )) {
                std::cout << "Invalid Move!";
                invalid_move = true;
            }
            else {
                invalid_move = false;
                //switching between players
                if (wplaying == true) {
                    wplaying = false;
                    bplaying = true;
                }
                else if (bplaying == true) {
                    wplaying = true;
                    bplaying = false;
                }
            }
                //checking if the game is over by elimination
            if (w.is_black_gone() == true) {
                std::cout << "Black Wins!";
                gameover = true;
            }
            else if (w.is_white_gone() == true) {
                std::cout << "White Wins!";
                gameover = true;
            }
            //need to make auto pass thing, leave to me for now but checks bishop correct
            else if(w.piece_is_taken() == true){
                std::cout<<"draw";
                gameover = true;
        }
    }
   
    
} 

    return 0;
}