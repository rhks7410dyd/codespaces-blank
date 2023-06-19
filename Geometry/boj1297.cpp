#include <iostream>
#include <cmath>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	double d,h,w;
	cin >> d >> h >> w;
	
	double k = sqrt((d*d)/(h*h + w*w));
	cout << (int)(k*h) << ' ' << (int)(k*w) << '\n';
	
	return 0;
}