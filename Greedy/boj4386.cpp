#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {
    bool operator()(pair<pair<int,int>,double>& a, pair<pair<int,int>,double>& b) {
        return a.second > b.second;
    }
};

priority_queue<pair<double,pair<int,int>>> edge;
double pos[100][2];
double sum=0;
bool is_make_cycle(int a,int b);
int uni[100];
int get_uni(int a);
void merge(int a,int b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	
	cin >> n;
	
	float a,b;
	for(int i = 0 ; i < n ; i++){
		cin >> pos[i][0] >> pos[i][1];
		uni[i] = i;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ;j++){
			double temp = (pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]);
			edge.push({-temp,{i,j}});
		}
	}
	
	while(!edge.empty()){
		double now_val = -edge.top().first;
		auto nodes = edge.top().second;
		edge.pop();
		if(!is_make_cycle(nodes.first, nodes.second)){
			sum += sqrt(now_val);
			merge(nodes.first,nodes.second);
		}
	}
	
	cout << sum << '\n';
	return 0;
}

int get_uni(int a){
	if(a != uni[a])	return uni[a] = get_uni(uni[a]);
	return a;
}

bool is_make_cycle(int a,int b){
	a = get_uni(a);
	b = get_uni(b);
	return a == b ? true : false;
}

void merge(int a,int b){
	a = get_uni(a);
	b = get_uni(b);
	if(a==b) return;
	uni[b] = a;
}