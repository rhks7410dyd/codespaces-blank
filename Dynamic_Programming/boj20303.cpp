#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n,M,k;
int Uni[30001];
int candy[30001];
int dp[2][3000];
map<int,pair<int,int>> m;
vector<pair<int,int>> info;

int get_root(int a);
void merge_set(int a,int b);
bool compare(pair<int,int>& a,pair<int,int>& b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> M >> k;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> candy[i];
		Uni[i] = i;
	}
	
	int a,b;
	for(int i = 0 ; i < M ; i++){
		cin >> a >> b;
		merge_set(a,b);
	}
	
	for(int i = 1 ; i <= n ; i++){
		int r = get_root(i);
		if (m.find(r) != m.end()) {
			m[r].first += candy[i];
			m[r].second++;
		}
		else {
			m[r].first = candy[i];
			m[r].second = 1;
		}
	}
	
	for (auto iter : m) {
		info.push_back({iter.second.first,iter.second.second});
	}

	sort(info.begin(),info.end(),compare);
	
	/*
	cout << "-----------------------------------------\n";
	for(int i = 0 ; i < info.size() ; i++){
		cout << info[i].first << ' ' << info[i].second << '\n';
	}
	
	for(int i = 1 ; i <= n ; i++){
		cout << "i : " << i << "	Uni : " << Uni[i] << '\n'; 
	}
	*/
	
	
	for(int i = 0 ; i < info.size() ; i++){
		for(int j = 0 ; j < k ; j++){
			if(j < info[i].second){
				dp[(i+1)%2][j] = dp[i%2][j];
			}
			else{
				dp[(i+1)%2][j] = max(dp[i%2][j],dp[i%2][j-info[i].second]+info[i].first);
			}
		}
	}
	
	int ans = 0;
	int last;
	if(info.size()%2){
		last = 1;
	}
	else{
		last = 0;
	}
	
	for(int i = 0 ; i < k ; i++){
		ans = max(dp[last][i],ans);
	}
	
	cout << ans << '\n';
	
	return 0;
}

bool compare(pair<int,int>& a,pair<int,int>& b){
	double a_val = (double)a.first/a.second;
	double b_val = (double)b.first/b.second;
	if(abs(a_val - b_val) <= 1e-10){
		return a.second < b.second;
	}
	return a_val > b_val;
}

void merge_set(int a,int b){
	a = get_root(a);
	b = get_root(b);
	Uni[b] = a;
}

int get_root(int a){
	if(Uni[a] == a)	return a;
	
	return Uni[a] = get_root(Uni[a]);
}