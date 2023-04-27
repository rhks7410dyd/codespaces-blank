#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v;
int P[5][5] ={
	{2,2,2,2,2},
	{-1,1,3,4,3},
	{-1,3,1,3,4},
	{-1,4,3,1,3},
	{-1,3,4,3,1}
};
int dp[5][5][100000];

int Solve(int i,int foot_1,int foot_2);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while(true){
		int temp;
		scanf("%d",&temp);
		
		if(temp == 0)	break;
		
		v.push_back(temp);
	}
	
	memset(&dp[0][0][0],-1,sizeof(dp));
	
	int ans = Solve(0,0,0);
	
	printf("%d\n",ans);
	
	
	return 0;
}

int Solve(int i,int foot_1,int foot_2){
	if(i == v.size()) return 0;
	if(foot_1 > foot_2){
		int tmp = foot_1;
		foot_1 = foot_2;
		foot_2 = tmp;
	}
	int& ret = dp[foot_1][foot_2][i];
	if(ret != -1)	return ret;
	
	int nxt_pos = v[i];
	
	if(nxt_pos == foot_1)	ret = Solve(i+1,foot_1,foot_2)+P[foot_1][nxt_pos];
	else if(nxt_pos == foot_2)	ret = Solve(i+1,foot_1,foot_2)+P[foot_2][nxt_pos];
	else	ret = min(Solve(i+1,v[i],foot_2)+P[foot_1][v[i]],Solve(i+1,foot_1,v[i])+P[foot_2][v[i]]);
	
	return ret;
}

/*
https://www.acmicpc.net/source/59911346
어떤식으로 구성된 코드인지 모르겠음

#include <iostream>
using namespace std;

int q, arr[2][5][5];
int arr2[5][5]{
	{ 1, 2, 2, 2, 2 },
	{ 3, 1, 3, 4, 3 },
	{ 3, 3, 1, 3, 4 },
	{ 3, 4, 3, 1, 3 },
	{ 3, 3, 4, 3, 1 }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[0][i][j] = 1 << 30;
		}
	}
	arr[0][0][0] = 0;
	for (int i = 1; 1; i++) {
		cin >> q;
		if (!q) {
			q = 1 << 30;
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					q = min(q, arr[(i + 1) & 1][j][k]);
				}
			}
			cout << q << '\n';
			return 0;
		}
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				arr[i & 1][j][k] = 1 << 30;
			}
		}
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (j == k) {
					continue;
				}
				if (j == q) {
					for (int l = 0; l < 5; l++) {
						arr[i & 1][j][k] = min(arr[i & 1][j][k], arr[(i + 1) & 1][l][k] + arr2[l][j]);
					}
				}
				if (k == q) {
					for (int l = 0; l < 5; l++) {
						arr[i & 1][j][k] = min(arr[i & 1][j][k], arr[(i + 1) & 1][j][l] + arr2[l][k]);
					}
				}
			}
		}
	}
	return 0;
}
*/