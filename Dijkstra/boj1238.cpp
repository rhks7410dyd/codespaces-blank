#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
//처음에 플로이드 워셜을 쓰려고 했는데, (10^3)^3 = 10억 이므로 시간초과가 뜰 수 있다는 감이 강하게 든다. 따라서 데이크스트라 알고리즘을 이용하여 특정 X노드까지의 최단거리만 구하는 것이 합당하지 않을까? 란 생각이 들었기에
//플로이드 워셜이 아닌 데이크스트라를 사용한다.
//c++에서는 플로이드 워셜로 충분히 풀린다는 질답 내용을 백준에서 봤지만, 의도가 데이크스트라의 응용이므로 데이크스트라로 풀기

using namespace std;

struct info{
	int node,val;
	
	info(int a,int b){
		node = a;
		val = b;
	}
	
	//밑에 있는 구조체 오퍼레이터 함수가 왜 안되는지 확인해봐야할듯. 이에 관한 공부가
	//이후에도 유용하다고 생각됨!
	bool operator<(const info &in) const{
		if(in.val != val){
			return val < in.val;
		}
		return node < in.node;
	}
	/*
	bool operator==(const info in) const{
		return this->node == in.node && this->val == in.val;
	}*/
};

vector<info> map[1001]; 
vector<info> rev_map[1001];
int N,M,X;
int to_X_dis[1001];
int from_X_dis[1001];

void dijkstra(){//노드 X에서 i까지 최단 거리를 구하는 데이크스트라 함수
	to_X_dis[X] = 0;
	priority_queue <info> pq;
	pq.push({X,0});
	while(!pq.empty()){
		auto temp = pq.top();
	}
}

void rev_dijkstra(){//노드 i에서 X까지 최단 거리를 구하는 데이크스트라 함수
	
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	scanf("%d %d %d",&N,&M,&X);
	
	fill(&map[1][1],&map[1000][1001],INF);
	fill(&rev_map[1][1],&rev_map[1000][1001],INF);
	
	int sn,en,val;
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d %d",&sn,&en,&val);
		map[sn].push_back({en,val});
		rev_map[en].push_back({sn,val});
	}
	
	//dijkstra();
	//fill(&visit[1],&visit[1001],false);
	//rev_dijkstra();
	priority_queue <info> pq;
	pq.push({1,2});
	pq.push({1,3});
	pq.push({2,5});
	pq.push({3,1});
	for(int i = 0 ; i < 4 ; i++){
		cout << pq.top().node << " " << pq.top().val << '\n';
		pq.pop();
	}
	
	
	/*
	int max_dis = -1;
	for(int i = 1 ; i <= N ; i++){
		max_dis = max_dis > (to_X_dis[i]+from_X_dis[i]) ? max_dis : (to_X_dis[i]+from_X_dis[i]);
	}
	
	printf("%d\n",max_dis);
	*/
	return 0;
}