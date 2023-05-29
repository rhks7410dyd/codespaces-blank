#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<pair<int,int>,double>& a,pair<pair<int,int>,double>& b){
	return a.second < b.second;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	scanf("%d",&C);
	
	while(C--){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<pair<int,int>> v[20];//지금까지 선호도 총합, 남은 예산
		vector<pair<pair<int,int>,double>> prefer_val;
		
		int mon,prefer;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d",&mon,&prefer);
			prefer_val.push_back({{mon,prefer},(double)mon/prefer});
		}
		sort(prefer_val.begin(),prefer_val.end(),compare);//효율이 좋은 애가 앞으로 옴
		
		
		//얘를 굳이 예산을 다 채울 때까지 돌릴 이유가 없음. 다음 효율이 좋은 애가 무조건 효율이 더 좋아지는 시점 전까지만 계산을 돌리면 됨
		//이 부분을 제대로 다듬어서 전처리 과정을 돌린 이후, 이전 초밥을 0개~그 갯수까지만 dp를 만들어 놓고, 다음 애에서는 거기까지만 보면 되게 만들면 됨
		//처음 초밥만 끝까지 하면 됨(아닌 경우가 있을 수 있음. 이에 대해서도 판단 해봐야됨)
		for(int i = 0 ; i < n ; i++){
			
		}
	}
	
	return 0;
}

/*

*/