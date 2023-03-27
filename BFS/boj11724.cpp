#include <iostream>
#include <queue>

using namespace std;

int N,M;
bool visit_node[1001];
bool map[1001][1001];

void BFS(int start);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i = 0 ; i < M ; i++){
		int n1,n2;
		cin >> n1 >> n2;
		map[n1][n2] = true;
		map[n2][n1] = true;
	}
	
	int connected_component_count = 0;
	for(int i = 1 ; i <= N ; i++){
		if(visit_node[i])	continue;
		
		BFS(i);
		connected_component_count++;
	}
	
	cout << connected_component_count << '\n';
	
	return 0;
}

void BFS(int start){
	visit_node[start] = true;
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int n = q.front();
		q.pop();
		for(int i = 1 ; i <= N ; i++){
			if(visit_node[i] || !map[n][i])	continue;
			visit_node[i] = true;
			q.push(i);
		}
	}
}