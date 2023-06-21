#include <iostream>
#include <utility>

using namespace std;

pair<int,int> start;
pair<int,int> e;
pair<pair<int,int>,int> planet[50];

bool is_counted(int num);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T,n;
	cin >> T;
	
	while(T--){
		cin >> start.first >> start.second >> e.first >> e.second;
		cin >> n;
		
		for(int i = 0 ; i < n ; i++){
			cin >> planet[i].first.first >> planet[i].first.second >> planet[i].second;
		}
		
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(is_counted(i)){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}

bool is_counted(int num){
	auto now = planet[num];
	int r = now.second*now.second;
	int dx_s = now.first.first - start.first;
	int dy_s = now.first.second - start.second;
	int dx_e = now.first.first - e.first;
	int dy_e = now.first.second - e.second;
	int d_s = dx_s*dx_s + dy_s*dy_s;
	int d_e = dx_e*dx_e + dy_e*dy_e;
	
	if(d_s <= r && d_e <= r)	return false;
	if(d_s <= r || d_e <= r)	return true;
	return false;
}