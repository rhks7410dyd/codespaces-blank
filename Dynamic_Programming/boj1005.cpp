//위상정렬 알고리즘 사용
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	
	for(int t = 0 ; t < T ; t++){
		int N,K;
		int Time[1001] ={0,};
		int graph[1001][1001]={{0,},};
		int Time_sum[1001]={0,};
		scanf("%d %d",&N,&K);
		
		for(int i = 1 ; i <= N ; i++){
			scanf("%d",&Time[i]);
		}
		
		int a,b;
		for(int i = 0 ; i < K ; i++){
			scanf("%d %d",&a,&b);
			graph[a][b] = 1;
			graph[b][0]++;
		}
		
		int W;
		scanf("%d",&W);
		
		queue<int> q;
		for(int i = 1 ; i <= N ; i++){
			if(graph[i][0] == 0){
				q.push(i);
				Time_sum[i] = Time[i];
			}
		}
		
		if(Time_sum[W] == Time[W]){
			printf("%d\n",Time[W]);
			continue;
		}
		
		vector<int> v; 
		bool visit[1001] = {false,};
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int i = 1 ; i <= N ; i++){
				if(graph[now][i] == 1 && !visit[i]){
					graph[i][0]--;
					if(graph[i][0] == 0){
						visit[i] = true;
						q.push(i);
						v.push_back(i);
					}
				}
			}
		}
		
		for(int i = 0 ; i < v.size() ; i++){
			int now = v[i];
			int max_t = -1;
			for(int j = 1 ; j <= N ; j++){
				if(graph[j][now] == 1){
					max_t = max(max_t,Time_sum[j]);
				}
			}
			Time_sum[now] = max_t + Time[now];
			//if(now == W)	break;
		}
		
		printf("%d\n",Time_sum[W]);
	}
	
	return 0;
}