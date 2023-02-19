/*
동일 제목의 다른 문제와 차이점이 있지만, 크게 차이는 없다. 그 문제를 참고할 것(1967)
그리고 입력의 경우에는 여러 단계로 나누는 방식으로 하는 것이 간단하기에, 많이 사용해야한다. 따라서 scanf를 사용하는 것을 추천함.
이후 복습할 때 stack stl을 사용하는 방식으로도 구현해보기!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> v[100001];
bool visit[100001];
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

int main(){
	scanf("%d",&n);
	
	int a,b,r;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&a);
		while(true){
			scanf("%d",&b);
			if(b == -1) break;
			scanf("%d",&r);
			v[a].push_back({b,r});
			v[b].push_back({a,r});
		}
	}
	
	
	DFS(1,0);
	
	fill(&visit[0],&visit[100001],false);
	
	result = 0;
	DFS(end_p,0);
	
	printf("%d\n",result);
	
	return 0;
}