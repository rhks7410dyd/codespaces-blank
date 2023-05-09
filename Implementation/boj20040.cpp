#include <iostream>
#include <vector>

using namespace std;

int parent[500001];
int n,m;
vector<pair<int,int>> v;
bool is_make_cycle(int x,int y);
void merge(int x,int y);
int get_parent(int x);
void print_parent(){
	for(int i = 0 ; i < n ; i++){
		printf("%d ",parent[i]);
	}
	printf("\n");
}


int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; i++){
		parent[i] = i;
	}
	for(int i = 0 ; i < m ; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back({a,b});
	}
	
	int cnt = 0;
	for(int i = 0 ; i < m ; i++){
		int x = v[i].first;
		int y = v[i].second;
		
		if(is_make_cycle(x,y)){
			printf("%d\n",(i+1));
			return 0;
		}
		merge(x,y);
	}
	
	
	printf("0\n");
	return 0;
}

bool is_make_cycle(int x,int y){
	x = get_parent(x);
	y = get_parent(y);
	
	if(x == y)	return true;
	return false;
}
void merge(int x,int y){
	x = get_parent(x);
	y = get_parent(y);
	
	parent[y] = x;
}
int get_parent(int x){
	if(x != parent[x])	return x = get_parent(parent[x]);
	return x;
}

