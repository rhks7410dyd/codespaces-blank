#include <iostream>
#include <queue>

using namespace std;

struct cmp{
bool operator()(pair<int, int>&a, pair<int, int>&b) {
              if (a.first == b.first) {
                  return a.second > b.second;
              }
              else {
                  return a.first > b.first;
              }
          }
};
/*
bool compare(pair<int,bool>& a,pair<int,bool>& b){
	if(a.first != b.first){
		return a.first < b.first;
	}
	if(a.second == b.second	|| a.second && !b.second)	return true;
	return false;
}
*/

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	for(int i = 0 ; i < N ; i++){
		int order;
		cin >> order;
		if(order == 0){
			if(pq.empty()){
				cout << 0 <<'\n';
				continue;
			}
			if(pq.top().second < 0){
				cout << -1*pq.top().first << '\n';
			}
			else{
				cout << pq.top().first << '\n';
			}
			pq.pop();
			
			continue;
		}
		
		if(order < 0){
			pq.push({-1*order,-1});
		}
		else{
			pq.push({order,1});
		}
	}
	
	return 0;
}