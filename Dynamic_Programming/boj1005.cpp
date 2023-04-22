//위상정렬 알고리즘 사용
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int time[1001];
int graph[1001][1001];
int time_sum[1001];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	
	for(int t = 0 ; t < T ; t++){
		int N,K;
		scanf("%d %d",&N,&K);
		
		for(int i = 1 ; i <= N ; i++){
			scanf("%d",&time[i]);
		}
		
		int a,b;
		for(int i = 0 ; i < K ; i++){
			scanf("%d %d",&a,&b);
			graph[a][b] = 1;
			graph[a][0]++;
		}
		
		int W;
		scanf("%d",&W);
		
		vector<pair<int,int>> v;
		queue<int> q;
		for(int i = 1 ; i <= N ; i++){
			if(graph[i][0] == 0){
				q.push(i);
			}
		}
		int deg =0;
		while(!q.empty()){
			int qsize = q.size();
			
			for(int i = 0 ; i < qsize ; i++){
				int now = q.front();
				q.pop();
				time_sum[now] += time[now];
				for(int j = 1 ; j <= N ; j++){
					if(graph[now][j] == 1)
					//머리 안돌아감 나주에
				}
			}
			
		}
	}
}