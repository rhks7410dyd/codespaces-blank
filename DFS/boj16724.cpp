#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000];
int num_of_piece[1000][1000];
int n,m;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> map[i][j];
		}
	}
	
	//굳이 직접 돌지 않아도 되는듯, 조각이 총 몇개인지가 중요함.
	int piece_num = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m; j++){
			if(num_of_piece[i][j])	continue;
			
			//일단 임의의 번호로 붙여주고, 더 낮은 번호로 통하게 된다면 그 번호로 통합되게 임의의 번호를 줌
			int t_num = piece_num;
			
			num_of_piece[i][j] = t_num;
			int next_c = i;
			int next_r = j;
			while(!num_of_piece[next_c][next_r]){
				
			}
			
			
		}
	}
	
	return 0;
}