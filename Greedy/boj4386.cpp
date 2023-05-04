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
bool visit[100];
bool is_make_cycle(int a,int b);
int uni[100];
int get_uni(int a);

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
		auto now = edge.top();
		edge.pop();
		if(!is_make_cycle(now.second.first, now.second.second) && !(visit[now.second.first] && visit[now.second.second])){
			sum += sqrt(-now.first);
			visit[now.second.first] = true;
			visit[now.second.second] = true;
		}
	}
	
	cout << sum << '\n';
	return 0;
}

int get_uni(int a){
	if(a != uni[a])	return a = get_uni(a);
	return a;
}

bool is_make_cycle(int a,int b){
	a = get_uni(a);
	b = get_uni(b);
	return a == b ? true : false;
}