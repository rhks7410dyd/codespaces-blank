#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 초과 뜸
int V,E;
int root [10010],edge_count=0;
vector<pair<int,pair<int,int>>> edge;

int find_root(int a);
bool compare(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b);
bool Is_union(int a,int b);

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
	
	if(V==2){
		printf("0\n");
		return 0;
	}
	root[edge[0].second.first] = edge[0].second.second;
	long long ans = edge[0].first;
	for(int i = 1 ; i < E ; i++){
		if(edge_count == V-2)	break;
		auto now = edge[i];
		if(Is_union(now.second.first,now.second.second)){
			continue;
		}
		
		edge_count++;
		ans+=now.first;
	}
	
	printf("%lld\n",ans);
	
	return 0;
}

bool compare(pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
	return a.first < b.first;
}

int find_root(int a){
	if(root[a] == a)	return a;
	
	return root[a] = find_root(root[a]);//앞에 root[a]를 없애면 52ms -> 448ms로 시간이 몇배나 뛰어버림. 좋은 디테일
}

bool Is_union(int a,int b){
	a = find_root(a);
	b = find_root(b);
	if(a == b)	return true;
	root[b] = a;
	return false;
}
