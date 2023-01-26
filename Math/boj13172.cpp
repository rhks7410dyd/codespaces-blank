#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <string>
#define INF 1000000007

using namespace std;

//임의의 소수 X에 대한 b의 모듈러 곱셈에 대한 역원은 b^(X - 2) 이다.

long long Euclidean(long long a,long long b){
	long long t;
	if(a < b){
		t = b;
		b = a;
		a = t;
	}
	
	while(a%b != 0){
		t = a%b;
		a = b;
		b = t;
	}
	
	return b;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int M;
	
	scanf("%d",&M);
	
	long long S,N,res,temp,divisible,rev;
	long long *x,*y;
	for(int i = 0 ; i < M ; i++){
		scanf("%lld %lld",&N,&S);
		
		divisible = Euclidean(N,S);
		N /= divisible;
		S /= divisible;

		/*
		여기서 부터  N^(INF-2) 를 구해야한다. 분할정복을 이용한 거듭제곱을 활용하여 이 값을 rev라고 칭하자. 이후 rev * S % INF 값을 res에 더해주면 된다.
		*/
		
		while(N){
			
		}
		
	}
	
	printf("%lld\n",res);
	
	return 0;
}