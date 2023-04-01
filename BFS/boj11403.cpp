#include <iostream>
#include <queue>

using namespace std;

int N;
bool map[100][100];
bool can_visit[100][100];
bool visit[100][100];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
		}
	}
	
	queue<int> q;
	for(int i = 0 ; i < N ; i++){
		q.push(i);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int j = 0 ; j < N ; j++){
				if(visit[i][j] || !map[now][j])	continue;
				q.push(j);
				visit[i][j] = true;
				can_visit[i][j] = true;
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << can_visit[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}