/*
최소 비용에 대한 배열을 스트링,인트 페어로 만들어서 경로를 저장하고, 이후 도착 경로의 스트링의 사이즈가 지나는 도시의 개수, 순서대로 출력을 하면 된다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 1e9

using namespace std;

long long d[1001];
int visit[1001];
vector<pair<int,int>> edge[1001];
vector <int> path;
int n,m,start_node,end_node;

void Dijkstra();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	int ts,te,tv;
	for(int i = 0 ; i < m ; i++){
		cin >> ts >> te >> tv;
		edge[ts].push_back(make_pair(te,tv));
	}
	
	cin >> start_node >> end_node;
	
	Dijkstra();
	
	int t = end_node;
	while(t){
		path.push_back(t);
		t = visit[t];
	}
	
	cout << d[end_node] << '\n' << path.size() << '\n';
	for(int i = path.size() - 1 ; i >= 0 ; i--){
		cout << path[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}

void Dijkstra(){
	fill(&d[0],&d[1000],INF);
	
	priority_queue<pair<long long,int>>pq;
    pq.emplace(0,start_node);
    d[start_node] =0;
	visit[start_node] = 0;
	 
	while(!pq.empty()){
        long long dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
		if(now == end_node){
			break;
		}
        
        if(d[now] < dist)
            continue;

        for(int i = 0 ; i < edge[now].size() ; i++){
			int next = edge[now][i].first;
            long long cost = dist + edge[now][i].second;
            if(cost < d[next]){
				d[next] = cost;
                visit[next] = now;
                pq.emplace(-cost,next);
            }
        }
    }
}