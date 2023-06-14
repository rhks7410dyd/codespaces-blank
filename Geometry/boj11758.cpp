#include <iostream>
#include <cmath>

using namespace std;

int P[3][2];
int V[2][2];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ans;
	for(int i = 0 ; i < 3 ; i++){
		cin >> P[i][0] >> P[i][1];
	}
	
	for(int i = 0 ; i < 2 ; i++){
		V[i][0] = P[i+1][0] - P[i][0];
		V[i][1] = P[i+1][1] - P[i][1];
	}
	
	double cos_val = (V[0][0]*V[1][0]+V[0][1]*V[1][1])/(sqrt(V[0][0]*V[0][0]+V[0][1]*V[0][1])*sqrt(V[1][0]*V[1][0]+V[1][1]*V[1][1]));
	
	if(cos_val == 1 || cos_val == -1){
		ans = 0;
	}
	else{
		if(V[0][0] == 0){
			//이것도 위아래 나눠야됨
			ans = V[1][0] > 0 ? -1:1;
		}
		else if(V[0][0] > 0){
			
		}
		else{
			
		}
	}
	return 0;
}