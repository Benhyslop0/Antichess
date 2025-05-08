#include "chessboard.h"
//----------------------------------------------------------------
//standard libraries needed for the code to run
#include <iostream>
#include <stdio.h>
//---------------------------------------------------------------
// when do we use vectors? is this needed for tie function?
#include <vector>
//what the frick is tuple?
#include <tuple>
//----------------------------------------------------------------
//takes user input calls grid pressed function takes from and to moves
int chessboard::grid_pressed(int row, int col, int nrow, int ncol, bool wplaying, bool bplaying) {
    //--------------------------------------------------------------
    //gets all the attributes of the piece at the declared location that the user is moving from
    Piece* piece = arr[row][col];
    if (piece == nullptr) {
        return 0;
    }
    PieceColor colour = piece->get_colour();
    PieceType pos = piece->get_type();

    Piece* piece2 = arr[nrow][ncol];
    PieceColor colour2;
    if (piece2 == nullptr) {
        colour2 = PieceColor::NONE_COLOR;
    }
    else {
        colour2 = piece2->get_colour();
    }
    //--------------------------------------------------------------------
    //makes sure its their piece
    if (wplaying == true && colour == BLACK) {
        return 0;
    }
    else if (bplaying == true && colour == WHITE) {

        return 0;
    }
    //--------------------------------------------------------------
    BoardAware* boardAwarePiece = nullptr; // need to make here so its in the scope of the switch statement
    //checking black
    if (colour == BLACK) {
        switch (pos) {
        case ROOK:
            //dynamic casting into a board aware piece
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            
            else {
                //need a checker if its a take to sort out the draw checkers
                if (colour2 == PieceColor::WHITE) {
                    //need a second check for the bishop to check other draw conditions
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                //if the same itll stop move completely
                else if (colour2 == PieceColor::BLACK) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::ROOK);
                    return 1;
                }

            }
        case KNIGHT:
            if (!piece->check_movement(nrow, ncol)) {
                return 0;
            }
            //board checking it's not taking its own teammate
            else {
                if (colour2 == PieceColor::WHITE) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                        //I DONT KNOW WHY BUT A BUG IS APPEARING HERE
                        std::cout << " ";
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KNIGHT);
                    return 1;
                }
            }
            break;
        case BISHOP:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (colour2 == PieceColor::WHITE) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::BISHOP);
                    return 1;
                }

            }
            break;
        case QUEEN:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (colour2 == PieceColor::WHITE) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::QUEEN);
                    return 1;
                }
            }
            break;
        case KING:
            if (!piece->check_movement(nrow, ncol)) {
                return 0;
            }
            else {
                if (colour2 == PieceColor::WHITE) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == PieceColor::BLACK) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, PieceType::KING);
                    return 1;
                }
            }
            break;


        case PAWN:
            //a good example of how grid asks pawn if it can move to a position
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else if (nrow == row + 1 && colour2 == WHITE && (ncol == col + 1 || ncol == col - 1)) {
                // Check if at last row
                if (nrow == 7) {  
                    bool invalid = true;
                    // Take input as an integer but still has to be converted to enum
                    int choice;  
                    while (invalid) {
                        std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen, 5: King): ";
                        std::cin >> choice;
                        if (choice >= 1 && choice <= 5) {
                            // Convert integer to enum, took a while to realise this was needed
                            pos = static_cast<PieceType>(choice);  
                            invalid = false;
                            switch(choice) {
                                    case 1:
                                        brookco++;
                                        break;
                                    case 2:
                                        bkingco++;
                                        break;
                                    case 3:
                                       bbishopco++;
                                        break;
                                    case 4:
                                        bqueenco++;
                                        break;
                                    case 5:
                                        bkingco++;
                                        break;
                                }
                                bptaken--;
                        }
                        else {
                            std::cout << "Invalid choice! Please enter 1, 2, 3, 4 or 5.\n";
                        }
                    }
                }
                if(piece2->get_type() == PieceType::BISHOP) {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type(), colour2);
                }
                return 1;
            }

            else {
                if (nrow == 7) {  
                    bool invalid = true;
                    int choice;  
                    while (invalid) {
                        std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen, 5: King): ";
                        std::cin >> choice;
                        if (choice >= 1 && choice <= 5) {
                            pos = static_cast<PieceType>(choice); 
                            invalid = false;
                            switch(choice) {
                                case 1:
                                    brookco++;
                                    break;
                                case 2:
                                    bkingco++;
                                    break;
                                case 3:
                                   bbishopco++;
                                    break;
                                case 4:
                                    bqueenco++;
                                    break;
                                case 5:
                                    bkingco++;
                                    break;
                            }
                            bptaken--;
                        }
                        else {
                            std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                        }
                    }
                }
                updated_grid(row, col, nrow, ncol, piece, pos);
                return 1;
            }
            return 0;
            break;
        }
    }
    //checking white
    //do not in any way touch the brackets. 
    // i will enphazise this greatly. I spent more time trying to fix this than i care to admit
    else if (colour == WHITE) {
        switch (pos) {
        case PAWN:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (nrow == row - 1 && colour2 == BLACK && (ncol == col + 1 || ncol == col - 1)) {
                    if (nrow == 0) {  
                        bool invalid = true;
                        int choice;  
                        while (invalid) {
                            std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen, 5: King): ";
                            std::cin >> choice;
                            if (choice >= 1 && choice <= 5) {
                                pos = static_cast<PieceType>(choice);  
                                invalid = false;
                                switch(choice) {
                                    case 1:
                                        wrookco++;
                                        break;
                                    case 2:
                                        wkingco++;
                                        break;
                                    case 3:
                                       wbishopco++;
                                        break;
                                    case 4:
                                        wqueenco++;
                                        break;
                                    case 5:
                                        wkingco++;
                                        break;
                                }
                                wptaken--;
                            }
                            else {
                                std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                            }
                        }
                    }
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;

                }
                else if (colour2 == WHITE || colour2 == BLACK) {
                    return 0;
                }
                else {
                    if (nrow == 0) {  
                        bool invalid = true;
                        int choice;  
                        while (invalid) {
                            std::cout << "Promote to (1: Rook, 2: Knight, 3: Bishop, 4: Queen, 5: King): ";
                            std::cin >> choice;
                            if (choice >= 1 && choice <= 4) {
                                pos = static_cast<PieceType>(choice);  
                                invalid = false;
                                switch(choice) {
                                    case 1:
                                        wrookco++;
                                        break;
                                    case 2:
                                        wkingco++;
                                        break;
                                    case 3:
                                       wbishopco++;
                                        break;
                                    case 4:
                                        wqueenco++;
                                        break;
                                    case 5:
                                        wkingco++;
                                        break;
                                }
                                wptaken--;
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
            break;
        case ROOK:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (colour2 == BLACK) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == WHITE) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }
            }
            break;
        case KNIGHT:
            if (!piece->check_movement(nrow, ncol)) {
                return 0;
            }
            else {
                if (colour2 == BLACK) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == WHITE) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }
            }
            break;
        case BISHOP:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (colour2 == BLACK) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == WHITE) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }
            }
            break;
        case QUEEN:
            boardAwarePiece = dynamic_cast<BoardAware*>(piece);
            if (!boardAwarePiece->check_movement(nrow, ncol, this)) {
                return 0;
            }
            else {
                if (colour2 == BLACK) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == WHITE) {
                    return 0;
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    return 1;
                }

            }
            break;
        case KING:
            if (!piece->check_movement(nrow, ncol)) {
                return 0;
            }
            else {
                if (colour2 == BLACK) {
                    if(piece2->get_type() == PieceType::BISHOP) {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2, piece2->get_tile_color());
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece, pos);
                        piece_is_taken(piece2->get_type(), colour2);
                    }
                    return 1;
                }
                else if (colour2 == WHITE) {
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
    PieceColor pieceColor = piece->get_colour();
    delete arr[rowold][colold];
    arr[rowold][colold] = nullptr;
    delete arr[rownew][colnew];
    switch (type) {
    case PAWN:
        arr[rownew][colnew] = new Pawn(rownew, colnew, pieceColor);
        break;
    case ROOK:
        arr[rownew][colnew] = new Rook(rownew, colnew, pieceColor);
        break;
    case KNIGHT:
        arr[rownew][colnew] = new Knight(rownew, colnew, pieceColor);
        break;
    case QUEEN:
        arr[rownew][colnew] = new Queen(rownew, colnew, pieceColor);
        break;
    case BISHOP:
        arr[rownew][colnew] = new Bishop(rownew, colnew, pieceColor, piece->get_tile_color());
        break;
    case KING:
        arr[rownew][colnew] = new King(rownew, colnew, pieceColor);
        break;
    }
    return 0;
}
//---------------------------------------------------------------
void chessboard::printBoard(bool wplaying, bool bplaying) {
    //tells terminal how to display board using nested loops decides what to print for each space based on if statements and whats there
    if (wplaying) {
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
    }
    if (bplaying) {
        //letters must be inversed
        std::cout << "\n    H    G    F    E    D    C    B    A\n  ----------------------------------------\n";
        for (int i = 7; i >= 0; i--) {
            //inverse of original board to display the black side of the board
            std::cout << i + 1 << "|";
            for (int j = 7; j >= 0; j--) {
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
        std::cout << "    H    G    F    E    D    C    B    A";
    }
};
//------------------------------------------------
bool chessboard::piece_is_taken(PieceType piecenum, PieceColor colour, Tile_color tile) {
    // Handle all piece types first based on color
    if (colour == WHITE) {
        switch (piecenum) {
            case ROOK:    wrookco--;  break;
            case KNIGHT: wknightco--; break;
            case BISHOP:  wbishopco--; break;
            case QUEEN:   wqueenco--;  break;
            case KING:    wkingco--;   break;
            case PAWN:    wptaken--;   break;
            default: break;
        }
        wtaken--; 
    } 
    else if (colour == BLACK) {
        switch (piecenum) {
            case ROOK:    brookco--;  break;
            case KNIGHT: bknightco--; break;
            case BISHOP:  bbishopco--; break;
            case QUEEN:   bqueenco--;  break;
            case KING:    bkingco--;  break;
            case PAWN:    bptaken--;  break;
            default: break;
        }
        btaken--; 
    }
    // Special handling for bishops tile colors
    if (piecenum == BISHOP) {
        if (tile == WHITE_TILE) {
            w_tile_bishop--;
        } 
        else if (tile == BLACK_TILE) {
            b_tile_bishop--;
        }
    }
    if (wptaken == 0 && bptaken == 0 && wrookco == 0 && brookco == 0 && 
        wknightco == 0 && bknightco == 0 && bqueenco == 0 && wqueenco == 0 && 
        wkingco == 0 && bkingco == 0 && wbishopco == 1 && bbishopco == 1 && 
        w_tile_bishop == 1 && b_tile_bishop == 1) {
        return true;
    } 
    else if (wptaken == 0 && bptaken == 0 && wrookco == 0 && brookco == 0 && 
             wknightco == 0 && bknightco == 0 && bqueenco == 0 && wqueenco == 0 && 
             wkingco == 1 && bkingco == 1 && wbishopco == 0 && bbishopco == 0 ) {
        return true;
    } 
    else {
        return false;
    }
}
//-----------------------------------------------
bool chessboard::is_white_gone() {
    if (wtaken == 0) {
        return true;
    }
    else {
        return false;
    }
}
//-----------------------------------------------
bool chessboard::is_black_gone() {
    if (btaken == 0) {
        return true;
    }
    else {
        return false;
    }
}
//-----------------------------------------------
int chessboard::nomoves(bool wplaying, bool bplaying) {
    BoardAware* piece;
    int row1, col;
    bool check = false;
    if (bplaying) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (this->arr[i][j] != nullptr && this->arr[i][j]->get_colour() == BLACK && this->arr[i][j]->get_type() == PAWN) {
                    //first had to cast to board aware to get the position of the piece
                    piece = dynamic_cast<BoardAware*>(this->arr[i][j]);
                    row1 = piece->get_pos().first + 1;
                    col = piece->get_pos().second;
                    //also since pawn check movemnet expects a pointer to the board class i had to pass "this" in
                    //instead of returning i have a boolean checker to put in a if statement
                    if (piece->check_movement(row1, col, this)) {
                        check = true;
                    }
                    if (piece->check_movement(row1, col + 1, this)) {
                        check = true;
                    }
                    if (piece->check_movement(row1, col - 1, this)) {
                        check = true;
                    }
                }
            }
        }
        //without this check it would return draw in the event no pawns can move
        if(check == false && brookco == 0 && bknightco == 0 && bqueenco == 0 && bkingco == 0 && bbishopco == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (wplaying) {
        //same changes as in black
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (this->arr[i][j] != nullptr && this->arr[i][j]->get_colour() == WHITE && this->arr[i][j]->get_type() == PAWN) {

                    piece = dynamic_cast<BoardAware*>(this->arr[i][j]);
                    row1 = piece->get_pos().first - 1;
                    col = piece->get_pos().second;

                    if (piece->check_movement(row1, col, this)) {
                        check = true;
                    }
                    if (piece->check_movement(row1, col + 1, this)) {
                        check = true;
                        //return 0;
                    }
                    if (piece->check_movement(row1, col - 1, this)) {
                        check = true;
                    }
                }
            }
        }
        if(check == false && wrookco == 0 && wknightco == 0 && wqueenco == 0 && wkingco == 0 && wbishopco == 0) {
            return 1;
        }
        else {
            //remind me to delete before submitting
            std::cout << "wrookco: " << wrookco << "\nwknightco: " << wknightco <<"\nwqueenco: " << wqueenco<<"\nwkingco: " << wkingco<<"\nwbishopco: " << wbishopco;
            return 0;
        }
    } 
}
//------------------------------------------------
int chessboard::cantake(bool wplaying, bool bplaying) {
    std::vector<Piece*> wpieces;
    std::vector<Piece*> bpieces;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (this->arr[i][j] != nullptr) {
                if (this->arr[i][j]->get_colour() == WHITE) {
                    wpieces.push_back(this->arr[i][j]);
                }
                if (this->arr[i][j]->get_colour() == BLACK) {
                    bpieces.push_back(this->arr[i][j]);
                };
            }
        }
    }
    if (wplaying and !wpieces.empty() and !bpieces.empty()) {
        for (int i = 0; i < wpieces.size(); i++) {
            for (int j = 0; j < bpieces.size(); j++) {
                int bx, by;
                std::tie(bx, by) = bpieces[j]->get_pos();
                PieceType type = wpieces.at(i)->get_type();
                if (type == KING or type == KNIGHT) {
                    if (wpieces.at(i)->check_movement(bx, by)) {
                        //setting variables to show what piece can take what
                        std::tie(move_from_x, move_from_y) = wpieces.at(i)->get_pos();
                        need_to_move_x = bx;
                        need_to_move_y = by;
                        return 1;
                    }
                }
                if (type == QUEEN or type == BISHOP or type == ROOK or type == PAWN) {
                    BoardAware* boardAwarePiece = dynamic_cast<BoardAware*>(wpieces.at(i));
                    if (boardAwarePiece->check_movement(bx, by, this)) {
                        std::tie(move_from_x, move_from_y) = wpieces.at(i)->get_pos();
                        need_to_move_x = bx;
                        need_to_move_y = by;
                        return 1;
                    }
                }
            }
        }
    }
    if (bplaying and !bpieces.empty() and !wpieces.empty()) {
        for (int i = 0; i < bpieces.size(); i++) {
            for (int j = 0; j < wpieces.size(); j++) {
                int wx, wy;
                std::tie(wx, wy) = wpieces[j]->get_pos();
                PieceType type = bpieces.at(i)->get_type();
                if (type == KING or type == KNIGHT) {
                    if (bpieces.at(i)->check_movement(wx, wy)) {
                        std::tie(move_from_x, move_from_y) = bpieces.at(i)->get_pos();
                        need_to_move_x = wx;
                        need_to_move_y = wy;
                        return 1;
                    }
                }
                if (type == QUEEN or type == BISHOP or type == ROOK or type == PAWN) {
                    BoardAware* boardAwarePiece = dynamic_cast<BoardAware*>(bpieces.at(i));
                    if (boardAwarePiece->check_movement(wx, wy, this)) {
                        std::tie(move_from_x, move_from_y) = bpieces.at(i)->get_pos();
                        need_to_move_x = wx;
                        need_to_move_y = wy;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
//------------------------------------------------
int chessboard::return_needed_x() {
    return need_to_move_x;
}
int chessboard::return_needed_y() {
    return need_to_move_y;
}
int chessboard::return_move_from_x() {
    return move_from_x;
}
int chessboard::return_move_from_y() {
    return move_from_y;
}
//------------------------------------------------
