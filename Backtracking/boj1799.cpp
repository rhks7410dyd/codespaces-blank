/*
동일한 열에 두 개의 비숍을 둘 수 있기 때문에 2차원 배열로 선언했어야됐는데..귀찮아서 나중에 하고 싶음
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dir[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int map[10][10];
int pos[10];

int get_ans(int idx);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
			pos[j] = -1;
		}
	}
	
	int ans = get_ans(0);
	
	
	cout << ans << '\n';
	
	return 0;
}

int get_ans(int idx){
	if(idx == n){
		return 0;
	}
	
	bool point_pos[10];
	for(int i = 0 ; i < idx ; i++){
		if(pos[i] == -1)	continue;
		if(pos[i] + idx - i < 10){
			point_pos[pos[i] + idx - i] = true;
		}
		if(pos[i] - idx + i >= 0){
			point_pos[pos[i] - idx + i] = true;
		}
	}
	
	int ret = get_ans(idx+1);
	bool can_put_bishop = false;
	for(int i = 0 ; i < n ; i++){
		if(map[idx][i] == 1 && !point_pos[i]){
			can_put_bishop = true;
			pos[idx] = i;
			ret = max(ret,get_ans(idx+1)+1);
			pos[idx] = -1;
		}
	}
	
	return ret;
}