#pragma once

#include <utility>

class chessboard;
//enumerated types on each attribute makes code asier and readable
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
    NONE_TILE
};

class Piece {

protected:
    std::pair<int, int> cur_pos;
    PieceType type;
    PieceColor colour;
public:
    Piece(int x, int y, PieceColor colour, PieceType type) : cur_pos(x, y), type(type), colour(colour) {};
    std::pair<int, int> get_pos();
    PieceType get_type();
    PieceColor get_colour();
    void set_pos(int x, int y);
    virtual bool check_movement(int x, int y) = 0;
    virtual ~Piece() {};
};


//separate board aware class derives from piece this is for pieces that need to know the spaces around them on the board to check moves
class BoardAware : public Piece {
public:
    BoardAware(int x, int y, PieceColor colour, PieceType type) : Piece(x, y, colour, type) {};

    // Override both methods properly
    bool check_movement(int x, int y) override {
        return check_movement(x, y, nullptr);  // Calls the three-arg version
    }

    virtual bool check_movement(int x, int y, chessboard* brd) = 0;
};

class Pawn : public BoardAware {
public:
    Pawn(int x, int y, PieceColor colour) : BoardAware(x, y, colour, PieceType::PAWN) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Rook : public BoardAware {
public:
    Rook(int x, int y, PieceColor colour) : BoardAware(x, y, colour, PieceType::ROOK) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Knight : public Piece {
public:
    Knight(int x, int y, PieceColor colour) : Piece(x, y, colour, PieceType::KNIGHT) {};
    bool check_movement(int x, int y) override;
};

class Queen : public BoardAware {
public:
    Queen(int x, int y, PieceColor colour) : BoardAware(x, y, colour, PieceType::QUEEN) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class Bishop : public BoardAware {
public:
    Bishop(int x, int y, PieceColor colour) : BoardAware(x, y, colour, PieceType::BISHOP) {};
    bool check_movement(int x, int y, chessboard* brd) override;
};

class King : public Piece {
public:
    King(int x, int y, PieceColor colour) : Piece(x, y, colour, PieceType::KING) {};
    bool check_movement(int x, int y) override;
};