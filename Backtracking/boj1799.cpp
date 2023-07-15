/*
검은칸에 있는 비숍은 검은 칸에 있는 애들끼리만 상호작용을 함을 이용하면 된다고함
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF -987654321

using namespace std;

int n;
int dir[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
int map[10][10];
int pos[10][10];

int get_ans(int c,int r,bool put_bishop);
bool can_put_bishop(int r,int c);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}
	
	int ans = get_ans(0,0,false);
	if(map[0][0] == 1){
		pos[0][0] = 1;
		ans = min(ans,get_ans(0,0,true)+1);
	}
	
	cout << ans << '\n';
	
	return 0;
}

/*
100개의 모든 칸에 대하여 그 칸에 비숍이 들어간 경우와 들어가지 않은 경우를 모두 재귀로 불러들임.
그래서 그 칸에 비숍을 두지 못한다면 INF를 즉시 리턴하도록 설정
dp를 이용해도 나쁘지 않을 거 같기도 하다고 느꼇지만, 필요한 용량이 너무 커져서 안됨
*/
//여기 계산 어디서 하나 더 해지는 기분
//https://www.acmicpc.net/board/view/103135
//위 링크 반례에서 시간 복잡도를 망쳐버림
int get_ans(int r,int c,bool put_bishop){
	int ret = INF;
	if(r == n - 1 && c == n-1){
		if(put_bishop){
			if(can_put_bishop(r,c))	return 0;
			else	return INF;
		}
		return 0;
	}
	
	if(put_bishop && !can_put_bishop(r,c)){
		return INF;
	}
	
	int nr = r, nc = c + 1;
	if(nc == n){
		nr = r + 1;
		nc = 0;
	}
	
	if(map[nr][nc] == 1){
		pos[nr][nc] = 1;
		ret = max(ret,get_ans(nr,nc,true)+1);
		pos[nr][nc] = 0;
	}
	ret = max(ret,get_ans(nr,nc,false));
	
	return ret;
}

bool can_put_bishop(int r,int c){
	for(int d = 0 ; d < 4 ; d++){
		int nr = r;
		int nc = c;
		while(nr >= 0 && nr < n && nc >= 0 && nc < n){
			nr += dir[d][0];
			nc += dir[d][1];
			if(pos[nr][nc])	return false;
		}
	}
	return true;
}