#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double dp[100][50];//dp[days][town_num]
int map[50][51];//map[town_A][50] means how many town is linked with town_A.
int C,n,d,p,t;
double get_answer(int town_num,int day);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> C;
	cout << fixed;
	cout.precision(8);
	for(int c = 0 ; c < C ; c++){
		cin >> n >> d >> p;
		for(int i = 0 ; i < n ; i++){
			int cnt = 0;
			for(int j = 0 ; j < n ; j++){
				cin >> map[i][j];
				if(map[i][j]) cnt++;
			}
			map[i][50] = cnt;
		}
		fill(&dp[0][0],&dp[99][50],-1.5);
		
		cin >> t;
		int temp;
		vector<int> ans_town;
		for(int i = 0 ; i < t ; i++){
			cin >> temp;
			ans_town.push_back(temp);
		}
		//입력부 끝
		
		for(int i = 0 ; i < t ; i++){
			double ans = get_answer(ans_town[i],d);
			cout << ans << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

double get_answer(int town_num,int day){
	if(day == 0)	return town_num == p ? 1.0 : 0.0;
	
	double& ret = dp[day][town_num];
	if(ret > -1)	return ret;
	
	ret = 0;
	for(int i = 0 ; i < n ; i++){
		if(map[town_num][i] == 1){
			ret += get_answer(i,day-1)/map[i][50];
		}
	}
	return ret;
}
