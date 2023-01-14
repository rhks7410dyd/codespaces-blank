#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int c,t;
	long min = 3987654321,max = -1;
	
	cin >> c;
	
	for(int i = 0 ; i < c ; i++){
		cin >> t;
		if(t > max)	t= max;
		else if(t < min)	t = min;
	}
	
	cout << max*min << endl;
	
	return 0;
}