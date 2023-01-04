#include <iostream>
#include <algorithm>
#define M_INF -987654321

using namespace std;

int val[125250];
int dp[125250];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N,T;
	cin >> N;

	T = N * (N + 1) / 2;
	for(int i = 0 ; i < T ; i++){
		cin >> val[i];
		//cout << val[i] << endl;
	}
	
	int start_ind=0,now_ind,floor = 1;
	dp[0] = val[0];
	for(int i = 1 ; i < N ; i++){
		start_ind += floor;
		floor++;
		for(int j = 0 ; j <= i ; j++){
			now_ind = start_ind + j;
			if(j == 0){
				dp[now_ind] = dp[now_ind - floor + 1] + val[now_ind];
			}
			else if(j == i){
				dp[now_ind] = dp[now_ind - floor] + val[now_ind];
			}
			else{
				dp[now_ind] = max(dp[now_ind - floor],dp[now_ind - floor + 1]) + val[now_ind];
			}
		}
	}
	
	/*
	cout << "val_arr" << endl;
	start_ind = 0,floor = 0;
	for(int i = 0 ; i < N ; i++){
		start_ind += floor;
		floor++;
		for(int j = 0 ; j <= i ; j++){
			now_ind = start_ind + j;
			cout << val[now_ind] << ' ';
		}
		cout << endl;
	}
	
	cout << "dp val"<<endl;
	start_ind = 0,floor = 0;
	for(int i = 0 ; i < N ; i++){
		start_ind += floor;
		floor++;
		for(int j = 0 ; j <= i ; j++){
			now_ind = start_ind + j;
			cout << dp[now_ind] << ' ';
		}
		cout << endl;
	}	
	*/
	
	int max_val = M_INF;
	for(int i = start_ind ; i < start_ind + N ; i++){
		if(max_val < dp[i]) max_val = dp[i];
	}
	
	cout << max_val << endl;
	
	return 0;
}
