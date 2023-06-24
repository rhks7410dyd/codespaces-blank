#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

int move(int map[][20],int t);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int map[20][20];
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> map[i][j];
		}
	}
	
	int ans = move(map,5);
	
	cout << ans << '\n';
	
	return 0;
}

int move(int map[][20],int t){
	int ret = 0;
	
	if(t == 2){
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if(ret < map[i][j])	ret = map[i][j];
			}
		}
		
		return ret;
	}
	
	cout << "T " << t << '\n';
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	
	int temp;
	
	for(int I = 0 ; I < 4 ; I++){
		int n_map[20][20];
		if(I != 2){// map의 값들을 90도 돌린 위치에 둬서 무조건 위로 올리는 식으로 해도 모든 경우를 할 수 있도록 만들기
			for(int a = 0 ; a < N/2 + 1 ; a++){
				for(int b = a ; b < N - a - 1 ; b++){
					int t = map[a][b];
					map[a][b] = map[N-b-1][a];
					map[N-b-1][a] = map[N-a-1][N-b-1];
					map[N-a-1][N-b-1] = map[b][N-a-1];
					map[b][N-a-1] = t;
				}
			}
			
		}
		
		//여기부터가 뭔가 잘못됨
		for(int j = 0 ; j < N ; j++){
			vector<int> v;
			for(int i = 0 ; i < N ; i++){
				if(map[i][j] != 0) v.push_back(map[i][j]);
			}
			
			bool is_merged[20];
			int t = 0;
			for(int i = 0 ; i < v.size() ; i++){
				if(is_merged[i])	continue;
				
				if(i != v.size() - 1 && v[i] == v[i+1]){
					n_map[t][j] = 2*v[i];
					t++;
					is_merged[i+1] = true;
				}
				else{
					n_map[t][j] = v[i];
					t++;
				}
			}
		}
		
		temp = move(n_map,t-1);
		if(temp > ret)	ret = temp;
	}
	
	return ret;
}