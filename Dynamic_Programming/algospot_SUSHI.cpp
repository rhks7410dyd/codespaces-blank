#include <iostream>
#include <algorithm>

using namespace std;

int n,m,price[20],pref[20];
int c[201];
int sushi();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	scanf("%d",&C);
	
	while(C--){
		scanf("%d %d",&n,&m);
		
		m/=100;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d",&price[i],&pref[i]);
			price[i]/=100;
		}
		
		int ans = sushi();
		
		printf("%d\n",ans);
	}
	
	return 0;
}

int sushi(){
	int ret = 0;
	c[0] = 0;
	for(int budget = 1 ; budget <= m ; ++budget){
		int cand = 0;
		for(int dish = 0 ; dish < n ; ++dish){
			if(budget >= price[dish]){
				cand = max(cand,c[(budget-price[dish])%201]+pref[dish]);
			}
		}
		c[budget%201] = cand;
		ret = max(ret,cand);
	}
	return ret;
}

/*

*/