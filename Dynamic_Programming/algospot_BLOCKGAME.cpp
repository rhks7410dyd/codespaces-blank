#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
0 1 2 3 4 
5 6 7 8 9
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
*/

vector<int> moves;
inline int cell(int y,int x){return 1 << (y*5 + x);}

void precalc(){
	for(int y = 0 ; y < 4 ; y++){
		for(int x = 0 ; x < 4 ; x++){
			vector<int> cells;
			for(int dy = 0 ; dy < 2 ; dy++){
				for(int dx = 0 ; dx < 2 ; dx++){
					cells.push_back(cell(y+dy,x+dx));
				}
			}
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			for(int i = 0 ; i < 4 ; i++){
				moves.push_back(square - cells[i]);
			}
		}
	}
	
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			moves.push_back(cell(i,j)+cell(i,j+1));
			moves.push_back(cell(j,i)+cell(j+1,i));
		}
	}
}

char cache[1<<25+1];

char play(int board){
	char& ret = cache[board];
	if(ret != -1)	return ret;
	ret = 0;
	for(int i = 0 ; i < moves.size() ; i++){
		if((moves[i] & board) == 0){
			if(play(board|moves[i]) == 0){
				ret = 1;
				break;
			}
		}
	}
	return ret;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int state;
	int C;
	
	precalc();
	memset(cache,-1,sizeof(cache));
	cin >> C;
	while(C--){
		state = 0;
		char t;
		for(int i = 0 ; i < 5 ; i++){
			for(int j = 0 ; j < 5 ; j++){
				cin >> t;
				if(t == '#')	state += cell(i,j);//이 파트를 제대로 안했더니 문제가 생긴듯.
			}
		}
		
		if(play(state)){
			cout << "WINNING\n";
		}
		else{
			cout << "LOSING\n";
		}
	}
	
	return 0;
}