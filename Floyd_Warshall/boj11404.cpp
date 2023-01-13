#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int map[101][101];

int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios::sync_with_stdio(false);
	
	int N,M;
	cin >> N >> M;
	
	int a,b,c;
	fill(&map[0][0],&map[101][102],INF);
	
	for(int i = 0 ; i < M ; i++){
		cin >> a >> b >> c;
		if(map[a][b] > c)	map[a][b] = c;
	}
	
	for(int i = 1 ; i <= N ; i++){
		map[i][i] = 0;
	}
	
	//cout <<"ln29\n";
	
	for(int i = 1 ; i <= N ; i++){
		for(int n1 = 1 ; n1 <= N ; n1++){
			for(int n2 = 1 ; n2 <= N ; n2++){
				//if(map[n1][n2] > map[n1][i] + map[i][n2])	map[n1][n2] = map[n1][i] + map[i][n2];
				map[n1][n2] = min(map[n1][n2] , map[n1][i] + map[i][n2]);
			}
		}
	}
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1; j <= N ; j++){
			if(map[i][j] != INF){
				cout << map[i][j] << ' ';
				continue;
			}
			cout << 0 << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}