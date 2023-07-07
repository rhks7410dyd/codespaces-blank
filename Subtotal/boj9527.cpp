#include <iostream>
#include <cmath>

using namespace std;

long long subsum[55];
long long getAns(long long x);
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long a,b;
	cin >> a >> b;
	
	subsum[0] = 1;
	for(int i = 1 ; i < 55 ; i++){
		subsum[i] = 2*subsum[i-1] + (1LL<<i);
	}
	
	long long ans = getAns(b) - getAns(a-1);
	cout << ans << '\n';
	return 0;
}

long long getAns(long long x) {
	long long ret = x & 1;

	for (int i = 54; i > 0; i--) {
		if (x & (1LL << i)) {
			ret += subsum[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ret;
}


//a_n = a_(n-1) + 2^(n-1);
// b까지 총 개수 - a 까지 총 개수 느낌으로 풀면 됨

/*
0
1			0!
10
11			1!
100
101
110
111			2!
1000
1001
1010
1011
1100
1101
1110
1111		3!
10000
10001
10010
10011
10100
10101
10110
10111
11000
11001
11010
11011
11100
11101
11110
11111		!
*/