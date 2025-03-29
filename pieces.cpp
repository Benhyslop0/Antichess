#include "pieces.h"
#include "chessboard.h"
#include <iostream>

std::pair<int, int> Piece::get_pos() {
    return cur_pos;
}

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

bool Pawn::check_movement(int x, int y, chessboard* brd) {
  //  std::cout << "check move";
    if (colour == WHITE) {
        if (y == cur_pos.second && brd->arr[x][y] == nullptr) {
            if (x == cur_pos.first - 1) {
                return true;
            }
            if (cur_pos.first == 6 && x == cur_pos.first - 2 && brd->arr[cur_pos.first - 1][y] == nullptr) {
                return true;
            }
        }
        else if (x == cur_pos.first - 1 && (y == cur_pos.second - 1 || y == cur_pos.second + 1)) {
            if (brd->arr[x][y] != nullptr && brd->arr[x][y]->get_colour() == BLACK) {
                return true;
            }
        }
    }
    if (colour == BLACK) {
        if (y == cur_pos.second && brd->arr[x][y] == nullptr) {
            if (x == cur_pos.first + 1) {
                return true;
            }
            if (cur_pos.first == 1 && x == cur_pos.first + 2 && brd->arr[cur_pos.first + 1][y] == nullptr) {
                return true;
            }
        }
        else if (x == cur_pos.first + 1 && (y == cur_pos.second + 1 || y == cur_pos.second - 1)) {
            if (brd->arr[x][y] != nullptr && brd->arr[x][y]->get_colour() == WHITE) {
                return true;
            }
        }
    }
    return false;
}

bool Rook::check_movement(int wantrow, int wantcol, chessboard* brd) {
 //   std::cout << "in ROOK check move";
    int start;
    int end;
    if (cur_pos.first != wantrow and cur_pos.second != wantcol) {
        return false;
    }




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
            start = cur_pos.first + 1; // found the issue here. Now starts checking the row infront of it
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
    }

    return false;


}

bool Knight::check_movement(int wantrow, int wantcol) {

    int rowdiff = abs(cur_pos.first - wantrow);
    int coldiff = abs(cur_pos.second - wantcol);
    return ((rowdiff == 1 and coldiff == 2) or (rowdiff == 2 and coldiff == 1));
}
    

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
}


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
            start = cur_pos.first + 1; // found the issue here. Now starts checking the row infront of it
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
    }
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
    }
    return false;
}


bool Bishop::check_movement(int wantrow, int wantcol, chessboard* brd) {
    int drow = wantrow - cur_pos.first;
    int dcol = wantcol - cur_pos.second;
    if (abs(drow) != abs(dcol)) {
        return false;
    }
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
}

bool King::check_movement(int wantrow, int wantcol) {
//    std::cout << "in KI check move";
    if (cur_pos.first == wantrow && cur_pos.second == wantcol + 1) {
        return true;
    }
    else if (cur_pos.first == wantrow && cur_pos.second == wantcol - 1) {
        return true;
    }
    else if (cur_pos.first == wantrow + 1 && cur_pos.second == wantcol) {
        return true;
    }
    else if (cur_pos.first == wantrow - 1 && cur_pos.second == wantcol) {
        return true;
    }
    else if (cur_pos.first == wantrow + 1 && cur_pos.second == wantcol + 1) {
        return true;
    }
    else if (cur_pos.first == wantrow + 1 && cur_pos.second == wantcol - 1) {
        return true;
    }
    else if (cur_pos.first == wantrow - 1 && cur_pos.second == wantcol + 1) {
        return true;
    }
    else if (cur_pos.first == wantrow - 1 && cur_pos.second == wantcol - 1) {
        return true;
    }
    else {
        return false;
    }
}

