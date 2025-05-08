#include "pieces.h"
#include "chessboard.h"
#include <iostream>
#include <cmath>
std::pair<int, int> Piece::get_pos() {
    return cur_pos; //pair used to hold x and y coordinates of pieces
}

//getters and setters
void Piece::set_pos(int x, int y) {
    cur_pos.first = x;
    cur_pos.second = y;
}

PieceType Piece::get_type() {
    return type;
}

PieceColor Piece::get_colour() {
    return colour;
}

Tile_color Piece::get_tile_color() {
    return tile_color;
}
//movement checks
bool Pawn::check_movement(int x, int y, chessboard* brd) {
    if (colour == WHITE) {
        if (y == cur_pos.second && brd->arr[x][y] == nullptr) {
            if (x == cur_pos.first - 1) {
                return true;
            } //one move forward
            if (cur_pos.first == 6 && x == cur_pos.first - 2 && brd->arr[cur_pos.first - 1][y] == nullptr) {
                return true;
            }// 2 on first move
        }
        else if (x == cur_pos.first - 1 && (y == cur_pos.second - 1 || y == cur_pos.second + 1)) {
            if (brd->arr[x][y] != nullptr && brd->arr[x][y]->get_colour() == BLACK) {
                return true;
            } //diagonal if theres a piece there gridpressed protects from taking friendly pieces
        }
    }
    if (colour == BLACK) {
        if (y == cur_pos.second && brd->arr[x][y] == nullptr) {
            if (x == cur_pos.first + 1) {
                return true;
            }//one move down
            if (cur_pos.first == 1 && x == cur_pos.first + 2 && brd->arr[cur_pos.first + 1][y] == nullptr) {
                return true;
            }
        }//2 moves down on first turn
        else if (x == cur_pos.first + 1 && (y == cur_pos.second + 1 || y == cur_pos.second - 1)) {
            if (brd->arr[x][y] != nullptr && brd->arr[x][y]->get_colour() == WHITE) {
                return true;
            }
        }//diagonal
    }
    return false; //none of these met means invalid move
}

bool Rook::check_movement(int wantrow, int wantcol, chessboard* brd) {
    int start;
    int end;
    if (cur_pos.first != wantrow and cur_pos.second != wantcol) {
        return false;
    } //makes sure the move actually is in line before even bothering with the rest
    if (cur_pos.first == wantrow) {
        if (cur_pos.second < wantcol) {
            start = cur_pos.second + 1;
            end = wantcol;
        }
        else {
            start = wantcol + 1;
            end = cur_pos.second;
        }//checks spaces inbetween are blank initialises +1 to not mistake itself as a taken space
        for (int i = start; i < end; i++) {
            if (brd->arr[cur_pos.first][i] != nullptr) {
                return false;
            }//loop that follows through with checking the space inbetween
        }
        return true;
    }

    if (cur_pos.second == wantcol) {
        if (cur_pos.first < wantrow) {
            start = cur_pos.first + 1;
            end = wantrow;
        }//again checks blank spaces inbetween
        else {
            start = wantrow + 1;
            end = cur_pos.first;
        }

        for (int i = start; i < end; i++) {
            if (brd->arr[i][cur_pos.second] != nullptr) {
                return false;
            }//loop that goes through the spaces
        }
        return true;
    }

    return false;
}

bool Knight::check_movement(int wantrow, int wantcol) {
    int rowdiff = abs(cur_pos.first - wantrow);
    int coldiff = abs(cur_pos.second - wantcol);
    return ((rowdiff == 1 and coldiff == 2) or (rowdiff == 2 and coldiff == 1));
}// if the magnitude of these changes are a combination of a 1 and 2 between rows and columns its a valid move for a knight

int dir(int x) {
    if (x > 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
}//later used direction of movement function will pass both x and y changes into it to check this

bool Queen::check_movement(int wantrow, int wantcol, chessboard* brd) {
    int start;
    int end;
    if (cur_pos.first == wantrow) {
        if (cur_pos.second < wantcol) {
            start = cur_pos.second + 1;
            end = wantcol;
        }
        else {
            start = wantcol + 1;
            end = cur_pos.second;
        }
        for (int i = start; i < end; i++) {
            if (brd->arr[cur_pos.first][i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    if (cur_pos.second == wantcol) {
        if (cur_pos.first < wantrow) {
            start = cur_pos.first + 1;
            end = wantrow;
        }
        else {
            start = wantrow + 1;
            end = cur_pos.first;
        }

        for (int i = start; i < end; i++) {
            if (brd->arr[i][cur_pos.second] != nullptr) {
                return false;
            }
        }
        return true;
    }//rook code
    int drow = wantrow - cur_pos.first;
    int dcol = wantcol - cur_pos.second;
    if (abs(drow) == abs(dcol)) {
        int rowdir = dir(drow);
        int coldir = dir(dcol);

        for (int i = 1; i < abs(drow); i++) {
            int rowcheck = cur_pos.first + (i * rowdir);
            int colcheck = cur_pos.second + (i * coldir);
            if (brd->arr[rowcheck][colcheck] != nullptr) {
                return false;
            }
        }
        return true;
    }//bishop code
    return false;
}

bool Bishop::check_movement(int wantrow, int wantcol, chessboard* brd) {
    int drow = wantrow - cur_pos.first;
    int dcol = wantcol - cur_pos.second; //gets diff of rows and cols
    if (abs(drow) != abs(dcol)) {
        return false;
    }//similar to rook except makes sure its a diagonal move before continuing
    int rowdir = dir(drow);
    int coldir = dir(dcol);//calls direction functions
    for (int i = 1; i < abs(drow); i++) {
        int rowcheck = cur_pos.first + (i * rowdir);
        int colcheck = cur_pos.second + (i * coldir);
        if (brd->arr[rowcheck][colcheck] != nullptr) {
            return false;
        }
    }//iterates on that direction
    return true;
}

bool King::check_movement(int wantrow, int wantcol) {
    int drow = abs(cur_pos.first - wantrow);
    int dcol = abs(cur_pos.second - wantcol);
    // King can move exactly one square in any direction
    return ((drow <= 1 and dcol <= 1) and (drow >0 or dcol >0));
}