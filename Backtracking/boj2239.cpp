#include <iostream>
#include <vector>

using namespace std;

int map[9][9];
bool recur(int next_blank);
bool can_put_this_num(int y,int x,int num);
vector<pair<int,int>> v;

int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	
	string input;
	for(int i = 0 ; i < 9 ; i ++){
		cin >> input;
		for(int j =0  ; j < 9 ; j++){
			map[i][j] = input[j]-'0';
			if(!map[i][j]){
				v.push_back({i,j});
			}
		}
	}
	
	recur(0);
	
	for(int i = 0 ; i < 9 ; i ++){
		for(int j =0  ; j < 9 ; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
	
	return 0;
}


bool recur(int next_blank){
	int y = v[next_blank].first;
	int x = v[next_blank].second;
	//cout << y << ' ' << x << '\n';
	if(next_blank == v.size()-1){
		for(int i = 1 ; i <= 9 ; i++){
			if(can_put_this_num(y,x,i)){
				map[y][x] = i;
				return true;
			}
		}
		return false;
	}
	
	for(int i = 1 ; i <= 9 ; i++){
		if(can_put_this_num(y,x,i)){
			map[y][x] = i;
			if(recur(next_blank+1)){
				return true;
			}
		}
	}
	
	map[y][x]=0;
	return false;
}

bool can_put_this_num(int y,int x,int num){
	int y_b = (y/3) * 3;
	int x_b = (x/3) * 3;
	for(int i = 0 ; i < 9 ; i++){
		if(map[y][i] == num || map[i][x] == num){
			return false;
		}
	}
	
	for(int i = y_b ; i < y_b+3 ; i++){
		for(int j = x_b ; j < x_b+3 ; j++){
			if(map[i][j] == num){
				return false;
			}
		}
	}
	
	return true;
}