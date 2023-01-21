#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> v[10001];
bool visit[10001];
vector<int> s;
int result = 0;
int end_p = 0;

void DFS(int node,int len){
	if(visit[node])	return;
	
	visit[node] = true;
	
	if(len > result){
		result = len;
		end_p = node;
	}
	
	for(int i = 0 ; i < v[node].size() ; i++){
		DFS(v[node][i].first, len+v[node][i].second);
	}
}

void print_tree(){
	cout << endl;
	for(int i = 1 ; i <= n ; i++){
		cout << i << " : ";
		for(int j = 0 ; j < v[i].size() ; j++){
			cout << "{ " << v[i][j].first << " , " << v[i][j].second << " } , ";
		}
		cout << endl;
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	int a,b,r;
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b >> r;
		v[a].push_back({b,r});
		v[b].push_back({a,r});
	}
	
	//print_tree();
	
	DFS(1,0);
	
	fill(&visit[0],&visit[10001],false);
	
	result = 0;
	DFS(end_p,0);
	
	cout << result << '\n';
	
	return 0;
}