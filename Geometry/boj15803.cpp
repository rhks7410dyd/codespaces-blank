#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int pos[3][2];
	
	for(int i = 0 ; i < 3; i ++){
		cin >> pos[i][0] >> pos[i][1];
	}
	
	int v[2][2];
	for(int i = 0 ; i < 2; i++){
		v[i][0] = pos[i][0] - pos[i+1][0];
		v[i][1] = pos[i][1] - pos[i+1][1];
	}
	int ans = v[0][0]*v[1][1] - v[0][1]*v[1][0];
	if(ans){
		cout << "WINNER WINNER CHICKEN DINNER!\n";
	}
	else{
		cout << "WHERE IS MY CHICKEN?\n";
	}
	
	return 0;
}