#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
	return a.second > b.second;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		vector<pair<int,int>> info;
		int n,temp = 0,t = 0;
		cin >> n;
	
		for(int i = 0 ; i < n ; i++){
			info.push_back({0,0});
			cin >> info[i].first;
			t += info[i].first;//여기도 아래 주석과 동일 내용
		}
		for(int i = 0 ; i < n ; i++){
			cin >> info[i].second;
		}
		
		sort(info.begin(),info.end(),compare);
		t += info[n-1].second;//굳이 t를 미리 설정하지 않더라도, 마지막에 비교할 수 있기 때문에 이렇게 할 필요 없음
		
		for(int i = 0 ; i < n ; i++){
			temp += info[i].first;
			if(temp + info[i].second > t)	t = temp + info[i].second;
		}
		
		cout << t << '\n';
	}
	
	return 0;
}