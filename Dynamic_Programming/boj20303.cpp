//시간 초과! DP 배열을 1차원 K에 대한 배열로 만들어도 풀 수 있다는데, 어떻게 하는지 모르게씀

#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int n,M,k;
int Uni[30001];
int candy[30001];
int DP[3000];

int get_root(int a);
int get_max(int num,int k);
void merge_set(int a,int b);
map<int,pair<int,int>> m;
vector<pair<int,int>> info;

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

	/*
	for(int i = 1 ; i <= n ; i++){
		cout << "i : " << i << "	Uni : " << Uni[i] << '\n'; 
	}
	*/
	
	memset(DP,-1,sizeof(DP));
	
	int ans = get_max(0,k);
	
	cout << ans << '\n';
	
	return 0;
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

int get_max(int num,int k){
	if(num == info.size())	return 0;
	
	if(info[num].second >= k)	return get_max(num+1,k);
	
	int& ret = DP[k];
	if(ret != -1)	return ret;
	
	ret = max(get_max(num+1,k-info[num].second)+info[num].first,get_max(num+1,k));
	
	return ret;
}