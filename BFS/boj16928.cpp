#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[101];//사다리나 뱀이 있다면 값이 들어가고 아니면 -1이 초기값으로 들어가있음.
int N,M;
int shrt_path[101];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;

	fill(&map[0],&map[101],-1);
	fill(&shrt_path[0],&shrt_path[101],-1);
	
	int start,end;
	for(int i = 0 ; i < N + M ; i++){
		cin >> start >> end;
		map[start] = end;
	}
	
	queue<int> q;
	q.push(1);
	shrt_path[1] = 0;
	while(!q.empty()){
		int now = q.top();
		q.pop();
		
		if(now == 100){
			break;
		}
		
		int next = map[now];
		if(next != -1 && shrt_path[next] == -1){
			shrt_path[next] = shrt_path[now];
			q.push(next);
		}
		for(next = now + 1 ; next <= now + 6 ; next++){
			if(next > 100)	break;
			if(shrt_path[next] == -1){
				shrt_path[next] = shrt_path[now] + 1;
				q.push(next);
			}
		}
	}
	
	for(int i = 0 ;  i < 10 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			cout << shrt_path[10*i + j + 1] << ' ';
		}
		cout << endl;
	}
	
	//cout << shrt_path[100] << '\n';

	return 0;
}