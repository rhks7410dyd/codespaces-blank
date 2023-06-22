/*
단순하게 빼준다고 되는게 아님
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	int slide[100000][2];
	int d[100000];
	long long ans=0;
	int max_d = 0,skip;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> slide[i][0] >> slide[i][1];
		if(!i)	continue;
		d[i] = abs(slide[i][0] - slide[i-1][0]) + abs(slide[i][1] - slide[i-1][1]);
		ans += d[i];
	}
	
	for(int i = 1 ; i < n - 1 ; i++){
		int temp = abs(slide[i+1][0] - slide[i-1][0]) + abs(slide[i+1][1] - slide[i-1][1]);
		if(max_d < d[i] + d[i+1] - temp){
			max_d = d[i] + d[i+1] - temp;
			skip = i;
		}
	}
	
	cout << ans - max_d << '\n';
	
	return 0;
}