#include <iostream>
#include <queue>

//세그폴트 떳음
using namespace std;

long long A,B;

void BFS(){
	//cout <<"ln23\n"
	priority_queue<pair<int,long long>> q;
	q.push({1,A});
	while(!q.empty()){
		auto n = q.top();
		if(n.second == B){
			cout << n.first << endl;
			return;
		}
		q.pop();
		
		if(2*n.second <= B){
			q.push({n.first+1 , n.second*2});
		}
		if(10*n.second+1 <= B){
			q.push({n.first+1 , 10*n.second + 1});
		}
	}
	cout << -1 << endl;
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> A >> B;
	
	BFS();

	return 0;
}