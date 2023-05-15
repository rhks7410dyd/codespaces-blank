#include <iostream>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	scanf("%d",&T);
	
	for(int t = 0 ; t < T ; t++){
		int N,K,arr[500];
		scanf("%d %d",&N,&K);
		
		for(int i = 0 ; i < N ; i++){
			scanf("%d ",&arr[i]);
		}
		
		//LIS 구하기
		
		
		//LIS 값을 토대로 K번째 LIS 구하기
	}
	
	return 0;
}