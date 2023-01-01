#include <iostream>

using namespace std;

//수학적으로 먼저 나누면 안되는 건가? 머리가 안돌아감.

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int L;
	long long hash_weight[51];
	string input;
	cin >> L >> input;
	
	long long hash_val=0;
	
	hash_weight[0] = 1;
	
	for(int i = 1 ; i < L ; i++){
		hash_weight[i] = (hash_weight[i-1]*31) % 1234567891;
	}
		
	for(int i = 0 ; i < L ; i++){
		hash_val += ((input[i]-'a'+1)*hash_weight[i])%1234567891;
	}
	
	if(hash_val > ((long long)1234567891)*50)	cout << "error!\n";
	cout << hash_val << endl;
	
	return 0;
}