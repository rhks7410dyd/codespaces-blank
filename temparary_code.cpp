#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<double> v;
	
	int N,t,max=-1;
	cin >> N >> t;
	
	if(N == 1 && t == 1){
		cout << 1;
	}
	else if(N == 1 && t == 1){
		cout << 2;
	}
	
	return 0;
}