#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main(){
	int temp,n,m;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]);
	}
	
	sort(arr,arr+n);
	
	int target_num;
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&target_num);
		
		int start = 0,end = n-1, mid;//start,end를 -1,n으로 두면 배열 내 최솟값보다 작거나 최댓값보다 큰 경우는 인덱스 에러가 뜨게 된다.
		bool is_exist_num = false;
		
		while(start <= end){
			mid = (start+end)/2;
			if(arr[mid] == target_num){
				is_exist_num = true;
				break;
			}
			else if(arr[mid] > target_num){
				end = mid-1;
				continue;
			}
			else{
				start = mid+1;
				continue;
			}
		}
		
		if(is_exist_num){
			cout << 1 << '\n';
		}
		else{
			cout << 0 << '\n';
		}
	}
	
	return 0;
}