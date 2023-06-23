#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

int move(int map[][20],int t);

int main(){
	/*
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);*/
	
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
	
	if(t == 0){
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
	vector<int> v;
	int n_map[20][20];
	bool is_merged[20];
	
	for(int i = 0 ; i < 4 ; i++){
		v.clear();
		memset(is_merged,0,sizeof(is_merged));
		memset(n_map,0,sizeof(n_map));
		if(i != 0){// map의 값들을 90도 돌린 위치에 둬서 무조건 위로 올리는 식으로 해도 모든 경우를 할 수 있도록 만들기
			for(int a = 0 ; a < N ; a++){
				for(int b = a ; b < N - a ; b++){
					int t = map[a][b];
					map[a][b] = map[N-b-1][a];
					map[N-b-1][a] = map[N-b-1][N-a-1];
					map[N-b-1][N-a-1] = map[b][N-a-1];
					map[b][N-a-1] = t;
				}
			}
			
		}
		cout << "ln60\n";
		
		//여기부터가 뭔가 잘못됨
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if(map[i][j] != 0){
					v.push_back(map[i][j]);
				}
			}
			
			int t= 0;
			for(int j = 0 ; j < v.size() - 1 ; j++){
				if(!is_merged[j]){
					if(v[j] == v[j+1]){
						n_map[i][t] = 2*v[j];
						is_merged[j+1] = true;
					}
					else{
						n_map[i][t] = v[j];
					}
					t++;
				}
			}
		}
		
		temp = move(n_map,t-1);
		if(temp > ret)	ret = temp;
	}
	
	return ret;
}