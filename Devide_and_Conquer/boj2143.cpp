#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,n,m;
long long subsum[2][1001];
vector<long long> subset;
bool can_get_T(long long S);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> subsum[0][i];
		subsum[0][i] += subsum[0][i-1];
	}
	cin >> m;
	for(int i = 1 ; i <= m ; i++){
		cin >> subsum[1][i];
		subsum[1][i] += subsum[1][i-1];
	}
	
	for(int i = 0 ; i < m ; i++){
		for(int j = i + 1 ; j <= m ; j++){
			subset.push_back(subsum[1][j] - subsum[1][i]);
		}
	}
	sort(subset.begin(),subset.end());
	
	long long ans = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			int a_sum = subsum[0][j] - subsum[0][i];
			int tar = T - a_sum;
			int lo = lower_bound(subset.begin(), subset.end(), tar) - subset.begin();
			int hi = upper_bound(subset.begin(), subset.end(), tar) - subset.begin();
			ans += hi-lo;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}

