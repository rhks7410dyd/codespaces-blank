#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
double info[100][3];
double deg[100][2];
vector<int> path_zero;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sycn_with_stdio(false);
	
	int c;
	cin >> c;
	while(c--){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> info[i][0] >> info[i][1] >> info[i][2];
			deg[i][0] = atan2(info[i][0],info[i][1]);
			deg[i][1] = asin(info[i][2]/16);
			
		}
		
		
	}
	
	return 0;
}