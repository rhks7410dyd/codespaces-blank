#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//수학적으로 먼저 나누면 안되는 건가? 머리가 안돌아감.

int comb(int n , int k){
	if(k == 0 || k == n){
		return 1;
	}
	else{
		return comb(n-1,k-1) + comb(n-1,k);
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N,K;
	
	cin >> N >> K;
	
	int res = comb(N,K);
	
	cout << res << endl;
	
	return 0;
}