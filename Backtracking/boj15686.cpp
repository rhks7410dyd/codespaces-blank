#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct pos{
	int r,c;
};

struct info{
	int r,c,val;
};

int N,M;
int map[50][50];
vector <pos> home;
vector <pos> chiken;
vector<vector <info>> near_chiken;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int i = 0 ; i < ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> arr[i][j];
			if(arr[i][j]){//1 or 2인 경우
				if(arr[i][j] == 1){
					home.push_back({i,j});
				}
				else{
					chiken.push_back({i,j});
				}
			}
		}
	}
	
	
	
	return 0;
}