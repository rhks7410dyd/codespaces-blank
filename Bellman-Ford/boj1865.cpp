#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<pair<pair<int,int>,int>> Edge;
int d[1001];
int TC,N,M,W;//node 개수

void Input(){
	cin >> N >> M >> W;

	int S,E,T;
	for(int i = 0 ; i < M ; i++){
		cin >> S >> E >> T;
		Edge.push_back({{S,E},T});
		Edge.push_back({{E,S},T});
	}
	
	for(int i = 0 ; i < W ; i++){
		cin >> S >> E >> T;
		Edge.push_back({{S,E},-T});
	}
	
}

bool Bellman_Ford(){
	fill(&d[1],&d[1001],INF);
    d[1] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < Edge.size(); j++)
        {
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;

            if (d[To] > d[From] + Cost) d[To] = d[From] + Cost;
        }
    }
 
    for (int i = 0; i < Edge.size(); i++)
    {
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;

        if (d[To] > d[From] + Cost){
            return true;
        }
    }
	return false;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> TC;
	
	for(int t = 0 ; t < TC ; t++){
		Input();
		
		bool time_travel = Bellman_Ford();
		
		if(time_travel)	cout << "YES\n";
		else	cout << "NO\n";
		
		Edge.clear();
	}
	
	return 0;
}