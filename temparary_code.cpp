#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a,b,c,d;
	
	cin >> a >> b >> d;
	
	c = a>(b+d) ? a:(b+d);
	
	cout << c << endl;
	
	return 0;
}