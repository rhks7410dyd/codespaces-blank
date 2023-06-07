#include <iostream>
#include <map>

using namespace std;

int n,s;
long long cnt = 0;
map<int,int> sub;
int arr[40];

void right_part(int pos,int sum);
void left_part(int pos,int sum);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;
	
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	right_part(n/2,0);
	left_part(0,0);
	
	if(s == 0){
		cnt--;
	}
	cout << cnt << '\n';
	return 0;
}

void right_part(int pos,int sum){
	if(pos == n){
		sub[sum] += 1;
		return ;
	}
	
	right_part(pos+1,sum+arr[pos]);
	right_part(pos+1,sum);
}

void left_part(int pos,int sum){
	if(pos == n/2){
		cnt += sub[s-sum];
		return ;
	}
	
	left_part(pos+1,sum+arr[pos]);
	left_part(pos+1,sum);
}