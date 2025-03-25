#include "chessboard.h"
#include "pieces.h"
#include <iostream>
int main()
{
    std::string input;
    int row, col, nrow, ncol, countr = 0;

    bool gameover = false;
    bool wplaying = true;
    bool bplaying = false;
    bool invalid_move = true;
    chessboard w;  // Create an instance of ChessBoard
    // Show the ChessBoard as the main window

    while (!gameover)
    {
        system("cls");
        w.printBoard(wplaying ,bplaying);
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
            if (row < 0 || row>7 || col < 0 || col>7 || nrow < 0 || nrow>7 || ncol < 0 || ncol>7) {
                std::cout << "invalid move\n";
                std::cout << "letters must be cap, sorry shit code ";
                invalid_move = true;
                continue;
            }
         //   std::cout << "Before cantake check" << std::endl;
            int takecheck = w.cantake(wplaying, bplaying);
         //   std::cout << "After cantake check: " << takecheck << std::endl;

            bool mustcapture = (takecheck == 1); // If 1 means captures are available

            // Check if this move is a capture when captures are available
            bool iscapturing = (w.arr[nrow][ncol] != nullptr &&
                ((wplaying && w.arr[nrow][ncol]->get_colour() == BLACK) ||
                    (bplaying && w.arr[nrow][ncol]->get_colour() == WHITE)));

            if (mustcapture && !iscapturing) {
                std::cout << "Capture is available! You must capture when possible.";
                invalid_move = true;
            }
            else if (w.grid_pressed(row, col, nrow, ncol, wplaying, bplaying) == 0) {
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
            else if (w.piece_is_taken() == true or w.nomoves()==1) {
                std::cout << "Draw";
                gameover = true;
            }
        }



    }

    return 0;
}
