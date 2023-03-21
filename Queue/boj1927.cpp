#include <iostream>
#include <queue>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,cmd;
	
	cin >> N;
	
	priority_queue<int> pq;
	for(int i = 0 ; i < N ; i++){
		cin >> cmd;
		if(cmd){
			pq.push(-cmd);
		}
		else{
			if(pq.empty()){
				cout << 0 << '\n';
				continue;
			}
			cout << -pq.top() << '\n';
			pq.pop();
		}
	}
}