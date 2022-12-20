#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int minimum_pirce[1001][1001];
int N,M;
bool visit[1001];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	scanf("%d",&N);
	scanf("%d",&M);
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			minimum_pirce[i][j] = INF;
		}
	}
	
	int s_pos,e_pos,val;
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d %d",&s_pos,&e_pos,&val);
		minimum_pirce[s_pos][e_pos] = val;
	}
	
	scanf("%d %d",&s_pos,&e_pos);
	visit[s_pos] = true;
	minimum_pirce[s_pos][s_pos] = 0;
	
	
	return 0;
}