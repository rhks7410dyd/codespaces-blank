#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int DP[11][101][101];//DP[s][a][b] <=> [a,b) 까지의 s개의 수로 양자화 했을 때 오차 제곱 최소값을 의미
int C,N,S;
vector<pair<int,int>> v;

int get_ans(int start,int end,int s);
int get_squared_error(int start,int end);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> C;
	
	for(int c = 0 ; c < C ; c++){
		cin >> N >> S;
		memset(DP,-1,sizeof(DP));
		
		for(int i = 0 ; i < N ; i++){
			int temp;
			cin >> temp;
			int pos;
			bool exist_val = false;
			for(int j = 0 ; j < v.size() ; j++){
				if(temp == v[j].first){
					exist_val = true;
					pos = j;
					break;
				}
			}
			if(exist_val){
				v[pos].second ++;
			}
			else{
				v.push_back({temp,1});
			}
		}
		
		if(v.size() <= S){
			cout << 0 << '\n';
			continue;
		}
		
		int ans = get_ans(0,v.size(),S);
		
		cout << ans << '\n';
		v.clear();
	}
	
	return 0;
}

int get_ans(int start,int end,int s){
	if(DP[s][start][end] != -1){
		return DP[s][start][end];
	}
	
	if(s == 0)	return 987654321;
	if(end - start <= s){
		DP[s][start][end] = 0;
		return 0;
	}
	if(s == 1){
		DP[s][start][end] = get_squared_error(start,end);
		return DP[s][start][end];
	}
	
	int ret = 987654321;
	for(int i = start + 1 ; i < end ; i++){
		if(DP[1][start][i] != -1){
			DP[1][start][i] = get_squared_error(start,i);
		}
		//if(DP[])
	}
	return 0;
}

int get_squared_error(int start,int end){
	int ret = 0;
	double avarage = 0;
	for(int i = start ; i < end ; i++){
		avarage += v[i].first * v[i].second;
	}
	avarage /= N;
	
	int int_average = (int)(ceil(avarage - 0.5));
	
	for(int i = start ; i < end ; i++){
		int Er = int_average - v[i].first;
		ret += Er*Er*v[i].second;
	}
	
	return ret;
}