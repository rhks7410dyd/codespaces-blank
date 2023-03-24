#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 초과 뜸
int V,E;
int root [10010];
vector<pair<int,pair<int,int>>> edge;

int find_root(int a);
bool compare(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b);
void union_(int a,int b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d", &V,&E);
	
	for(int i = 0 ; i <= V ; i++){
		root[i] = i;
	}
	
	for(int i = 0 ; i < E ; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge.push_back({c,{a,b}});
	}
	
	sort(edge.begin(),edge.end(),compare);
	//edge를 힙으로 구현하면 확실히 더 빨라지긴 할듯
	
	root[edge[0].second.first] = edge[0].second.second;
	long long ans = edge[0].first;
	for(int i = 1 ; i < E ; i++){
		auto now = edge[i];
		int root_first = find_root(now.second.first);
		int root_second = find_root(now.second.second);
		if(root_first == root_second)	continue;
		ans += now.first;
		root[root_first] = root_second;
	}
	
	printf("%lld\n",ans);
	
	return 0;
}

bool compare(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
	return a.first < b.first;
}

int find_root(int a){
	if(root[a] == a)	return a;
	
	return find_root(root[a]);
}

void union_(int a,int b){
	a = find_root(a);
	b = find_root(b);
	root[b] = a;
}