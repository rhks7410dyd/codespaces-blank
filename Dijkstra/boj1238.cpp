//처음에 플로이드 워셜을 쓰려고 했는데, (10^3)^3 = 10억 이므로 시간초과가 뜰 수 있다는 감이 강하게 든다. 따라서 데이크스트라 알고리즘을 이용하여 특정 X노드까지의 최단거리만 구하는 것이 합당하지 않을까? 란 생각이 들었기에
//플로이드 워셜이 아닌 데이크스트라를 사용한다.
//c++에서는 플로이드 워셜로 충분히 풀린다는 질답 내용을 백준에서 봤지만, 의도가 데이크스트라의 응용이므로 데이크스트라로 풀기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<pair<int,int>> map[1001]; 
vector<pair<int,int>> rev_map[1001];
int N,M,X;
int to_X_dis[1001];
int from_X_dis[1001];

void dijkstra(){//노드 X에서 i까지 최단 거리를 구하는 데이크스트라 함수
	from_X_dis[X] = 0;
	priority_queue <pair<int,int>> pq;
	pq.push({X,0});
	while(!pq.empty()){
		int temp_node = pq.top().first;
		int temp_dis = -pq.top().second;
		pq.pop();
		
		if(temp_dis > from_X_dis[temp_node])	continue;
		
		for(int i = 0 ; i < map[temp_node].size() ; i++){
			int next = map[temp_node][i].first;
			int next_d = from_X_dis[temp_node] + map[temp_node][i].second;
			if(next_d < from_X_dis[next]){
				from_X_dis[next] = next_d;
				pq.emplace(next,-next_d);
			}
		}
	}
}

void rev_dijkstra(){//노드 i에서 X까지 최단 거리를 구하는 데이크스트라 함수
	to_X_dis[X] = 0;
	priority_queue <pair<int,int>> pq;
	pq.push({X,0});
	while(!pq.empty()){
		int temp_node = pq.top().first;
		int temp_dis = -pq.top().second;
		pq.pop();
		
		if(temp_dis > to_X_dis[temp_node])	continue;
		
		for(int i = 0 ; i < rev_map[temp_node].size() ; i++){
			int next = rev_map[temp_node][i].first;
			int next_d = to_X_dis[temp_node] + rev_map[temp_node][i].second;
			if(next_d < to_X_dis[next]){
				to_X_dis[next] = next_d;
				pq.emplace(next,-next_d);
			}
		}
	}	
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> X;
	
	int sn,en,val;
	for(int i = 0 ; i < M ; i++){
		cin >> sn >> en >> val;
		map[sn].push_back({en,val});
		rev_map[en].push_back({sn,val});
	}
	
	fill(&to_X_dis[0],&to_X_dis[1001],INF);
	fill(&from_X_dis[0],&from_X_dis[1001],INF);
	
	dijkstra();
	rev_dijkstra();
	
	/*
	for(int i = 1 ; i <= N ; i++){
		cout << from_X_dis[i] << '\n';
	}
	
	for(int i = 1 ; i <= N ; i++){
		cout << to_X_dis[i] << '\n';
	}
	*/
	
	int max_dis = 0;
	for(int i = 1 ; i <= N ; i++){
		max_dis = max_dis > (to_X_dis[i]+from_X_dis[i]) ? max_dis : (to_X_dis[i]+from_X_dis[i]);
	}
	
	printf("%d\n",max_dis);
	
	return 0;
}