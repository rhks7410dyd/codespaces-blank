#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int dp[1<<16][16];
int map[16][16];
int n;

void Input();
void Solve();
int dfs(int pos,int set);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Input();
	Solve();
	
	return 0;
}

void Input(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}
}

void Solve(){
	memset(&dp[0][0],-1,sizeof(dp));
	cout << dfs(0,0) << '\n';
	return ;
}

int dfs(int pos,int set){
	if(set == (1<<n)-1){
		return 0;
	}
	
	int& ret = dp[set][pos];
	if(ret != -1)	return ret;
	
	ret = INF;
	
	for(int i = 0 ; i < n ; i++){
		if(i == pos || set&(1<<i) != 0 || !map[pos][i])	continue;
		
		ret = min(ret,map[pos][i]+dfs(i,set|(1<<i)));
	}
	
	return ret;
}