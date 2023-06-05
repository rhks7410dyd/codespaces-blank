#include <iostream>
#include <vector>

using namespace std;

double table[50][50];
double dp[5][50];
int time[50];
int n,m,k;


int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d %d",&n,&m,&k);
		
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&time[i]);
		}
		
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				scanf("%lf",&table[i][j]);
			}
		}
		
		int t;
		vector<int> f_song;
		for(int i = 0 ; i < m ; i++){
			scanf("%d",&t);
			f_song.push_back(t);
		}
		
		for(int i = 0 ; i < n ; i++)	dp[time[0]][i] = table[0][i];
		for(int i = 0 ; i < time[0] ; i++)	dp[i][0] = 1;
		
		
		for(int i = time[0] + 1 ; i < k ; i++){
			//슬라이딩 윈도 기법을 사용해야됨
			//이전 문제 보면서 생각해보기
			for(int j = 0 ; j < n ; j++){
				if()
			}
		}
		
		
	}
	
	return 0;
}