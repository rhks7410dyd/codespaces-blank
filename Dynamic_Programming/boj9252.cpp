#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string a,b;
int asize,bsize;
int dp[1010][1010];

void Solve(int a_p,int b_p);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	
	asize = a.size();
	bsize = b.size();

	for(int i = 1 ; i < asize ; i++){
		for(int j = 1 ; j < bsize ; j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + 1;
				continue;
			}
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	int col = asize-1;
	int row = bsize-1;
	string result = "";
	while (dp[col][row]) {
		if (dp[col][row] == dp[col - 1][row]) {
			col--;
		}
		else if (dp[col][row] == dp[col][row - 1]) {
			row--;
		}
		else {
			result += a[col];
			row--, col--;
		}
	}
	
	
	int ans = dp[asize-1][bsize-1];
	cout << ans << '\n';
	if(result.size() > 0){
		reverse(result.begin(),result.end());
		cout << result << '\n';
	}
	
	return 0;
}
