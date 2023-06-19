#include <iostream>
#include <queue>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		priority_queue<int> pq;
		int n,t;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> t;
			pq.push(-t);
		}
		
		int ans = 0;
		for(int i = 0 ; i < n - 1 ; i++){
			int n1 = -pq.top();
			pq.pop();
			int n2 = -pq.top();
			pq.pop();
			
			int now = n1+n2;
			pq.push(-now);
			ans += now;
		}
		
		if(!ans)	ans = -pq.top();
		cout << ans << '\n';
	}
	
	return 0;
}