#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N,K;
	int value[10];
	int count = 0;
	
	cin >> N >> K;
	for(int i = 0 ; i <  N ; i++){
		cin >> value[i];
	}
	
	for(int i = N - 1 ; i >= 0 ; i--){
		int quo = K / value[i];
		K %= value[i];
		count += quo;
	}
	
	cout << count << '\n';
	
	return 0;
}