#include "chessboard.h"
#include <iostream>
#include <stdio.h>
#include "pawn.h"
#include "king.h"


//checking for what piece has been clicked
int chessboard::grid_pressed(int row,int col,int nrow,int ncol,int squareSize){
    Pawn p;
    King k;
    bool wthere = false;
    bool bthere = false;
    int pos = arr[row][col];
    int en = arr[nrow][ncol];

    for(int i = 1 ; i<= 6 ; i++ ){
        if(i == en){
            bthere = true;
        }
    }
    for(int i = 7 ; i<= 12 ; i++ ){
        if(i == en){
            wthere = true;
        }
    }
    //checking black
    switch(pos){
    case 1 :
        //is a rook
        break;
    case 2 :
        //is a knight
        break;
    case 3 :
        //is a bishop
        break;
    case 4 :
        //is a queen

        break;
    case 5 :
        k.posassign(row,col,nrow,ncol);
                //if not nothing happens and the user can try again although am having issues with updating currow
                if(!k.movement()){
                    clkco = 0;
                }
                //if it can move then the grid will update itself
                else{
                    if(wthere == true){
                        updated_grid(row,col,nrow,ncol,pos);
                        std::cout<<"haha i have taken";
                    }
                    else if(bthere ==true){
                        std::cout<<"cant move there mate";
                    }
                    else{
                        updated_grid(row,col,nrow,ncol,pos);
                    }

                }

            break;
            //is a king
        
    case 6 :
        //is a pawn
        //a good example of how grid asks pawn if it can move to a position
        p.posassign(row,col,nrow,ncol);
        //if not nothing happens and the user can try again although am having issues with updating currow
        if(!p.movement(pos)){
            clkco = 0;
        }
        //if it can move then the grid will update itself
        else{
            if(nrow == row+1 && wthere == true && (ncol == col+1 || ncol == col-1)){
                updated_grid(row,col,nrow,ncol,pos);
                std::cout<<"haha i have taken";
            }
            else if(wthere ==true ||bthere ==true){
                std::cout<<"cant move there mate";
            }
            else{
                updated_grid(row,col,nrow,ncol,pos);
            }

        }

        break;
    }
    //checking white
    switch(pos){
    case 7 :

        p.posassign(row,col,nrow,ncol);
        p.movement(pos);
        if(!p.movement(pos)){
            clkco = 0;
        }
        else {
            //can it be attacking?
            if(nrow == row-1 && bthere == true && (ncol == col+1 || ncol == col-1)){
                updated_grid(row,col,nrow,ncol,pos);
                std::cout<<"haha i have taken";
            }
            else if(wthere ==true ||bthere ==true){
                std::cout<<"cant move there mate";
            }
            else{
                updated_grid(row,col,nrow,ncol,pos);
            }


        }
        //is a pawn
        break;
    case 8 :
        //is a rook
        break;
    case 9 :
        //is a knight
        break;
    case 10 :
        //is a bishop
        break;
    case 11 :
        //is a queen
        break;
    case 12 :
        //is a king
        k.posassign(row,col,nrow,ncol);
            //if not nothing happens and the user can try again although am having issues with updating currow
            if(!k.movement()){
                clkco = 0;
            }
            //if it can move then the grid will update itself
            else{
                if(bthere == true){
                    updated_grid(row,col,nrow,ncol,pos);
                    std::cout<<"haha i have taken";
                }
                else if(wthere ==true){
                    std::cout<<"cant move there mate";
                }
                else{
                    updated_grid(row,col,nrow,ncol,pos);
                }

            }

        break;
        break;
    }

    return 0;
}
int chessboard::updated_grid(int rowold,int colold,int rownew,int colnew,int piecenum){

    arr[rowold][colold]=0;
    arr[rownew][colnew] = piecenum;
    clkco = 0;
    return 0;
}
void chessboard::printBoard(){
    for(int i = 61;i<68;i++){
        char c = i;
        std::cout<<c<<"|";
        for(int j = 0;j<8;j++){
            std::cout<<arr[i-61][j]<<",";
        }
        
        }
    };
    /*printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");*/
