#include "pieces.h"
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

bool Pawn::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }

}

bool Rook::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else {
        return false;
    }
}

bool Knight::check_movement(int x, int y) {
    std::cout << "hello";
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

bool Queen::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Bishop::check_movement(int x, int y) {
    if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool King::check_movement(int x, int y) {
    if (cur_pos.first == x && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x + 1 && cur_pos.second == y - 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y + 1) {
        return true;
    }
    else if (cur_pos.first == x - 1 && cur_pos.second == y - 1) {
        return true;
    }
    else {
        return false;
    }
}

