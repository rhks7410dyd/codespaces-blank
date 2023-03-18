#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,S;
	int Input[100001];
	int subtotal[100001];
	
	scanf("%d %d",&N,&S);
	
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&Input[i]);
		subtotal[i] += subtotal[i-1] + Input[i];
	}
	
	if(subtotal[N] < S){
		printf("0\n");
		return 0;
	}
	
	//두 포인터
	int shortest_length = N;
	while()
	
	return 0;
}