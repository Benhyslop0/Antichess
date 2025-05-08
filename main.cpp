#include "chessboard.h"
#include "pieces.h"
#include <iostream>
#include <random>
int main()
{
    //------------------------------------------
    //for user input
    std::string input;
    //for random number generation
    int row, col, nrow, ncol, countr = 0;
    //for the game loop
    bool gameover = false;
    //turn checkers
    bool wplaying = true;
    bool bplaying = false;
    bool invalid_move = true;
    bool ai = false;
    bool invalid_input = true;
    //made w since the start and im not changing it now
    //this is what the chessboard class is called   
    chessboard w;  
    //------------------------------------------
    //starting the game off 
    std::cout << "Welcome to AntiChess!\n";
    std::cout << "Enter your moves in the format: A1 B2\n";
    std::cout << "Where A1 is the piece position you want to move from and B2 is the destination\n";
    std::cout << "single or multiplayer (1 or 0)\n";
    //checks mode they want to play in
    //1 for single player 0 for multiplayer
    while (invalid_input) {
        std::cout << "Enter 1 for single player or 0 for multiplayer: ";
        std::cin >> countr;
        if (countr == 1 || countr == 0) {
            invalid_input = false; // Valid input, exit the loop
        }
        else {
            std::cout << "Invalid input. Please enter 1 or 0.\n";
        }
    }

    if (countr == 1) {
        std::cout << "AI is black\n";
        ai = true;
    }
    else {
        std::cout << "No ai selected\n";
    }
    //-------------------------------------------------------------
    //game loop
    while (!gameover)
    {   
        //clears the screen for the next turn
        system("cls");
        invalid_move = true;
        w.printBoard(wplaying, bplaying);
        if (wplaying) {
            std::cout << "\n\n\n\n\n\nWhite's turn\n";
        }
        else {
            std::cout << "\n\n\n\n\n\nBlack's turn\n";
        };
        //checks for end of game conditions
        //always at the start so the game will end without needing a move
        if (w.is_black_gone()) {
            std::cout << "Black Wins!";
            gameover = true;
        }
        else if (w.is_white_gone()) {
            std::cout << "White Wins!";
            gameover = true;
        }
        else if (w.piece_is_taken() or w.nomoves(wplaying, bplaying) == 1) {
            std::cout << "Draw";
            gameover = true;
        }
        //---------------------------------------------------------------------------------
        //ai loop for moving pieces
        //same checks as the player but with a random number generator to select the piece to move
        if (ai == true && bplaying == true && !gameover) {
            while (invalid_move) {
                int takecheck = w.cantake(wplaying, bplaying);
                bool mustcapture = (takecheck == 1);
                if (!mustcapture) {
                    row = 0 + (rand() % 7);
                    col = 0 + (rand() % 7);
                    nrow = 0 + (rand() % 7);
                    ncol = 0 + (rand() % 7);
                }
                else if (mustcapture) {
                    row = w.return_move_from_x();
                    col = w.return_move_from_y();
                    nrow = w.return_needed_x();
                    ncol = w.return_needed_y();
                }
                //checks player is following the rules of the game
                bool iscapturing = (w.arr[nrow][ncol] != nullptr &&
                    ((wplaying && w.arr[nrow][ncol]->get_colour() == BLACK) ||
                        (bplaying && w.arr[nrow][ncol]->get_colour() == WHITE)));

                if (mustcapture == true && !iscapturing) {
                    //std::cout << "Capture is available! You must capture when possible.";
                    invalid_move = true;
                }
                else if (w.arr[row][col] != nullptr && w.arr[row][col]->get_colour() == BLACK) {
                    if (w.grid_pressed(row, col, nrow, ncol, wplaying, bplaying) == 0) {
                        //std::cout << "Invalid Move!";
                        invalid_move = true;

                    }
                    else {
                        invalid_move = false;
                        //switching between players
                        if (wplaying) {
                            wplaying = false;
                            bplaying = true;
                        }
                        else if (bplaying) {
                            wplaying = true;
                            bplaying = false;
                        }

                    }
                }
            }
        }
        else if(!gameover) {
            while (invalid_move) {
                //std::cout << "AI is not selected\n";
                std::cout << "\n\n\n\n\n\nMove From: ";
                std::cin >> input;
                row = input[1] - '1';
                col = input[0] - 'A';
                std::cout << "Move To: ";
                std::cin >> input;
                std::cout << "\n\n\n\n\n\n";
                nrow = input[1] - '1';
                ncol = input[0] - 'A';
                //boundary check for the input
                if (row < 0 || row>7 || col < 0 || col>7 || nrow < 0 || nrow>7 || ncol < 0 || ncol>7) {
                    std::cout << "invalid move\n";
                    std::cout << "letters must be cap, sorry shit code ";
                    invalid_move = true;
                    continue;
                }
                int takecheck = w.cantake(wplaying, bplaying);
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
                    if (wplaying) {
                        wplaying = false;
                        bplaying = true;
                    }
                    else if (bplaying) {
                        wplaying = true;
                        bplaying = false;
                    }
                }
            }
            
        }
    }

    return 0;
}