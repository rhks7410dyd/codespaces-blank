#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int DP[503];
int arr[503];
int C,N;

int find_pos(int val);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> C;
	
	for(int c = 0 ; c < C ; c++){
		cin >> N;
		for(int i = 1 ; i <= N ; i++){
			cin >> arr[i];
		}
		
		fill(&DP[0],&DP[503],INF);
		
		int longest_length = 1;
		DP[0] = 0;
		DP[1] = arr[1];
		for(int pos = 2 ; pos <= N ; pos++){
			//이분탐색을 이용해서 arr[pos]의 값이 상대적으로 어디 위치해야하는지를 파악하기
			int dp_pos = find_pos(arr[pos]);
			DP[dp_pos] = arr[pos];
			if(longest_length < dp_pos)	longest_length = dp_pos;
		}
		
		cout << longest_length << endl;
	}
}

int find_pos(int val){
	int start = 0,end = N+1;
	int mid;
	while(start < end){
		mid = (start+end)/2;
		if(DP[mid] < val && val <= DP[mid+1]){
			return mid+1;
		}
		
		if(DP[mid] >= val){
			end = mid;
			continue;
		}
		
		start = mid+1;
	}
	
	return 502;
}