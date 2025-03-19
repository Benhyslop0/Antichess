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
    std::cout << "check move";
    if (colour == WHITE) {
        if (y == cur_pos.second && brd->arr[x][y] == nullptr) {
            if (x == cur_pos.first - 1) {
                return true;
            }
            if (cur_pos.first == 6 && x == cur_pos.first - 2 && brd->arr[cur_pos.first - 1][y] == nullptr) {
                return true;
            }
        }       
        else if (x == cur_pos.first - 1 &&
            (y == cur_pos.second - 1 || y == cur_pos.second + 1)) {
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
        else if (x == cur_pos.first - 1 &&
            (y == cur_pos.second + 1 || y == cur_pos.second - 1)) {
            if (brd->arr[x][y] != nullptr && brd->arr[x][y]->get_colour() == BLACK) {
                return true;
            }
        }
    }
    return false;
}

bool Rook::check_movement(int wantrow, int wantcol, chessboard* brd) {
    std::cout << "in ROOK check move";
    for (int i = 1; i <= 7; i++) {
        //left
        if (cur_pos.first == wantrow && cur_pos.second == wantcol + i) {
            for (int j = 0; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        // right
        else if (cur_pos.first == wantrow && cur_pos.second == wantcol - i) {
            for (int j = 0; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        //up
        else if (cur_pos.first == wantrow + i && cur_pos.second == wantcol) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second];
                std::cout << pos;
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        //down
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol) {
            for (int j = 0; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool Knight::check_movement(int x, int y) {
    std::cout << "in KN check move";
    if (cur_pos.first == x + 2 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 2 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 2 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 2 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 2) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 2) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 2) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 2) {
        return true;
    }
    else {
        return false;
    }
}

bool Queen::check_movement(int wantrow, int wantcol, chessboard* brd) {
    std::cout << "in QN check move";
    for (int i = 0; i <= 7; i++) {
        //left
        if (cur_pos.first == wantrow && cur_pos.second == wantcol + i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        // right
        else if (cur_pos.first == wantrow && cur_pos.second == wantcol - i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        //up
        else if (cur_pos.first == wantrow + i && cur_pos.second == wantcol) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        //down
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow + i && cur_pos.second == wantcol + i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow + i && cur_pos.second == wantcol - i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol + i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol - i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }

    }
    return false;
}

bool Bishop::check_movement(int wantrow, int wantcol, chessboard* brd) {
    std::cout << "in BI check move";
    for (int i = 0; i <= 7; i++) {

        if (cur_pos.first == wantrow + i && cur_pos.second == wantcol + i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow + i && cur_pos.second == wantcol - i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first - j][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol + i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second - j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
        else if (cur_pos.first == wantrow - i && cur_pos.second == wantcol - i) {
            for (int j = 1; j < i; j++) {
                Piece* pos = brd->arr[cur_pos.first + j][cur_pos.second + j];
                if (pos != nullptr) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool King::check_movement(int wantrow, int wantcol) {
    std::cout << "in KI check move";
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

