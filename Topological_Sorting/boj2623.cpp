#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[1001][1001]={};
vector<int> Sort;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,M;
	
	cin >> N >> M;
	
	for(int i = 0 ; i < M ; i++){
		int t;
		cin >> t;
		if(!t)	continue;
		int a,b;
		cin >> a;
		for(int j = 1 ; j < t ; j++){
			cin >> b;
			if(graph[a][b] == 1)	continue;
			graph[a][b] = 1;
			graph[b][0]++;
			a = b;
		}
	}
	
	queue<int> q;
	for(int i = 1 ; i <= N ; i++){
		if(graph[i][0] == 0){
			q.push(i);
			Sort.push_back(i);
		}
	}
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 1 ; i <= N ; i++){
			if(graph[now][i] == 1){
				graph[i][0]--;
				if(graph[i][0] == 0){
					q.push(i);
					Sort.push_back(i);
				}
			}
		}
	}
	
	if(Sort.size() != N){
		cout << 0 << '\n';
	}
	else{
		for(int i = 0 ; i < N ; i++){
			cout << Sort[i] << '\n';
		}
	}
	
	return 0;
}