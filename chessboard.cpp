#include "chessboard.h"
#include <iostream>
#include <stdio.h>



//checking for what piece has been clicked

int chessboard::grid_pressed(int row, int col, int nrow, int ncol, bool bplaying,bool wplaying) {
    
    Piece* piece = arr[row][col];
    PieceColor colour = piece->get_colour();
    PieceType pos = piece->get_type();

    Piece* piece2 = arr[nrow][ncol];
    PieceColor colour2 = piece2->get_colour();
    
    if (wplaying == true && colour == BLACK) {
        std::cout << "Not your piece!";
        return 0;
    }
    else if (bplaying == true && colour == WHITE) {
        std::cout << "Not your piece!";
        return 0;
    }
    //checking black
    if(colour == BLACK){
        switch (pos) {
    
            case ROOK:
                //is a rook
                //if not nothing happens and the user can try again although am having issues with updating currow
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
                }
                //if it can move then the grid will update itself
                else {
                    if (colour2 == PieceColor::WHITE) {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::ROOK);
                        piece_is_taken(piece2->get_type());
                        return 1;
                    }
                    else if (colour2 == PieceColor::BLACK) {
                        std::cout << "cant move there mate";
                        return 0;
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::ROOK);
                        return 1;
                    }

                }
            case KNIGHT:
                //is a knight
                //white knights movement checker
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
                }

                //board checking it's not taking its own teammate
                else {
                    if (colour2 == PieceColor::WHITE) {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::KNIGHT);
                        piece_is_taken(piece2->get_type());
                        std::cout << "haha i have taken";
                        return 1;
                    }
                    else if (colour2 == PieceColor::BLACK) {
                        std::cout << "cant move there mate";
                        return 0;
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::KNIGHT);
                        return 1;
                    }
                }
                break;
            case BISHOP:
                //is a bishop
                //if not nothing happens and the user can try again although am having issues with updating currow
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
                }
                //if it can move then the grid will update itself
                else {
                    if (colour2 == PieceColor::WHITE) {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::BISHOP);
                        piece_is_taken(piece2->get_type());
                        return 1;
                    }
                    else if (colour2 == PieceColor::BLACK) {
                        std::cout << "cant move there mate";
                        return 0;
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::BISHOP);
                        return 1;
                    }

                }
                //if it can move then the grid will update itself
                break;
            case QUEEN:
                //is a queen
                
                //if not nothing happens and the user can try again although am having issues with updating currow
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
                }
                //if it can move then the grid will update itself
                else {
                    if (colour2 == PieceColor::WHITE) {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::QUEEN);
                        piece_is_taken(piece2->get_type());
                        return 1;
                    }
                    else if (colour2 == PieceColor::BLACK) {
                        std::cout << "cant move there mate";
                        return 0;
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::QUEEN);
                        return 1;
                    }

                }
                break;
                
            case KING:
                //if not nothing happens and the user can try again although am having issues with updating currow
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
                }

                //if it can move then the grid will update itself
                else {
                    if (colour2 == PieceColor::WHITE) {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::KING);
                        piece_is_taken(piece2->get_type());
                        return 1;
                    }
                    else if (colour2 == PieceColor::BLACK) {
                        std::cout << "cant move there mate";
                        return 0;
                    }
                    else {
                        updated_grid(row, col, nrow, ncol, piece,PieceType::KING);
                        return 1;
                    }

                }
                break;
                

            case PAWN:
                //is a pawn
                //a good example of how grid asks pawn if it can move to a position
                if (!piece->check_movement(row,col)) {
                    clkco = 0;
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
                                } else {
                                    std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                                }
                            }
                        }
                        updated_grid(row, col, nrow, ncol, piece,pos);
                        piece_is_taken(piece2->get_type());
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
                                } else {
                                    std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                                }
                                }
                            }
                            updated_grid(row, col, nrow, ncol,piece, pos);
                        }
                break;
            }
        }
    else if(colour == WHITE){
    
    //checking white
        switch (pos) {
        case PAWN:
            if (!piece->check_movement(row,col)) {
                clkco = 0;
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
                            } else {
                                std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                            }
                            }
                        }
                    updated_grid(row, col, nrow, ncol, piece, pos);
                    piece_is_taken(piece2->get_type());

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
                            } else {
                                std::cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
                            }
                            }
                        }
                    updated_grid(row, col, nrow, ncol, piece, pos);
                }


            }
            //is a pawn
            break;
        case ROOK:
            //is a rook
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row,col)) {
                clkco = 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                    piece_is_taken(piece2->get_type());
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                }
                else {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                }

            }
            break;
        case KNIGHT:
            //is a knight
            
            //white knights movement checker
            if (!piece->check_movement(row,col)) {
                clkco = 0;
            }

            //board checking it's not taking its own teammate
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                    piece_is_taken(piece2->get_type(),colour2);
                    std::cout << "haha i have taken";
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                }
                else {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                }
            }
            break;
        case BISHOP:
            //is a bishop
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row,col)) {
                clkco = 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                    piece_is_taken(piece2->get_type(),colour2);
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                }
                else {
                    updated_grid(row, col, nrow, ncol,piece, pos);
                }

            }
            break;
        case QUEEN:
            //is a queen
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row,col)) {
                clkco = 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece,pos);
                    piece_is_taken(piece2->get_type(),colour2);
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece,pos);
                }

            }
            break;
        case KING:
            //is a king
            //if not nothing happens and the user can try again although am having issues with updating currow
            if (!piece->check_movement(row,col)) {
                clkco = 0;
            }
            //if it can move then the grid will update itself
            else {
                if (colour2 == BLACK) {
                    updated_grid(row, col, nrow, ncol, piece,pos);
                    piece_is_taken(piece2->get_type(),colour2);
                }
                else if (colour2 == WHITE) {
                    std::cout << "cant move there mate";
                }
                else {
                    updated_grid(row, col, nrow, ncol, piece,pos);

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
    switch(type){
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
            if(arr[i][j] == nullptr){
                std::cout << "    |";
                continue;
            }
            else{
                Piece* piece = arr[i][j];
                PieceType pos = piece->get_type();
                if(piece->get_colour() == PieceColor::WHITE){
                    if(pos == PieceType::PAWN){
                        std::cout << " wp |";
                    }
                    else if(pos == PieceType::ROOK){
                        std::cout << " wr |";
                    }
                    else if(pos == PieceType::KNIGHT){
                        std::cout << " wn |";
                    }
                    else if(pos == PieceType::BISHOP){
                        std::cout << " wb |";
                    }
                    else if(pos == PieceType::QUEEN){
                        std::cout << " wq |";
                    }
                    else if(pos == PieceType::KING){
                        std::cout << " wk |";
                    }
                    
                }
                else{
                    if(pos == PieceType::PAWN){
                        std::cout << " bp |";
                    }
                    else if(pos == PieceType::ROOK){
                        std::cout << " br |";
                    }
                    else if(pos == PieceType::KNIGHT){
                        std::cout << " bn |";
                    }
                    else if(pos == PieceType::BISHOP){
                        std::cout << " bb |";
                    }
                    else if(pos == PieceType::QUEEN){
                        std::cout << " bq |";
                    }
                    else if(pos == PieceType::KING){
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
    if (piecenum == ROOK){
        rookco--;
        if(colour == WHITE){
            wtaken--;
        }
        else{
            btaken--;
        }
        
    }
    else if (piecenum == KNIGHT){
        knightco--;
        if(colour == WHITE){
            wtaken--;
        }
        else{
            btaken--;
        }
    }
    else if (piecenum == BISHOP){
        bishopco --;
        if(colour == WHITE){
            wtaken--;
        }
        else{
            btaken--;
        }
        if(tile == WHITE_TILE){
            w_tile_bishop--;
        }
        else{
            b_tile_bishop--;
        }
    }
    else if (piecenum == KING){
        kingco--;
        if(colour == WHITE){
            wtaken--;
        }
        else{
            btaken--;
        }
    }
    else if (piecenum == QUEEN){
        queenco--;
        if(colour == WHITE){
            wtaken--;
        }
        else{
            btaken--;
        }
    }
    else if (piecenum == PAWN){
        if(colour == WHITE){
            wptaken--;
            wtaken--;
        }
        else{
            bptaken--;
            btaken--;
        }
    }
    //absolutley fucking horrible way of checking that only bishops remain
    if(wptaken == 0 && bptaken == 0 && rookco == 0 && knightco == 0 && queenco == 0 && kingco == 0 && bishopco == 2 && w_tile_bishop == 1 && b_tile_bishop == 1){
        return true;
    }
    else if(wptaken == 0 && bptaken == 0 && rookco == 0 && knightco == 0 && queenco == 0 && kingco == 2 && bishopco == 0){
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





/*bool chessboard::cantake(bool wturn, bool bturn) {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            int pos = brd.arr[i][j];
            if (bturn == true and pos >= 1 and pos <= 6) {
                for (int k = 0; k <= 7; k++) {
                    for (int l = 0; l <= 7; l++) {
                        if (brd.grid_noturn(i, j, k, l, brd) == 1 and brd.arr[k][l] >= 7) {
                            return true;
                        }
                    }
                }
            }
            else if (wturn == true and pos >= 7) {
                for (int k = 0; k <= 7; k++) {
                    for (int l = 0; l <= 7; l++) {

                        if (brd.grid_noturn(i, j, k, l, brd) == 1 and (brd.arr[k][l] >= 1 and brd.arr[k][l] <= 6)){
                            return true;
                        }   
                    }
                }
            }
        }
    }
    std::cout << "returned false";
    return false;
}

int chessboard::grid_noturn(int row, int col, int nrow, int ncol, chessboard board) {
=======
int chessboard::grid_pressed(int row, int col, int nrow, int ncol, chessboard board,bool bplaying,bool wplaying) {
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
    Pawn p;
    Queen q;
    King k;
    Bishop b;
    Rook r;
    Knight n;
    bool wthere = false;
    bool bthere = false;
    int pos = arr[row][col];
    int en = arr[nrow][ncol];



    for (int i = 1; i <= 6; i++) {
        if (i == en) {
            bthere = true;
        }
    }
    for (int i = 7; i <= 12; i++) {
        if (i == en) {
            wthere = true;
        }
    }
<<<<<<< HEAD
=======
    if (wplaying == true && pos > 6) {
        std::cout << "Not your piece!";
        return 0;
    }
    else if (bplaying == true && pos < 7) {
        std::cout << "Not your piece!";
        return 0;
    }
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
    //checking black
    switch (pos) {
    case 1:
        //is a rook
        r.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!r.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {

                return 1;
            }
            else if (bthere == true) {
                return 0;
            }
            else {

                return 1;
            }
        }
        break;
    case 2:
        //is a knight
        n.posassign(row, col, nrow, ncol);

        //white knights movement checker
        if (!n.movement()) {
            clkco = 0;
<<<<<<< HEAD
            return 0;
=======
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
        }

        //board checking it's not taking its own teammate
        else {
            if (bthere == true) {
<<<<<<< HEAD
                return 0;
            }
            else if (wthere == true) {
                return 1;
            }
            else {
                return 1;
=======
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
                std::cout << "haha i have taken";
            }
            else if (wthere == true) {
                std::cout << "cant move there mate";
            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
            }
        }
        break;
    case 3:
        //is a bishop
        b.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!b.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                return 1;
            }
            else if (bthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    case 4:
        //is a queen
        q.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!q.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                return 1;
            }
            else if (bthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
        //is queen
    case 5:
        k.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!k.movement()) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (wthere == true) {
                return 1;
            }
            else if (bthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
        //is a king

    case 6:
        //is a pawn
        //a good example of how grid asks pawn if it can move to a position
        p.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!p.movement(pos)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (nrow == row + 1 && wthere == true && (ncol == col + 1 || ncol == col - 1)) {
                return 1;
            }
            else if (wthere == true || bthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    }
    //checking white
    switch (pos) {
    case 7:
        p.posassign(row, col, nrow, ncol);
        if (!p.movement(pos)) {
            clkco = 0;
            return 0;
        }
        else {
            //can it be attacking?
            if (nrow == row - 1 && bthere == true && (ncol == col + 1 || ncol == col - 1)) {
<<<<<<< HEAD
                return 1;
=======
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
            }
            else if (wthere == true || bthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        //is a pawn
        break;
    case 8:
        //is a rook
        r.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!r.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
<<<<<<< HEAD
                return 1;
=======
                updated_grid(row, col, nrow, ncol, pos);
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
            }
            else if (wthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    case 9:
        //is a knight
        n.posassign(row, col, nrow, ncol);

        //white knights movement checker
        if (!n.movement()) {
            clkco = 0;
<<<<<<< HEAD
            return 0;
=======
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
        }

        //board checking it's not taking its own teammate
        else {
            if (bthere == true) {
<<<<<<< HEAD
                return 1;
            }
            else if (wthere == true) {
                return 0;
            }
            else {
                return 1;
=======
                updated_grid(row, col, nrow, ncol, pos);
                piece_is_taken(en);
                std::cout << "haha i have taken";
            }
            else if (wthere == true) {
                std::cout << "cant move there mate";
            }
            else {
                updated_grid(row, col, nrow, ncol, pos);
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
            }
        }
        break;
    case 10:
        //is a bishop
        b.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!b.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
<<<<<<< HEAD
                return 1;
=======
                updated_grid(row, col, nrow, ncol, pos);
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
            }
            else if (wthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    case 11:
        //is a queen
        q.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!q.movement(board)) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                return 1;
            }
            else if (wthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    case 12:
        //is a king
        k.posassign(row, col, nrow, ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if (!k.movement()) {
            clkco = 0;
            return 0;
        }
        //if it can move then the grid will update itself
        else {
            if (bthere == true) {
                return 1;
            }
            else if (wthere == true) {
                return 0;
            }
            else {
                return 1;
            }
        }
        break;
    }

    return 0;
<<<<<<< HEAD
}*/
=======
}
int chessboard::updated_grid(int rowold, int colold, int rownew, int colnew, int piecenum) {

    arr[rowold][colold] = 0;
    arr[rownew][colnew] = piecenum;
    clkco = 0;
    return 0;
}
void chessboard::printBoard() {
    std::cout << "\n    A    B    C    D    E    F    G    H\n  ----------------------------------------\n";
    for (int i = 0; i < 8; i++) {

        std::cout << i + 1 << "|";
        for (int j = 0; j < 8; j++) {
            int pos = arr[i][j];
            switch (pos) {
            case 0:
                std::cout << "    |";
                break;
            case 1:
                std::cout << " br |";
                break;
            case 2:
                std::cout << " bn |";
                break;
            case 3:
                std::cout << " bb |";
                break;
            case 4:
                std::cout << " bq |";
                break;
            case 5:
                std::cout << " bk |";
                break;
            case 6:
                std::cout << " bp |";
                break;
            case 7:
                std::cout << " wp |";
                break;
            case 8:
                std::cout << " wr |";
                break;
            case 9:
                std::cout << " wn |";
                break;
            case 10:
                std::cout << " wb |";
                break;
            case 11:
                std::cout << " wq |";
                break;
            case 12:
                std::cout << " wk |";
                break;
            }
        }
        std::cout << i + 1 << " \n |----------------------------------------\n";

    }
    std::cout << "    A    B    C    D    E    F    G    H";

};


void chessboard::piece_is_taken(int piecenum) {
    if (piecenum == 1) {
        btaken--;
    }
    else if (piecenum == 2) {
        btaken--;
    }
    else if (piecenum == 3) {
        btaken--;
    }
    else if (piecenum == 4) {
        btaken--;
    }
    else if (piecenum == 5) {
        btaken--;
    }
    else if (piecenum == 6) {
        btaken--;
    }
    else if (piecenum == 7) {
        wtaken--;
    }
    else if (piecenum == 8) {
        wtaken--;
    }
    else if (piecenum == 9) {
        wtaken--;
    }
    else if (piecenum == 10) {
        wtaken--;
    }
    else if (piecenum == 11) {
        wtaken--;
    }
    else if (piecenum == 12) {
        wtaken--;
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

bool cantake(chessboard brd,bool bturn, bool wturn) {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            int pos = brd.arr[i][j];
            if (wturn == true && pos >= 1 and pos = < 6) {
                for (int k = 0; k <= 7; k++) {
                    for (int l = 0; l <= 7; l++) {
                        if(brd.grid_pressed(i,j,k, l, brd, wturn, bturn))
                       





                    }
                }
            }
        }
    }
}
>>>>>>> 95a4dadc6c3eefc19c4ebd181b80bb9e2b221abf
