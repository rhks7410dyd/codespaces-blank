#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,K;
int shrt_path_val = 987654321;
int visit[100010];
queue<int> q;

int BFS(){
	int shrt_path_count = 0;
	int pos,t_pos;
	bool visit_K = false;
	
	visit[N] = 0;
	q.push({N,0});
	
	while(!q.empty()){
		pos = q.front();
		q.pop();
		//cout << pos.first << ' ' << pos.second << '\n';
		
		
	}
	
	return shrt_path_count;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	
	fill(&visit[0],&visit[100010]);
	
	int ans = BFS();
	
	cout << shrt_path_val << '\n' << ans << '\n';
	
	return 0;
}