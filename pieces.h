#pragma once

#include <utility>
//need explained why this is here
class chessboard;
//-----------------------------------------------------------------------
//enumerated types on each attribute makes code easier and readable
enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    QUEEN,
    BISHOP,
    KING,
    NONE
};
enum PieceColor {
    WHITE,
    BLACK,
    NONE_COLOR
};
enum Tile_color {
    WHITE_TILE,
    BLACK_TILE,
    //every piece constructor has there tile color set to NONE_TILE except for bishops which is left undefined
    //set in the chessboard array
    NONE_TILE
};
//---------------------------------------------------------------------------
class Piece {
protected:
    //position of the piece on the board
    //pair is used to store the x and y coordinates of the piece on the board
    std::pair<int, int> cur_pos;
    //piece type and color
    PieceType type;
    PieceColor colour;
    //specifically only for bishops to check draw conditions
    Tile_color tile_color;
public:
    //constructor for the piece class
    Piece(int x, int y, PieceColor colour, PieceType type, Tile_color tile_color) 
        : cur_pos(x, y), type(type), colour(colour), tile_color(tile_color) {};
    //getters and setters for the piece class
    std::pair<int, int> get_pos();
    PieceType get_type();
    PieceColor get_colour();
    Tile_color get_tile_color();
    void set_pos(int x, int y);
    //movement checks for the pieces
    //changed in boardaware class to take in chessboard pointer
    virtual bool check_movement(int x, int y) = 0;
    //might not need this destructor but its here just in case
    virtual ~Piece() {};
};
//---------------------------------------------------------------------------
//separate board aware class derives from piece this is for pieces that need to know the spaces around them on the board to check moves
class BoardAware : public Piece {
public:
    BoardAware(int x, int y, PieceColor colour, PieceType type, Tile_color tile_color) 
        : Piece(x, y, colour, type, tile_color) {};
    virtual ~BoardAware() override = default;

    //only thing that needs changed is whats passed through to check movement
    bool check_movement(int x, int y) override {
        return check_movement(x, y, nullptr);
    }
    
    virtual bool check_movement(int x, int y, chessboard* brd) = 0;
};
//--------------------------------------------------------------------------------
//none of these classes need to be virtual as they are the same as the piece class
class Pawn : public BoardAware {
public:
    Pawn(int x, int y, PieceColor colour, Tile_color tile_color = NONE_TILE) 
        : BoardAware(x, y, colour, PieceType::PAWN, tile_color) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Rook : public BoardAware {
public:
    Rook(int x, int y, PieceColor colour, Tile_color tile_color = NONE_TILE) 
        : BoardAware(x, y, colour, PieceType::ROOK, tile_color) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Knight : public Piece {
public:
    Knight(int x, int y, PieceColor colour, Tile_color tile_color= NONE_TILE) 
        : Piece(x, y, colour, PieceType::KNIGHT, tile_color) {};
    bool check_movement(int x, int y) override;
};

class Queen : public BoardAware {
public:
    Queen(int x, int y, PieceColor colour, Tile_color tile_color = NONE_TILE) 
        : BoardAware(x, y, colour, PieceType::QUEEN, tile_color) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Bishop : public BoardAware {
public:
    Bishop(int x, int y, PieceColor colour, Tile_color tile_color) 
        : BoardAware(x, y, colour, PieceType::BISHOP, tile_color) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class King : public Piece {
public:
    King(int x, int y, PieceColor colour, Tile_color tile_color = NONE_TILE) 
        : Piece(x, y, colour, PieceType::KING, tile_color) {};
    bool check_movement(int x, int y) override;
};