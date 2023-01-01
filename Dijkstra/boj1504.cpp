#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int graph[801][801];
int d[3][801]; // d[0] : 1 -> v1	d[1] : v1 -> v2		d[2] : v2 -> N
int N,M;
bool visit[801];

void dijkstra(int start, int end,int order){
	int temp = start;
	int min_val,min_pos;
	d[order][start] = 0;
	for(int i = 0 ; i < N ; i++){
		visit[temp] = true;
		min_val = INF;
		min_pos = -1;
		for(int j = 1 ; j <= N ; j++){
			if(visit[j])	continue;
			if(d[order][j] > d[order][temp] + graph[temp][j]){
				d[order][j] = d[order][temp] + graph[temp][j];
				if(d[order][j] < min_val){
					min_val = d[order][j];
					min_pos = j;
				}
			}
		}
		if(min_pos == -1 || min_pos == end)	break;
		temp = min_pos;
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	fill(&graph[0][0],&graph[800][801],INF);
	fill(&d[0][0],&d[2][801],INF);
	
	for(int i = 1 ; i <= N ; i++){
		graph[i][i] = 0;
	}
	
	int v1,v2,c;
	for(int i = 0 ; i < M ; i++){
		cin >> v1 >> v2 >> c;
		graph[v1][v2] = c;
		graph[v2][v1] = c;
	}
	
	cin >> v1 >> v2;
	
	dijkstra(1,v1,0);
	fill(&visit[0],&visit[801],false);
	dijkstra(v1,v2,1);
	fill(&visit[0],&visit[801],false);
	dijkstra(v2,N,2);
	
	/*
	//print arr
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1; j <= N ; j++){
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 1 ; j <= N ; j++){
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	*/
	
	if(d[0][v1] == INF || d[1][v2] == INF || d[2][N] == INF){
		cout << -1 << endl;
	}
	else{
		cout << (long long)d[0][v1] + (long long)d[1][v2] + (long long)d[2][N] << endl;
	}
	
	return 0;
}