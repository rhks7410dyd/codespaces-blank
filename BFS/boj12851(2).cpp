#include <iostream>
#include <queue>

using namespace std;

int n,k,cnt=0,tim;
queue<pair<int,int>> q;
bool visit[100001];

void BFS(){
	visit[n] = true;
	q.push({n,0});
	while(!q.empty()){
		int pos = q.front().first;
		int t = q.front().second;
		q.pop();
		visit[pos] = true;
		
		if(cnt && pos == k && t == tim){
			cnt++;
		}
		
		if(!cnt && pos == k){
			cnt ++;
			tim = t;
		}
		
		if(pos -1 >= 0 && !visit[pos-1])	q.push({pos-1,t+1});
		if(pos + 1 < 100001 && !visit[pos+1])	q.push({pos+1,t+1});
		if(pos * 2 < 100001 && !visit[pos*2])	q.push({pos*2,t+1});
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	BFS();
	
	cout << tim << '\n' << cnt << '\n';
	
	return 0;
}