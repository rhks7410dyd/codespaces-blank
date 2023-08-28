//9:41
#include <iostream>
#define INF 123456*2+2

using namespace std;

bool eratoth[INF];
//int dp[INF][INF];

void Solve(){
	for(int i = 2 ; i < INF/2 + 2 ; i++){
		if(!eratoth[i]){
			int temp = 2*i;
			while(temp < INF){
				eratoth[temp] = true;
				temp += i;
			}
		}
	}
	eratoth[1] = true;
	
	while(true){
		int n;
		cin >> n;

		if(!n)	return;
		int count = 0;
		for(int i = n + 1 ; i <= 2*n ; i++){
			if(!eratoth[i])	count++;	
		}
		
		cout << count << '\n';
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Solve();
	
	return 0;
}