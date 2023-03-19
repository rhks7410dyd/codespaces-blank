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
	subtotal[0]=0;
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&Input[i]);
		subtotal[i] += subtotal[i-1] + Input[i];
	}
	
	if(subtotal[N] < S){
		printf("0\n");
		return 0;
	}
	
	
	int shortest_length = N;
	int start = 0,end = 1;
	
	while(end<=N && start < end){
		int temp_subtotal = subtotal[end]-subtotal[start];
		if(temp_subtotal >= S){
			if(end-start < shortest_length){
				shortest_length = end-start;
				if(end-start == 1)	break;
			}
			start++;
			continue;
		}
		end++;
	}
	
	printf("%d\n",shortest_length);
	
	return 0;
}