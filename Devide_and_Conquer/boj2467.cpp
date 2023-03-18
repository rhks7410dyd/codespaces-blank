#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int Input[100000];
int N;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&Input[i]);
	}
	sort(&Input[0],&Input[N-1]);
	
	int left = 0,right=N-1;
	int best_val = abs(Input[0]+Input[N-1]),best_left=0,best_right=N-1;

	while(left < right){
		int now_val = Input[left]+Input[right];
		if(now_val == 0){
			best_left = left;
			best_right =right;
			break;
		}
		
		if(best_val > abs(now_val)){
			best_left = left;
			best_right = right;
			best_val = abs(now_val);
		}
		
		if(now_val > 0){
			right--;
		}
		else{
			left++;
		}
		
	}
	
	printf("%d %d\n",Input[best_left],Input[best_right]);
	return 0;
}