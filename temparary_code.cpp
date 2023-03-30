#include <iostream>
#include <queue>

using namespace std;

int K,cnt=0;
priority_queue<int,vector<int>,less<int>> l_q;
priority_queue<int,vector<int>,greater<int>> g_q;

int main(){
	cin >> K;
	for(int i = 0 ; i < K ; i++){
		int t;
		cin >> t;
		l_q.push(t);
	}
	for(int i = 0 ; i < K ; i++){
		cout << l_q.top() << '\n';
		l_q.pop();
	}
	
	return 0;
}