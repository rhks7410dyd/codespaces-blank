#include <iostream>

using namespace std;

int arr[15] = {0,-1,-1,1,-1,1,2,-1,2,3, 2, 3, 4, 3, 4};

int main(){
	int k;
	
	cin >> k;
	
	int num=0;
	
	while(k >= 0){
		if(k % 5 == 0){
			cout << num + k/5 << endl;
			break;
		}
		num++;
		k -= 3;
	}
	
	if(k < 0){
		cout << -1 << endl;
	}
	
	return 0;
}