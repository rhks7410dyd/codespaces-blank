#include <iostream>
//옛날에 배운 확장 유클리드 알고리즘을 써야된다. 추가 공부가 필요할듯..
using namespace std;

long long modula_times(){
	
}

long long modula_inverse(long long N){
	
}

long long Euclidean(long long a,long long b){
	long long t;
	if(a < b){
		t = b;
		b = a;
		a = t;
	}
	//a = b*Q + t
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
	
	long long S,N,res,temp,divisible;
	for(int i = 0 ; i < M ; i++){
		scanf("%lld %lld",&N,&S);
		
		divisible = Euclidean(N,S);
		N /= divisible;
		S /= divisible;
		
		N = modula_inverse(N);
		temp = modula_times(N,S);
		
		res += temp;
		res %= 1000000007;
	}
	
	printf("%lld\n",res);
	
	return 0;
}