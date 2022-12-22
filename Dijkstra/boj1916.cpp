#include <iostream>
#define INF 1234567890

using namespace std;

int minimum_pirce[1001][1001];
int d[1001];
bool visit[1001];
int N,M;

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
		if(minimum_pirce[s_pos][e_pos] > val)	minimum_pirce[s_pos][e_pos] = val;
	}
	
	scanf("%d %d",&s_pos,&e_pos);
	minimum_pirce[s_pos][s_pos] = 0;
	visit[s_pos] = true;
	
	for(int i = 1 ; i <= N ; i++){
		d[i] = minimum_pirce[s_pos][i];
	}
	
	int small_dis_index;
	for(int i = 1 ; i <= N ; i++){
		//거리가 INF가 아니면서 방문하지 않았고 가장 가까운 노드를 탐색
		int min = INF;
		small_dis_index = 0;
		for(int j = 1 ; j <= N ; j++){
			if(min > d[j] && !visit[j]){
				min = d[j];
				small_dis_index = j;
			}
		}
		visit[small_dis_index] = true;
		if(!small_dis_index)	break;
		
		//cout << "small_dis_index " << small_dis_index << endl;
		
		
		for(int j = 1 ; j <= N ; j++){
			if(!visit[j]){
				if(d[j] > d[small_dis_index] + minimum_pirce[small_dis_index][j]){
					d[j] = d[small_dis_index] + minimum_pirce[small_dis_index][j];
				}
			}
		}
		
		/*
		for(int j = 1 ; j <= N ; j++){
			cout << d[j] << ' ';
		}
		cout << endl;
		*/
	}
	
	cout << d[e_pos] << endl;
	
	return 0;
}