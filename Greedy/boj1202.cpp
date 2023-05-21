#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
bool is_filled_pack[300000];
vector<int> backpack;
vector<pair<int,int>> info;

bool compare(pair<int,int>& a,pair<int,int>& b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&N,&K);
	
	int w,v;
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&w,&v);
		info.push_back({w,v});
	}
	
	for(int i = 0 ; i < K ; i++){
		scanf("%d",&w);
		backpack.push_back(w);
	}
	
	sort(backpack.begin(),backpack.end());
	sort(info.begin(),info.end(),compare);
	
	long long ans = 0;
	int f_pos = 0;
	for(int i = 0 ; i < info.size() ; i++){
		//위치 잡는걸 이분탐색으로 바꿔야할듯
		for(int j = f_pos ; j < backpack.size() ; j++){
			if(backpack[j] >= info[i].first && !is_filled_pack[j]){
				if(j == f_pos)	f_pos++;
				is_filled_pack[j] = true;
				ans += info[i].second;
				break;
			}
		}
	}
	
	
	printf("%lld\n",ans);
	return 0;
}

bool compare(pair<int,int>& a,pair<int,int>& b){
	return a.second > b.second;
}