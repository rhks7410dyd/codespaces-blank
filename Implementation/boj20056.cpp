#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct fireball{
	int r,c,m,d,s;
	fireball(int R,int C,int M,int D,int S) : r(R),c(C),m(M),d(D),s(S) {};
	fireball(){
		r = 0;
		c = 0;
		m = 0;
		d = 0;
		s = 0;
	};
};

int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int temp[51][51][4];
int N,M,K;
queue<fireball> q;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	
	int r,c,m,d,s,even;
	for(int i = 0 ; i < M ; i++){
		cin >> r >> c >> m >> d >> s;
		q.push({r,c,m,d,s});
	}
	
	for(int t = 0 ; t < K ; t++){
		int qsize = q.size();
		
		for(int i = 0 ; i < qsize ; i++){
			auto now = q.front();
			q.pop();
			//0,1로 홀작을 구분하면 memset 이나 fill을 사용하기 애매해지기 때문에 1을 홀,2를 짝의 경우로 생각함
			int next_r,next_c;
			next_r = now.r + now.s*dir[now.d][0];
			next_c = now.c + now.s*dir[now.d][1];
			temp[next_r][next_c][0] += now.m;
			temp[next_r][next_c][1] += now.s;
			if(temp[next_r][next_c][2] == -2){
				temp[next_r][next_c][2] = now.d%2;
			}
			else if(now.d == 0){
				if(temp[next_r][next_c][2] == 1){
					temp[next_r][next_c][2] = -1;
				}
			}
			else{
				if(temp[next_r][next_c][2] == 0){
					temp[next_r][next_c][2] = -1;
				}
			}
		}
		
		
	}
	
	return 0;
}

