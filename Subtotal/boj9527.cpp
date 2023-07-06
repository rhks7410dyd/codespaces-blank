#include <iostream>

using namespace std;

long long subsum[55];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sycn_with_stdio(false);
	
	unsigned long long a,b;
	cin >> a >> b;
	
	//이거 이렇게하면 무조건 시간 초과임.
	for(){
		
	}
	
	return 0;
}

//a_n = a_(n-1) + 2^(n-1);
// b까지 총 개수 - a 까지 총 개수 느낌으로 풀면 됨