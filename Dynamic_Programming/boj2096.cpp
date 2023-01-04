#include <iostream>
#include <algorithm>

using namespace std;

int pre[3][2];
int current[3][2];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N,a,b,c;
	cin >> N;
	cin >> a >> b >> c;
	pre[0][0] = a;
	pre[1][0] = b;
	pre[2][0] = c;
	
	pre[0][1] = a;
	pre[1][1] = b;
	pre[2][1] = c;	
	
	for(int i = 1 ; i < N ; i++){
		cin >> a >> b >> c;
		current[0][0] = max(pre[0][0],pre[1][0]) + a;
		current[1][0] = max({pre[0][0],pre[1][0],pre[2][0]}) + b;
		current[2][0] = max(pre[2][0],pre[1][0]) + c;
		
		pre[0][0] = current[0][0];
		pre[1][0] = current[1][0];
		pre[2][0] = current[2][0];
		
		current[0][1] = min(pre[0][1],pre[1][1]) + a;
		current[1][1] = min({pre[0][1],pre[1][1],pre[2][1]}) + b;
		current[2][1] = min(pre[2][1],pre[1][1]) + c;
		
		pre[0][1] = current[0][1];
		pre[1][1] = current[1][1];
		pre[2][1] = current[2][1];		
	}
	
	int max_val = max({pre[0][0],pre[1][0],pre[2][0]});
	
	int min_val = min({pre[0][1],pre[1][1],pre[2][1]});
		
	cout << max_val << ' ' << min_val << endl;
	
	return 0;
}