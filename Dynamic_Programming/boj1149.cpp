#include <iostream>
#include <algorithm>
#define Red 0
#define Green 1
#define Blue 2

using namespace std;

int info[1001][3];
int DP[1001][3];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	
	cin >> N;
	
	for(int i = 1 ; i <= N ; i++){
		cin >> info[i][0] >> info[i][1] >> info[i][2];//R G B
	}
	
	DP[1][Red] = info[1][Red];
	DP[1][Green] = info[1][Green];
	DP[1][Blue] = info[1][Blue];
	
	for(int i = 2 ; i <= N ; i++){
		DP[i][Red] = min(DP[i-1][Green],DP[i-1][Blue]) + info[i][Red];
		DP[i][Green] = min(DP[i-1][Red],DP[i-1][Blue]) + info[i][Green];
		DP[i][Blue] = min(DP[i-1][Green],DP[i-1][Red]) + info[i][Blue];
	}
	
	cout << min({DP[N][0],DP[N][1],DP[N][2]}) << endl;
	
	return 0;
}