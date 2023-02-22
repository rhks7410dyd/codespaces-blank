#include <iostream>

using namespace std;

int main(){
	long long hash_res=0;
	string input;
	int L;
	
	cin >> L >> input;
	
	long long r = 1;
	for(int i = 0 ; i < L ; i++){
		hash_res = (hash_res + (input[i]-96)*r)%1234567891;
		r = (r * 31) % 1234567891;
	}
	
	cout << hash_res << endl;
	
	return 0;
}

/*
26
abcdefghijklmnopqrstuvwxyz
801449636
*/

/*
10
abcdefghij
233956494
*/