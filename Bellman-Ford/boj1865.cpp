#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int map[1001][1001];
int d[1001];
int TC,N,M,W;//node 개수

void Input(){
	cin >> N >> M >> W;
		
	fill(&map[1][1],&map[1000][1001],INF);
	fill(&d[1],&d[1001],INF);
		
	for(int i = 0 ; i < M ; i++){
		cin >> S >> E >>> T;
		if(map[S][E] < T) continue;
		map[S][E] = T;
		map[E][S] = T;
	}
	
	for(int i = 0 ; i < W ; i++){
		cin >> S >> E >> T;
		map[S][E] = -T;
	}
	
}

bool bellman_ford(){
	d[1] = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(map[node][j] < INF){
				
			}
		}
	}
	
	
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> TC;
	
	int S,E,T;
	for(int t = 0 ; t < TC ; t++){
		Input();
		
		bool time_travel = bellman_ford();
		
		if(time_travel)	cout << "YES\n";
		else	cout << "NO\n";
	}
	
	return 0;
}