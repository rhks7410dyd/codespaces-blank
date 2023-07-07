#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI 3.14159265358979323846
using namespace std;

int n;
double info[100][3];
double deg[100][2];
double range[100][2];
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
			range[i][0] = deg[i][0] - 2*deg[i][1];
			range[i][1] = deg[i][0] + 2*deg[i][1];
		}
		
		for(int i = 0 ; i < n ; i++){
			if(range[i][0] < 0){
				if(range[i][1] <= -10e-7){
					range[i][0] += 2*PI;
					range[i][1] += 2*PI;
				}
				else if(range[i][1] >= 10e-7){
					path_zero.push_back(i);
				}
			}
		}
		
		
	}
	
	return 0;
}