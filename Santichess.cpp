#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


struct MoveResult{
	int status;
	string message;
};
struct GameResult{
	int status;
	string message;
};

class AntiChess{
	
	public:

	int n;
	vector<string>board;
	int current_player;
	int max_moves;
	int moves_made;
	vector<string>meta_data;
	AntiChess(){//int maxMoves){

		n = 8;	
		current_player = 1;
		max_moves = 10;//maxMoves;
		moves_made = 0;
		string empty_row = "........";
		string bottom_row = "RNBQKBNR";
		string top_row = "rnbqkbnr";
		string top_pawns = "pppppppp";
		string bottom_pawns = "PPPPPPPP";
		for(int i=0;i<n;i++){
			board.push_back(empty_row);		
		}		
		board[0] = top_row;
		board[1] = top_pawns;
		board[7] = bottom_row;
		board[6] = bottom_pawns;	
	}
	


	
/*------------------- helper functions ------------------------------*/
    inline int to_int(string x){

        stringstream ss;        ss << x;
        int ret;                ss >> ret;
        return ret;
    }
    inline string to_string(int x){
        stringstream ss;        ss << x;
        string ret;             ss >> ret;
        return ret;
    }
    inline bool check_int(string str){
        int n = str.size();
        for(int i=0;i<n;i++)
                if(!(str[i]>='0'&&str[i] <= '9'))
                        return 0;
        return 1;
    }

    vector<string> split_string(string str){
        stringstream ss;        ss << str;
        string res;
	vector<string>ret;
	while(ss >> res)        
		ret.push_back(res);
        return ret;

   }

/*____________________________________________________________________________________*/

    inline int check_piece(int x,int y){
	     char piece = board[x][y];
	     if(current_player == 1) {
             		if(piece >= 'A' && piece <= 'Z')
                        	return 1;
                        else if(piece >= 'a' && piece <= 'z')
                        	return 0;
             }
             if(current_player == 2){
             	//cout << x << " " << y << " " << piece << "\n";
		if(piece >= 'A' && piece <= 'Z')
                	return 0;
                else if(piece >= 'a' && piece <= 'z')
                	return 1;
             }
	return -1;

}

   inline int check_king(int x, int y){

	int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
	int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	
		

	for(int i = 0; i < 8; i++){
		int xx = x + dx[i];
		int yy = y + dx[i];
		if(xx < 0 || xx >= n || yy < 0 || yy >= n)
			continue;
		int ret = check_piece(xx, yy);
		if(ret == 1)	return ret;
	}				
	return 0;											
}

  inline int check_queen(int x, int y){

	int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	
	for(int i = 0; i < 8; i++){
		int xx = x, yy = y;
		while(1){
			xx = xx + dx[i];
			yy = yy + dy[i];
			if(xx < 0 || xx >= n || yy < 0 || yy > n)
				break;
			int ret = check_piece(xx, yy);
			if(ret == 0)break;
			else if(ret == 1)	return ret;
		}
	}
	return 0;

}

  inline int check_knight(int x, int y){
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	
	for(int i = 0; i < 8; i++){
        	int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx < 0 || xx >= n || yy < 0 || yy > n)
                	continue;
		int ret = check_piece(xx, yy);
		if( ret == 1)	return ret;	
	}	
	return 0;
} 

  inline int check_bishop(int x, int y){
	int dx[] = {1, 1, -1, -1};
	int dy[] = {-1, 1, 1, -1};
		
	for(int i=0;i<4;i++){
		int xx = x, yy = y;
		while(1){
			xx += dx[i];
			yy += dy[i];
			if(xx < 0 || xx >= n || yy < 0 || yy >= n)
				break;
			int ret = check_piece(xx, yy);
			if(ret == 0)break;
			else if(ret == 1) return ret;
		}
	}
	return 0;
  }

  inline int check_rook(int x, int y){
	int dx[] = {0, 1, 0, -1};
	int dy[] = {-1, 0, 1, 0};
	
	for(int i=0; i < 4; i++){
		int xx = x, yy = y;
		while(1){
			xx += dx[i];
			yy += dy[i];
			if( xx < 0 || xx >= n || yy < 0 || yy >= n )
				break;
			int ret = check_piece(xx, yy);
			if( ret == 0 ) break;
			else if( ret == 1 ){	
				return ret;
			}
		}
	}
	return 0;
  }

  inline int check_pawn(int x, int y){
	
	int dx[] = {1, 1, -1, -1};
        int dy[] = {-1, 1, 1, -1};
	
	for(int i=0;i<4;i++){
		
		int xx = x + dx[i];
		int yy = y + dy[i];
		//if(x == 5 && y == 0)
		//	cout << xx << " " << yy << "\n";
		if(xx < 0 || xx >= n || yy < 0 || yy >= n)
			continue;
	
		if(current_player == 1 && i < 2){
			int ret = check_piece(xx, yy);
			if(ret == 1)	return ret;		
		}
		else if(current_player  == 2 && i >= 2){
			int ret = check_piece(xx, yy);
			if(ret == 1) return ret;			
		}
	}
	return 0;
  }

/*------------------------------------------------------------------------------------------------------*/

    inline int check_move_piece(int x,int y){
	     char piece = board[x][y];
             if(current_player == 1) {
             		if(piece >= 'A' && piece <= 'Z')
                        	return 1;
                        else if(piece >= 'a' && piece <= 'z')
                        	return 0;
             }
             if(current_player == 2){
             		if(piece >= 'a' && piece <= 'z')
                        	return 1;
                        else if(piece >= 'A' && piece <= 'Z')
                                return 0;
             }
	     if(board[x][y] == '.')
		return -1;
	     return 0;

    }

    inline int check_move_king(int x1, int y1, int x2, int y2, int tocapture){

	if(!(abs(x1-x2) <= 1 && abs(y1-y2) <= 1))
		return 0;

	int capture = check_move_piece(x2,y2);
	if(tocapture == 1){
		return (capture == 1);
	}
	else
		return (capture == -1);
									
    }

    inline int check_move_bishop(int x1,int y1, int x2, int y2, int tocapture){
	if(!(abs(x2-x1) == abs(y2-y1)))
		return 0;
	int dx = (x2-x1)/abs(x2-x1);
	int dy = (y2-y1)/abs(y2-y1);
		
	int xx = x1, yy = y1;
	
	while(1){
		xx += dx;
		yy += dy;
		if(xx < 0 || xx >= n || yy < 0 || yy >= n)
			return 0;
		if(xx == x2 && yy == y2)
			break;
		if(check_move_piece(xx,yy) != -1)
			return 0;
	}
	int capture = check_move_piece(x2, y2);
	if(tocapture == 1){
		return (capture == 1);
	}
	else	return (capture == -1);
    }

    inline int check_move_knight(int x1, int y1, int x2, int y2, int tocapture){
	if(!((abs(x2-x1) == 2 && abs(y1-y2) == 1) || (abs(x1-x2) == 1 && abs(y1-y2) == 2)))
    		return 0;
	int capture = check_move_piece(x2, y2);
	if(tocapture == 1)
		return (capture == 1);
	else
		return (capture == -1);
    } 

    inline int check_move_rook(int x1, int y1, int x2, int y2, int tocapture){
	
	if(!(x1 == x2 || y1 == y2))
		return 0;
	
	int div = max(abs(x1-x2), abs(y1-y2));	
	int dx = (x2-x1)/div;
	int dy = (y2-y1)/div;
	int xx = x1, yy = y1;
	while(1){
		xx += dx, yy += dy;
		if(xx < 0 || xx >= n || xx < 0 || xx >= n)
			return 0;
		if(xx == x2 && yy == y2)
			break;
		if(check_move_piece(xx,yy) != -1)
                    return 0;
	}
	int capture = check_move_piece(x2, y2);
	if(tocapture == 1)
		return (capture == 1);
	else
		return (capture == -1);
	
    }

  inline int check_move_pawn(int x1, int y1, int x2, int y2, int tocapture){
	
	int capture = check_move_piece(x2, y2);
//	cout << capture << "\n";
	if(current_player == 1){
		if(tocapture == 1){
			if(!((x2-x1) == 1 && abs(y1-y2)==1))
				return 0;
			return (capture == 1);
		}
		else{
			if(!((y1 == y2) && (x2 == x1+1)))
				return 0;
			return (capture == -1);
		}
	}
	else{
		if(tocapture == 1){
			if(!((x2-x1) == -1 && abs(y1-y2) == 1))
				return 0;
			return (capture == 1);
		}	
		else{
			if(!((y1 == y2) && (x2 == x1-1)))
				return 0;
			return (capture == -1);
		}
	}
  }

/*------------------------------------------------------------------------------------------------*/


  int can_capture_any(){
	int ok = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(ok == 1) break;			
			char piece = board[i][j];
			if(current_player == 1 && piece >= 'A' && piece <= 'Z')
				continue;
			if( current_player == 2 && piece >= 'a' && piece <= 'z')
				continue;
			if(piece == 'k' || piece == 'K'){
				ok = check_king(i, j);	
			}
			else if (piece == 'Q' || piece == 'q'){
				ok = check_queen(i, j);
			}
			else if(piece == 'N' || piece == 'n'){
				ok = check_knight(i, j);
			}
			else if(piece == 'r' || piece == 'R'){
				ok = check_rook(i, j);
			}
			else if(piece == 'b' || piece == 'B'){
				ok = check_bishop(i, j);
			}
			else if(piece == 'p' || piece == 'P'){
			//	if(i == 5 && j == 0)
				ok = check_pawn(i, j);				
			}
		}
	return ok;
  }

  MoveResult is_valid_move(string move){
	
	vector<string>moves = split_string(move);

	MoveResult res;
	
	res.status = -1;
	res.message = "Move made from " + moves[0] + " " + moves[1] + " to " + moves[2] + " " + moves[3];
	
	if( moves[0] == "" || moves[1] == "" || moves[2] == "" || moves[3] == ""){
		res.message = "Invalid Move format.";
		return res;
	}
	if(!check_int(moves[0]) || !check_int(moves[1]) || !check_int(moves[2]) || !check_int(moves[3])){
		res.message = "Invalid Move format.";
		return res;
	}
	 	
	int x1 = to_int(moves[0]);
	int y1 = to_int(moves[1]);
	
	int x2 = to_int(moves[2]);
	int y2 = to_int(moves[3]);
	
	if(x1 < 0 || y1 >= n || x2 < 0 || y2 >= n){
		res.message = "Illegal Move. The index of move was out of bound.";
		return res;
	}
        if(x1 == x2 && y1 == y2){
		res.message = "Illegal Move.";
		return res;	
	}
	if(board[x1][y1] == '.'){
		res.message = "Invalid piece moved.";
		return res;
	}
	if(current_player == 1){
		if(!(board[x1][y1] >= 'a' && board[x1][y1] <= 'z')){
			res.message = "Invalid piece moved.";
			return res;
		}
	}
	else if(current_player == 2){
		if(!(board[x1][y1] >= 'A' && board[x1][y1] <= 'Z')){
			res.message = "Invalid piece moved.";
			return res;	
		}
	}
	
	int tocapture = can_capture_any();
	//cout << tocapture << "\n";	
	char piece = board[x1][y1];
	
	int ok = 0;
	
	string common_message = "Invalid move.";
		
	
	if(piece == 'k' || piece == 'K')
        	ok = check_move_king(x1, y1, x2, y2, tocapture);
        else if (piece == 'Q' || piece == 'q')
        	ok = check_move_bishop(x1, y1, x2 ,y2, tocapture) || check_move_rook(x1, y1, x2, y2, tocapture);
        else if(piece == 'N' || piece == 'n')
        	ok = check_move_knight(x1, y1, x2, y2, tocapture);
        else if(piece == 'r' || piece == 'R')
        	ok = check_move_rook(x1, y1, x2, y2, tocapture);
        else if(piece == 'b' || piece == 'B')
        	ok = check_move_bishop(x1, y1, x2, y2, tocapture);
        else if(piece == 'p' || piece == 'P'){
        	ok = check_move_pawn(x1, y1, x2, y2, tocapture);
	}
	if(ok == 1){
		res.status = 0;
	}
	else
		res.message = common_message;
	return res;
  }

  void make_move(string move){
	meta_data.clear();
	vector<string> moves = split_string(move);
	int x1 = to_int(moves[0]);
        int y1 = to_int(moves[1]);

        int x2 = to_int(moves[2]);
        int y2 = to_int(moves[3]);
	
	meta_data.push_back(to_string(x1) + " " + to_string(y1) + " " + to_string(current_player));
	meta_data.push_back(to_string(x2) + " " + to_string(y2) + " " + to_string(current_player));

	board[x2][y2] = board[x1][y1];
	board[x1][y1] = '.';
 	moves_made++; 
	current_player  = 3 - current_player;
 
}	
	
  GameResult get_game_status(){
	GameResult res;
	res.status = -1;
	res.message = "The game id still in progress.";	
  	
	int score1 = 0;
	int score2 = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			char piece = board[i][j];
			if(piece >= 'a' && piece <= 'z')
				score1++;
			else if(piece >='A' && piece <= 'Z')
				score2++;
		}
	
	if(score1 == 0){
		res.status  = 1;	
		res.message = "Player1 won the game.";
	}
	else if(score2 == 0){
		res.status = 2;
		res.message = "Player2 has won the game.";
	}
	
	if(moves_made == max_moves){
		if(score1 < score2){
			res.status = 1;
			res.message= "Player1 has won the game.";
			return res;
		}
		else if(score1 > score2){
			res.status = 2;
			res.message = "Player2 has won the game.";
			return res;
		}
		else{
			res.status = 0;
			res.message = "The game is drawn.";
			return res;	
		}
	}
	
	return res;		
  }	

  /*
	* is_over tells whether the game is over and is so who is the winner
	* 1 indicate player 1 has won
	* 2 indicate player 2 has won
	* 0 indicate a draw
	* -1 indicate the game is not yet over
  */  

	inline int is_over(){
		
		int over = -1;
		int score1 = 0, score2 = 0;
		for(int i = 0; i < n; i++){
			for(int j=0;j<n;i++){
				if(board[i][j] >= 'a' && board[i][j] <= 'z')
					score1++;
				else if(board[i][j] >= 'A' && board[i][j] <= 'Z')
					score2++;
			}
		}
		if(score1 == 0){
			return over = 1;
		}		
		else if(score2 == 0){
			return over = 2;
		}
		if(moves_made > max_moves){
			if(score1 < score2)
				over = 1;
			else if(score1 > score2)
				over = 2;
			else
				over = 0;	
		}
		return over;
	}
	
  vector<string> get_move(){
  	return meta_data;
  }

  string get_next_state_input(){	
	string res = "";
	res += to_string(current_player) + "\n";;
	
	for(int i=0;i<n;i++)
		res += board[i] + "\n";;
	
	return res;
  }
  string get_current_state(){
	string res = "";
	for(int i=0;i<n;i++){
		res += board[i] + "\n";
	}
	return res;
  }
};


struct st{
	string s;
	//nt x1,x2,y1,y2;
	int val;
	friend bool operator<(const st st1,const st& st2){
		return st1.val > st2.val;
	}
};

int main(){
	

	string s = "........";
	vector<string>board;
	for(int i=0;i<8;i++)
		board.push_back(s);
	int player;
	cin >> player;
	for(int i=0;i<8;i++)
		cin >> board[i];
	AntiChess game;	
	game.board = board;
	game.current_player = player;
	
	vector<st>vv;
	
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){
			char piece = board[i][j];
			if(player == 1 && !(piece >= 'a' && piece <= 'z'))
				continue;
			if(player == 2 && !(piece >= 'A' && piece <= 'Z'))
				continue;
			int ok = 0;
			//vector<st>vv;
			for(int k=7;k>=0;k--)
				for(int l=7;l>=0;l--)if(!(i==k&&j==l)){
					int x1,x2,y1,y2;
					x1=i,y1=j,x2=k,y2=l;
					//cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
					int tocapture = game.can_capture_any();
					//cout << tocapture << "\n";
					if(piece == 'k' || piece == 'K'){
                				
						ok = game.check_move_king(x1, y1, x2, y2, tocapture);		
					}
        				else if (piece == 'Q' || piece == 'q')
                				ok = game.check_move_bishop(x1, y1, x2 ,y2, tocapture) || game.check_move_rook(x1, y1, x2, y2, tocapture);
        				else if(piece == 'N' || piece == 'n')
                				ok = game.check_move_knight(x1, y1, x2, y2, tocapture);
        				else if(piece == 'r' || piece == 'R')
                				ok = game.check_move_rook(x1, y1, x2, y2, tocapture);
        				else if(piece == 'b' || piece == 'B')
                				ok = game.check_move_bishop(x1, y1, x2, y2, tocapture);
        				else if(piece == 'p' || piece == 'P')
                				ok = game.check_move_pawn(x1, y1, x2, y2, tocapture);
        		
					if(ok){	
						AntiChess tmp;
						string move = tmp.to_string(x1) + " " + tmp.to_string(y1) + " " + tmp.to_string(x2) + " " + tmp.to_string(y2);
						tmp.current_player = game.current_player;
						tmp.make_move(move);
						st tmpp ;
						tmpp.s = move;
						tmpp.val = tmp.can_capture_any();
						vv.push_back(tmpp);
						//cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
						//return 0;
					}
				}
				
		}
	
			
	cout << vv[0].s << "\n";
	return 0;
}