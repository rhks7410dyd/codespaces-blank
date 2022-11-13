/*
부분합을 이용하면 빠르게 계산을 할 수 있음.
즉, 부분합 배열을 만들어 평균을 빠르게 만드는 것이 중요해 보임.
*/
#include <iostream>

using namespace std;

int C,N,L;
int sum[1001];

void Input(){
	int temp;
	scanf("%d %d",&N,&L);
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&temp);
		sum[i] = sum[i-1] + temp; //부분합 만들기
	}
}

void Solve(){
	double minaverage = 100, temp;
	for(int i = 0 ; i <= N - L ; i++){
		for(int j = i + L ; j <= N ; j++){
			temp = ((double)sum[j] - sum[i]) / (j-i);
			if(temp < minaverage){
				minaverage = temp;
				//cout << "j : " << j << " i " << i << " minaverage " << minaverage << endl;
			}
		}
	}
	printf("%lf\n",minaverage);
}

int main(){
	ios::sync_with_stdio(0);
	
	scanf("%d",&C);
	for(int i = 0 ; i < C ; i++){
		Input();
		Solve();
	}
}