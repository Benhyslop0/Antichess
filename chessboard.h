#pragma once
#include "pieces.h"
#include <iostream>

class chessboard
{
public:

    Piece* arr[8][8] = {
        {new Rook(0,0, PieceColor::BLACK), new Knight(0,1, PieceColor::BLACK), new Bishop(0,2, PieceColor::BLACK),
         new Queen(0,3, PieceColor::BLACK), new King(0,4, PieceColor::BLACK), new Bishop(0,5, PieceColor::BLACK),
         new Knight(0,6, PieceColor::BLACK), new Rook(0,7, PieceColor::BLACK)},

        {new Pawn(1,0, PieceColor::BLACK), new Pawn(1,1, PieceColor::BLACK), new Pawn(1,2, PieceColor::BLACK),
         new Pawn(1,3, PieceColor::BLACK), new Pawn(1,4, PieceColor::BLACK), new Pawn(1,5, PieceColor::BLACK),
         new Pawn(1,6, PieceColor::BLACK), new Pawn(1,7, PieceColor::BLACK)},

        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},

        {new Pawn(6,0, PieceColor::WHITE), new Pawn(6,1, PieceColor::WHITE), new Pawn(6,2, PieceColor::WHITE),
         new Pawn(6,3, PieceColor::WHITE), new Pawn(6,4, PieceColor::WHITE), new Pawn(6,5, PieceColor::WHITE),
         new Pawn(6,6, PieceColor::WHITE), new Pawn(6,7, PieceColor::WHITE)},

        {new Rook(7,0, PieceColor::WHITE), new Knight(7,1, PieceColor::WHITE), new Bishop(7,2, PieceColor::WHITE),
         new Queen(7,3, PieceColor::WHITE), new King(7,4, PieceColor::WHITE), new Bishop(7,5, PieceColor::WHITE),
         new Knight(7,6, PieceColor::WHITE), new Rook(7,7, PieceColor::WHITE)}
    };
    /*t arr[8][8] = {
        {1,2,3,4,5,3,2,1},
        {6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {7,7,7,7,7,7,7,7},
        {8,9,10,11,12,10,9,8} //top is white (1-6),bottom is black (7-12),no mans land is defined by 0s
    };*/

    int grid_pressed(int row, int col, int nrow, int ncol, bool wplaying, bool bplaying);
    int updated_grid(int rowold, int colold, int rownew, int colnew, Piece* piece, PieceType type);
    void printBoard(bool wplaying, bool bplaying);
    bool is_white_gone();
    bool is_black_gone();

    int nomoves(bool wplaying, bool bplaying);

    int cantake(bool wplaying, bool bplaying);

    bool piece_is_taken(PieceType type = NONE, PieceColor colour = NONE_COLOR, Tile_color tile = NONE_TILE);



    //a function to print the board


private:
    int wtaken = 16;
    int btaken = 16;

    int wptaken = 8, bptaken = 8;
    int rookco = 4;
    int knightco = 4;
    int queenco = 2;
    int kingco = 2;
    int bishopco = 4;
    int w_tile_bishop = 2;
    int b_tile_bishop = 2;
    int clkco;
};