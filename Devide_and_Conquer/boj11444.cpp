/*
참조 : https://zzonglove.tistory.com/32
머리 굴러갈 때 공부하고 풀어보기.
포스팅 된 글에서 말하는 4번째 방법을 사용하면 굳이 행렬의 곱을 구하지 않아도 쉽게 구현이 가능함. 이 방법을 사용해보기
//시간 초과가 뜬다.
vector<pair<int,int>> v 를 만들어서 num,fib_val 이런 식으로 페어를 활용해서 이미 만든 값을 활용하는 방식을 사용해서 다수의 저장을 방지하는 식으로 해보기.
어차피 최대값이라고 해봤자 2^60 꼴이라 값의 개수가 많아봐야 몇천개를 안넘길 것 같음(확인이 필요하긴 함) 그래서 시간적으로는 여유가 있기 때문에 매번 탐색하는 방식으로 해도 크게 상관이
없을 것 같음.
*/
#include <iostream>

using namespace std;

int FIB[11] = {0,1,1,2,3,5,8,13,21,34,55};

unsigned long long fib(unsigned long long n);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	unsigned long long N;
	cin >> N;
	
	unsigned long long res = fib(N);
	
	cout << res << '\n';
	
	return 0;
}

unsigned long long fib(unsigned long long n){
	unsigned long long res;
	if(!n)	return 0;
	if(n < 11){
		return FIB[n];
	}
	if(n&1){
		unsigned long long F_k = fib(n/2+1);
		unsigned long long F_k2 = fib(n/2);
		F_k = F_k*F_k%1000000007;
		F_k2 = F_k2*F_k2%1000000007;
		res = (F_k + F_k2)%1000000007;
	}
	else{
		unsigned long long F_k = fib(n/2-1);
		unsigned long long F_k2 = fib(n/2);
		F_k = (2*F_k+F_k2)%1000000007;
		res = F_k*F_k2%1000000007;		
	}
	return res;
}