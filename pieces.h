#pragma once

#include <utility>

class chessboard;

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

class BoardAware : public Piece {
    public:
    BoardAware(int x, int y, PieceColor colour, PieceType type) : Piece(x, y, colour, type) {};

    // Override both methods properly
    bool check_movement(int x, int y) override {
        return check_movement(x, y, nullptr);  // Calls the three-arg version
    }

    virtual bool check_movement(int x, int y, chessboard* brd) = 0;
};

class Pawn : public Piece {
    public:
        Pawn(int x, int y, PieceColor colour) : Piece(x, y,colour, PieceType::PAWN) {};
        bool check_movement(int x, int y) override;
};  

class Rook : public BoardAware{
    public:
        Rook(int x, int y, PieceColor colour) : BoardAware(x, y,colour, PieceType::ROOK) {};
        bool check_movement(int x, int y,chessboard* brd) override;
};

class Knight : public Piece {
    public:
        Knight(int x, int y, PieceColor colour) : Piece(x, y,colour, PieceType::KNIGHT) {};
        bool check_movement(int x, int y) override;
};

class Queen : public BoardAware {
    public:
        Queen(int x, int y, PieceColor colour) : BoardAware(x, y,colour, PieceType::QUEEN) {};
        bool check_movement(int x, int y,chessboard* brd) override;
};  

class Bishop : public BoardAware {
    public:
        Bishop(int x, int y, PieceColor colour) : BoardAware(x, y,colour, PieceType::BISHOP) {};
        bool check_movement(int x, int y,chessboard* brd) override;
};  

class King : public Piece {
    public:
        King(int x, int y, PieceColor colour) : Piece(x, y,colour, PieceType::KING) {};
        bool check_movement(int x, int y) override;
};

/*class Pawn
{
public:
    Pawn();
    void posassign(int cx, int cy, int nx, int ny);
    bool movement(int piecenum);
    bool row(int row);
private:
    int currow, curcol, wantrow, wantcol;

};


class King {
public:
    King();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};


class Queen {
public:
    Queen();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

class Rook {
public:
    Rook();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};

class Bishop {
public:
    Bishop();
    bool movement(chessboard brd);
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};



class Knight {
public:
    Knight();
    bool movement();
    void posassign(int cx, int cy, int nx, int ny);

private:
    int currow, curcol, wantrow, wantcol;
};*/