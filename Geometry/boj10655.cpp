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
	int slide[2][2];
	long long ans=0;
	int max_d = 0;
	cin >> n;
	cin >> slide[0][0] >> slide[0][1];
	for(int i = 1 ; i < n ; i++){
		cin >> slide[i%2][0] >> slide[i%2][1];
		int now_d = abs(slide[i%2][0] - slide[(i+1)%2][0]) + abs(slide[i%2][1] - slide[(i+1)%2][1]);
		ans += now_d;
		if(i != 1 && i != n-1){
			if(now_d > max_d)	max_d = now_d;
		}
		cout << "i " << i << " " << ans << ' ' << now_d << ' ' << max_d <<'\n';
	}
	
	cout << ans - max_d << '\n';
	
	return 0;
}