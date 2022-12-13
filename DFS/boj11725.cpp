#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int N;
vector<int> adj_list[100001];
bool visit[100001];
int parent_node_info[100001];
queue<int> q;

void BFS(){
	visit[1] = true;
	int temp,nxt;
	
	for(int i = 0 ; i < adj_list[1].size() ; i++){
		temp = adj_list[1][i];
		q.push(temp);
		visit[temp] = true;
		parent_node_info[temp] = 1;
	}
	
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(int i = 0 ; i < adj_list[temp].size() ; i++){
			nxt = adj_list[temp][i];
			if(!visit[nxt]){
				q.push(nxt);
				visit[nxt] = true;
				parent_node_info[nxt] = temp;
			}
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	
	int n1,n2;
	for(int i = 1 ; i < N ; i++){
		cin >> n1 >> n2;
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}
	
	BFS();
	
	for(int i = 2 ; i <= N ; i++){
		cout << parent_node_info[i] << endl;
	}
	
	return 0;
}