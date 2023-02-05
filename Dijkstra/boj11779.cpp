/*
최소 비용에 대한 배열을 스트링,인트 페어로 만들어서 경로를 저장하고, 이후 도착 경로의 스트링의 사이즈가 지나는 도시의 개수, 순서대로 출력을 하면 된다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 987654321

using namespace std;

pair<int,string> d[1001];
vector<pair<int,int>> edge[1001];
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
		edge[ts].push_back({te,tv});
	}
	
	cin >> start_node >> end_node;
	
	Dijkstra();
	
	cout << d[end_node].first << '\n' << d[end_node].second.size() << '\n';
	for(int i = 0 ; i < d[end_node].second.size() ; i++){
		cout << d[end_node].second[i] << ' ';
	}
	
	return 0;
}

void Dijkstra(){
	fill(&d[0],&d[1000],make_pair(INF,""));
	
	priority_queue<pair<int,int>>pq;
    pq.push({0,start_node});
    d[start_node].first =0;
	d[start_node].second = to_string(start_node);
    
	while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
		if(now == end_node){
			break;
		}
        
        if(d[now].first < dist)
            continue;

        for(int i = 0 ; i < edge[now].size() ; i++){
            int cost = dist + edge[now][i].second;
            if(cost < d[edge[now][i].first].first){
				d[edge[now][i].first].first = cost;
                d[edge[now][i].first].second = d[now].second + to_string(edge[now][i].first);
                pq.push(make_pair(-cost,edge[now][i].first));
            }
        }
    }
}