#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
pair<int,int> info[501][501];
int dp[501][501];
int Solve(int start,int end);

void print(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << dp[i][j] <<  ' ';
		}
		cout << endl;
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << "{ " << info[i][j].first << " , " << info[i][j].second << " } ";
		}
		cout << endl;
	}
	
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	fill(&info[0][0],&info[500][501],make_pair(-1,-1));
	fill(&dp[0][0],&dp[500][501],-1);
	
	for(int i = 0 ; i < N ; i++){
		cin >> info[i][i].first >> info[i][i].second;
	}
	
	Solve(0,N-1);
	
	cout << dp[0][N-1] << '\n';
	//print();
	
	return 0;
}

int Solve(int start,int end){
	if(dp[start][end] != -1)	return dp[start][end];
	
	if(start == end){
		return dp[start][end] = 0;
	}
	
	if(end - start == 1){
		dp[start][end] = info[start][start].first*info[start][start].second*info[end][end].second;
		info[start][end] = make_pair(info[start][start].first,info[end][end].second);
		return dp[start][end];
	}
	
	int ret = 987654321,temp,best_n,best_m;
	for(int i = start ; i < end ; i++){
		if(dp[start][i] == -1)	dp[start][i]=Solve(start,i);
		if(dp[i+1][end] == -1)	dp[i+1][end]=Solve(i+1,end);
		temp = info[start][i].first*info[start][i].second*info[i+1][end].second + dp[start][i] + dp[i+1][end];
		if(temp < ret){
			ret = temp;
			best_n = info[start][i].first;
			best_m = info[i+1][end].second;
		}
	}
	
	dp[start][end] = ret;
	info[start][end] = make_pair(best_n,best_m);
	return ret;
}