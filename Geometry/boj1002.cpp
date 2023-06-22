#include <iostream>

using namespace std;

int main(){
	long long x[2],y[2],r[2],d[2];	
	
	int T;
	cin >> T;
	while(T--){
		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

		int ans;
		if(x[0] == x[1] && y[0] == y[1] && r[0] == r[1] && r[0]) ans = -1;
		else{
			d[0] = x[0] - x[1];
			d[1] = y[0] - y[1];
			
			long long d2 = d[0]*d[0] + d[1]*d[1];
			long long r2 = r[0]*r[0] + 2*r[0]*r[1] + r[1]*r[1];
			if(d2 == r2 || d2 == r[0]*r[0] - 2*r[0]*r[1] + r[1]*r[1])	ans = 1;
			else if(d2 > r2)	ans = 0;
			else if(d2 < r[0]*r[0] - 2*r[0]*r[1] + r[1]*r[1])	ans = 0;
			else	ans = 2;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}