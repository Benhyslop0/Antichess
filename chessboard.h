#pragma once
#include "pieces.h"
#include <iostream>

class chessboard
{
public:
    //8*8 default grid with all info in it on game start constructs all pieces on it aswell
    Piece* arr[8][8] = {
        {new Rook(0,0, PieceColor::BLACK), new Knight(0,1, PieceColor::BLACK), new Bishop(0,2, PieceColor::BLACK,Tile_color::WHITE_TILE),
         new Queen(0,3, PieceColor::BLACK), new King(0,4, PieceColor::BLACK), new Bishop(0,5, PieceColor::BLACK,Tile_color::BLACK_TILE),
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

        {new Rook(7,0, PieceColor::WHITE), new Knight(7,1, PieceColor::WHITE), new Bishop(7,2, PieceColor::WHITE,Tile_color::BLACK_TILE),
         new Queen(7,3, PieceColor::WHITE), new King(7,4, PieceColor::WHITE), new Bishop(7,5, PieceColor::WHITE,Tile_color::WHITE_TILE),
         new Knight(7,6, PieceColor::WHITE), new Rook(7,7, PieceColor::WHITE)}
    };
    //--------------------------------------------------------------------------------------------------------------------------------
    //this function is used to check if the player is trying to move a piece that they own or not
    //basically checks if the piece is the same color as the player and if the piece is not null
    //it also checks if the player is trying to move a piece that is not theirs
    int grid_pressed(int row, int col, int nrow, int ncol, bool wplaying, bool bplaying);
    //-------------------------------------------------------------------------------------------------------------------------------
    //this function is used to update the grid when a piece is moved from one location to another
    //it deletes the old piece and creates a new one in the new location
    int updated_grid(int rowold, int colold, int rownew, int colnew, Piece* piece, PieceType type);
    //-------------------------------------------------------------------------------------------------------------------------------
    //this function is used to print the board and the pieces on it in a readable format
    void printBoard(bool wplaying, bool bplaying);
    //------------------------------------------------------------------------------------------------------------------------------
    //wind conditions
    bool is_white_gone();
    bool is_black_gone();
    //-----------------------------------------------------------------------------------------------------------------------------
    //draw condition for if pawns can move or not
    // as well if pawns are the last pieces on the board
    int nomoves(bool wplaying, bool bplaying);
    //------------------------------------------------------------------------------------------------------------------------------
    //checks if the player can take a piece or not and wil force the player to make the move
    //this is either by returning 1 or 0 or giving the ai the position of the piece it needs to take and what piece it is taking
    int cantake(bool wplaying, bool bplaying);
    //continuously udpates the counters for draw conditions and checks for draw conditions
    bool piece_is_taken(PieceType type = NONE, PieceColor colour = NONE_COLOR, Tile_color tile = NONE_TILE);
    //----------------------------------------------------------------------------------------------------------------------------------
    int return_needed_x();
    int return_needed_y();
    int return_move_from_x();
    int return_move_from_y();
private:
    //-----------------------------------------------------------------------------------------------------------------
    //counters win conditions
    int wtaken = 16;
    int btaken = 16;
    //----------------------------------------------------------------------------------------------------------------
    //counters for draw conditions
    //only found in pawn scenarios in grid pressed function
    //as well found in piece is taken function and nomoves function
    int wptaken = 8, bptaken = 8;
    int wrookco = 2;
    int brookco = 2;
    int wknightco = 2;
    int bknightco = 2;
    int wqueenco = 1;
    int bqueenco = 1;
    int wkingco = 1;
    int bkingco = 1;
    int wbishopco = 2;
    int bbishopco = 2;
    int w_tile_bishop = 2;
    int b_tile_bishop = 2;
    //----------------------------------------------------------------------------------------------------------------
    //ai force move variables
    //theres are the variables that are used to force the ai to move a piece if it can capture another piece
    //changed in the cantake function
    int need_to_move_x;
    int need_to_move_y;
    int move_from_x;
    int move_from_y;
    //----------------------------------------------------------------------------------------------------------------
};
