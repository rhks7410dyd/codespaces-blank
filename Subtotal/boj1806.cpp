#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N,S;
	int Input[100001];
	
	scanf("%d %d",&N,&S);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&Input[i]);
	}
	
	int shortest_length = N+1;
	int start = 0,end = 0;
	int sum = Input[0];
	
	while(end<N && start <= end){
		if(sum < S){
			sum += Input[++end];
		}
		else{
			if(shortest_length > end - start +1)	shortest_length = end - start + 1;
			sum -= Input[start++];
		}
	}
	
	if(shortest_length == N + 1)	shortest_length = 0;
	printf("%d\n",shortest_length);
	
	return 0;
}