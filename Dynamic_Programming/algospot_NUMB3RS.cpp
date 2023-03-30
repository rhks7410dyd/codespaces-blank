#include <iostream>
#include <vector>

using namespace std;

double dp[100][50];//dp[days][town_num]
int map[50][51];//map[town_A][50] means how many town is linked with town_A.
int C,n,d,p,t;
vector<int> ans_town;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_wiht_stdio(false);
	
	cin >> C;
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
		
		cin >> t;
		int temp;
		for(int i = 0 ; i < t ; i++){
			cin >> temp;
			ans_town.push_back(temp);
		}
		//입력부 끝
		
		
	}
	
	return 0;
}

//결국 재귀함수를 짜는 과정에서 타겟 마을의 확률 값을 구하는 형식으로 짜는가, 혹은 모든 과정 자체를 연산하느냐로 알고리즘이 바뀔 것임
//하지만 우린 지금 모든 마을에 대해 알 필요가 없기 때문에, 당연하게도 전자의 방식이 더 효율적일 것이라 생각됨.