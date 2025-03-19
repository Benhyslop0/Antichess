#include "chessboard.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include<tuple>



//checking for what piece has been clicked

int chessboard::grid_pressed(int row, int col, int nrow, int ncol, bool wplaying, bool bplaying) {

    Piece* piece = arr[row][col];
    PieceColor colour = piece->get_colour();
    PieceType pos = piece->get_type();
    Piece* piece2 = arr[nrow][ncol];
    PieceColor colour2 = NONE_COLOR;
    if (piece2 != nullptr) {

        colour2 = piece2->get_colour();
    }

    std::cout << colour2;
    std::cout << colour;
    if (wplaying == true && colour == BLACK) {
        std::cout << "Not your piece!";
        return 0;
    }
    else if (bplaying == true && colour == WHITE) {
        std::cout << "Not your piece!";
        return 0;
    }


    //checking black
    if (colour == BLACK) {
        switch (pos) {

        case ROOK:
            //is a rook
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == PieceColor::WHITE) {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::ROOK);
                    piece_is_taken(piece2->get_type());
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::ROOK);
                    return 1;
                }

            }
        case KNIGHT:
            //is a knight
            //white knights movement checker
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }

            //board checking it's not taking its own teammate
            else {
                if (colour2 == PieceColor::WHITE) {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KNIGHT);
                    piece_is_taken(piece2->get_type());
                    std::cout << "haha i have taken";
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KNIGHT);
                    return 1;
                }
            }
            break;
        case BISHOP:
            //is a bishop
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == PieceColor::WHITE) {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::BISHOP);
                    piece_is_taken(piece2->get_type());
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::BISHOP);
                    return 1;
                }

            }
            //if it can move then the grid will update itself
            break;
        case QUEEN:
            //is a queen

            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == PieceColor::WHITE) {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::QUEEN);
                    piece_is_taken(piece2->get_type());
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::QUEEN);
                    return 1;
                }

            }
            break;

        case KING:
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }

            //if it can move then the grid will update itself
            else {
                if (colour2 == PieceColor::WHITE) {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KING);
                    piece_is_taken(piece2->get_type());
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KING);
                    return 1;
                }

            }
            break;


        case PAWN:
            //is a pawn
            //a good example of how grid asks pawn if it can move to a position
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }

            //if it can move then the grid will update itself
            else if (nrow == row + 1 && colour2 == WHITE && (ncol == col + 1 || ncol == col - 1)) {
                // Check if at last row
                if (nrow == 7) {  // Check if pawn has reached the last row
                    bool invalid = true;
                    int choice;  // Take input as an integer

                    while (invalid) {
                        std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen): ";
                        std::cin >> choice;

                        if (choice >= 1 && choice <= 4) {
                            pos = static_cast<PieceType>(choice);  // Convert integer to enum
                            invalid = false;
                        }
                        else {
                            std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                        }
                    }
                }
                updated_grid(row, col, nrow, ncol, piece, pos);
                piece_is_taken(piece2->get_type());
                return 1;
            }

            else {
                // bool funtion here to check if it at the last row and then ask the user what they want to change it to
                if (nrow == 7) {  // Check if pawn has reached the last row
                    bool invalid = true;
                    int choice;  // Take input as an integer

                    while (invalid) {
                        std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen): ";
                        std::cin >> choice;

                        if (choice >= 1 && choice <= 4) {
                            pos = static_cast<PieceType>(choice);  // Convert integer to enum
                            invalid = false;
                        }
                        else {
                            std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                        }
                    }
                }
                updated_grid(row, col, nrow, ncol, piece, pos);
            }
            break;
        }
    }
    else if (colour == WHITE) {

        //checking white
        switch (pos) {
        case PAWN:
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            else {
                //can it be attacking?
                if (nrow == row - 1 && colour2 == BLACK && (ncol == col + 1 || ncol == col - 1)) {
                    if (nrow == 7) {  // Check if pawn has reached the last row
                        bool invalid = true;
                        int choice;  // Take input as an integer

                        while (invalid) {
                            std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen): ";
                            std::cin >> choice;

                            if (choice >= 1 && choice <= 4) {
                                pos = static_cast<PieceType>(choice);  // Convert integer to enum
                                invalid = false;
                            }
                            else {
                                std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                            }
                        }
                    }
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type());
                    return 1;

                }
                else if (colour == WHITE || colour2 == BLACK) {
                    std::cout << "cant move there mate";
                    return 0;

                }
                else {
                    if (nrow == 7) {  // Check if pawn has reached the last row
                        bool invalid = true;
                        int choice;  // Take input as an integer

                        while (invalid) {
                            std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen): ";
                            std::cin >> choice;

                            if (choice >= 1 && choice <= 4) {
                                pos = static_cast<PieceType>(choice);  // Convert integer to enum
                                invalid = false;
                            }
                            else {
                                std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                            }
                        }
                    }
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }


            }
            //is a pawn
            break;
        case ROOK:
            //is a rook
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type());
                    return 1;
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }

            }
            break;
        case KNIGHT:
            //is a knight

            //white knights movement checker
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }

            //board checking it's not taking its own teammate
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2);
                    std::cout << "haha i have taken";
                    return 1;
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;

                }
            }
            break;
        case BISHOP:
            //is a bishop
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2);
                    return 1;
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }

            }
            break;
        case QUEEN:
            //is a queen
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2);
                    return 1;
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }

            }
            break;
        case KING:
            //is a king
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row, col)) {
                clkco = 0;
                return 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2);
                    return 1;
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;

                }
            }

            break;
        }
    }
    return 1;
}
int chessboard::updated_grid(int rowold, int colold, int rownew, int colnew, Piece* piece, PieceType type) {
    delete arr[rowold][colold];
    arr[rowold][colold] = nullptr;
    switch (type) {
    case PAWN:
        arr[rownew][colnew] = new Pawn(rownew, colnew, piece->get_colour());
        break;
    case ROOK:
        arr[rownew][colnew] = new Rook(rownew, colnew, piece->get_colour());
        break;
    case KNIGHT:
        arr[rownew][colnew] = new Knight(rownew, colnew, piece->get_colour());
        break;
    case QUEEN:
        arr[rownew][colnew] = new Queen(rownew, colnew, piece->get_colour());
        break;
    case BISHOP:
        arr[rownew][colnew] = new Bishop(rownew, colnew, piece->get_colour());
        break;
    case KING:
        arr[rownew][colnew] = new King(rownew, colnew, piece->get_colour());
        break;
    }
    clkco = 0;
    return 0;
}
void chessboard::printBoard() {
    std::cout << "\n    A    B    C    D    E    F    G    H\n  ----------------------------------------\n";
    for (int i = 0; i < 8; i++) {

        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; j++) {
            if (arr[i][j] == nullptr) {
                std::cout << "    |";
                continue;
            }
            else {
                Piece* piece = arr[i][j];
                PieceType pos = piece->get_type();
                if (piece->get_colour() == PieceColor::WHITE) {
                    if (pos == PieceType::PAWN) {
                        std::cout << " wp |";
                    }
                    else if (pos == PieceType::ROOK) {
                        std::cout << " wr |";
                    }
                    else if (pos == PieceType::KNIGHT) {
                        std::cout << " wn |";
                    }
                    else if (pos == PieceType::BISHOP) {
                        std::cout << " wb |";
                    }
                    else if (pos == PieceType::QUEEN) {
                        std::cout << " wq |";
                    }
                    else if (pos == PieceType::KING) {
                        std::cout << " wk |";
                    }

                }
                else {
                    if (pos == PieceType::PAWN) {
                        std::cout << " bp |";
                    }
                    else if (pos == PieceType::ROOK) {
                        std::cout << " br |";
                    }
                    else if (pos == PieceType::KNIGHT) {
                        std::cout << " bn |";
                    }
                    else if (pos == PieceType::BISHOP) {
                        std::cout << " bb |";
                    }
                    else if (pos == PieceType::QUEEN) {
                        std::cout << " bq |";
                    }
                    else if (pos == PieceType::KING) {
                        std::cout << " bk |";
                    }
                }
            }
        }
        std::cout << i + 1 << " \n |----------------------------------------\n";

    }
    std::cout << "    A    B    C    D    E    F    G    H";

};

bool chessboard::piece_is_taken(PieceType piecenum, PieceColor colour, Tile_color tile) {
    if (piecenum == ROOK) {
        rookco--;
        if (colour == WHITE) {
            wtaken--;
        }
        else {
            btaken--;
        }

    }
    else if (piecenum == KNIGHT) {
        knightco--;
        if (colour == WHITE) {
            wtaken--;
        }
        else {
            btaken--;
        }
    }
    else if (piecenum == BISHOP) {
        bishopco--;
        if (colour == WHITE) {
            wtaken--;
        }
        else {
            btaken--;
        }
        if (tile == WHITE_TILE) {
            w_tile_bishop--;
        }
        else {
            b_tile_bishop--;
        }
    }
    else if (piecenum == KING) {
        kingco--;
        if (colour == WHITE) {
            wtaken--;
        }
        else {
            btaken--;
        }
    }
    else if (piecenum == QUEEN) {
        queenco--;
        if (colour == WHITE) {
            wtaken--;
        }
        else {
            btaken--;
        }
    }
    else if (piecenum == PAWN) {
        if (colour == WHITE) {
            wptaken--;
            wtaken--;
        }
        else {
            bptaken--;
            btaken--;
        }
    }
    //absolutley fucking horrible way of checking that only bishops remain
    if (wptaken == 0 && bptaken == 0 && rookco == 0 && knightco == 0 && queenco == 0 && kingco == 0 && bishopco == 2 && w_tile_bishop == 1 && b_tile_bishop == 1) {
        return true;
    }
    else if (wptaken == 0 && bptaken == 0 && rookco == 0 && knightco == 0 && queenco == 0 && kingco == 2 && bishopco == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool chessboard::is_white_gone() {
    if (wtaken == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool chessboard::is_black_gone() {
    if (btaken == 0) {
        return true;
    }
    else {
        return false;
    }
}


int chessboard::cantake(bool wplaying, bool bplaying) {
    std::vector<Piece*> wpieces;
    std::vector<Piece*> bpieces;
    for (int i = 0; i <= 15; i++) {
        for (int j = 0; j <= 15; j++) {
            if (this->arr[i][j] != nullptr) {
                if (this->arr[i][j]->get_colour() == WHITE) {
                    wpieces.push_back(this->arr[i][j]);
                }
                else if (this->arr[i][j]->get_colour() == BLACK) {
                    bpieces.push_back(this->arr[i][j]);
                }
            }

        }
    }
    if (wplaying) {
        for (int i = 0; i <= wpieces.size(); i++) {
            for (int j = 0; j <=bpieces.size() ; j++) {
                int bx, by;
                std::tie(bx, by) = bpieces.at(j)->get_pos();
                if (wpieces.at(i)->check_movement(bx, by)) {
                    return 0;
                }
            }
        }
    }
    if (bplaying) {
        for (int i = 0; i <= bpieces.size(); i++) {
            for (int j = 0; j <= wpieces.size(); j++) {
                int wx, wy;
                 std::tie(wx,wy)= wpieces.at(j)->get_pos();
                 if (bpieces.at(i)->check_movement(wx, wy)) {
                     return 0;
                }
            }

        }
        
    }
    return 1;
}
