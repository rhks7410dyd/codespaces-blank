/*
왜 안되냐 이거>?
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    double x[3],y[3];
	
	for(int i = 0 ; i < 3 ; i++){
		cin >> x[i] >> y[i];
	}
	
	double d1,d2;
	if(x[2] != x[1] && x[1] != x[0]){
		d1 = (y[2] - y[1])/(x[2] - x[1]);
		d2 = (y[1] - y[0])/(x[1] - x[0]);
		if(abs(d1 - d2) <= 0.0001){
			cout << -1 << '\n';
			return 0;
		}
	}
	if((y[0] == y[1] && y[1] == y[2]) || (x[0]==x[1] && x[1]==x[2])){
		cout << -1 << '\n';
		return 0;
	}
	
	double l[3];
	for(int i = 0 ; i < 3 ; i++){
		l[i] = sqrt((y[i%3]-y[(i+1)%3])*(y[i%3]-y[(i+1)%3]) + (x[i%3]-x[(i+1)%3])*(x[i%3]-x[(i+1)%3]));
	}
	
	cout.precision(15);
	
	sort(&l[0],&l[3]);
	
	double ans[3];
	for(int i = 0 ; i < 3 ; i++){
		ans[i] = 2*(l[i]+l[(i+1)%3]);
	}
	sort(&ans[0],&ans[3]);
	
	cout << ans[2]-ans[0] << endl;
	
	return 0;
}