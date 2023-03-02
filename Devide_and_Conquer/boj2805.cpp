#include <iostream>

using namespace std;

int N,M;
int height[1000000];

int cal_wood(int h);

int main(){
	scanf("%d %d",&N,&M);
	
	int t,max_h = -1;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&height[i]);
		if(height[i] > max_h){
			max_h = height[i];
		}
	}
	
	int start = 0, end = max_h;
	while(start <= end){
		int mid = (start+end)/2;
		int get_wood = cal_wood(mid);
		if(get_wood >= M){
			
		}
	}
}

int cal_wood(int h){
	int sum = 0;
	for(int i = 0 ; i < N ; i++){
		if(height[i] <= h){
			continue;
		}
		sum += height - h;
	}
	
	return sum;
}