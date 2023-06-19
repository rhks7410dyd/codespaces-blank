//직선으로 이어야됨
#include <iostream>

using namespace std;

int arr[50];
int N;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> arr[i];
	}
	int ans = 0;
	for(int i = 0 ; i < N ; i++){
		int now = 0,t = 0;
		for(int j = i - 1 ; j >= 0 ; j--){
			if(arr[j] > t){
				now++;
				t = arr[j];
			}
			if(arr[j] == t && arr[j] < arr[i])	now++;
		}
		t = 0;
		for(int j = i + 1 ; j < N ; j++){
			if(arr[j] > t){
				now++;
				t = arr[j];
			}
			if(arr[j] == t && arr[j] < arr[i])	now++;
		}
		if(ans < now)	ans = now;
	}
	
	cout << ans << '\n';
	
	return 0;
}