#include <iostream>
#include <vector>

using namespace std;

bool is_decimal[1000001];
int n;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	vector<int> v;
	int t;
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		v.push_back(t);
	}
	
	for(int i = 2 ; i <= 999 ; i++){
		if(is_decimal[i])	continue;
		
		t = i;
		while(t <= 1000000){
			is_decimal[t] = true;
			t += i;
		}
	}
	
	return 0;
}