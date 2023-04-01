#include <iostream>

using namespace std;

int gcd(int a,int b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0 ; t < T ; t++){
		int n,m,x,y;
		cin >> m >> n >> x >> y;
		// ans%m == x && ans%n == y
		//ans = m*k_1 + x = n*k_2 + y <= m*n	==> k_2 < m
		//k_1 == (n*k_2+y-x)/m
		int ans;
		int GCD = gcd(m,n);
		int LCM;
		if(m>n){
			LCM = (m/GCD)*n;
		}
		else{
			LCM = (n/GCD)*m;
		}
		
		while(x<=LCM){
			if(x%n == y){
				cout << x << '\n';
				break;
			}
			x += m;
		}
		if(x >= LCM)	cout << -1 << '\n';
		//10 12 10 12 예제에 대해서 풀면 될듯
	}
	
	return 0;
}

int gcd(int a,int b){
	if(a%b == 0)	return b;
	return gcd(b,a%b);
}

/*
https://namu.wiki/w/%EC%A4%91%EA%B5%AD%EC%9D%B8%EC%9D%98%20%EB%82%98%EB%A8%B8%EC%A7%80%20%EC%A0%95%EB%A6%AC
*/