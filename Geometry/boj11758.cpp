#include <iostream>
#include <cmath>

using namespace std;

int P[3][2];
int V[2][2];
bool exist_above_the_line();
bool is_same_val(double a,int b);

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
	
	double t = V[0][0]/sqrt(V[0][0]*V[0][0] + V[0][1]*V[0][1]);
	double cos_val = (V[0][0]*V[1][0]+V[0][1]*V[1][1])/(sqrt(V[0][0]*V[0][0]+V[0][1]*V[0][1])*sqrt(V[1][0]*V[1][0]+V[1][1]*V[1][1]));
	
	
	if(is_same_val(cos_val,1) || is_same_val(cos_val,-1)){
		ans = 0;
	}
	else{
		if(V[0][0] == 0){
			//이것도 위아래 나눠야됨
			ans = (V[1][0]*V[0][1] > 0 ) ? -1:1;
		}
		else if(t > 0){//V[1]의 위치벡터가 V[0]를 방향 벡터로 하는 직선보다 위에 있냐 아래에 있냐로 구분
			if(exist_above_the_line())	ans = -1;
			else	ans = 1;
		}
		else{
			if(!exist_above_the_line())	ans = 1;
			else	ans = -1;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}

bool exist_above_the_line(){
	if(V[0][1]*V[1][0] - V[0][0]*V[1][1] > 0)	return true;
	return false;
}

bool is_same_val(double a,int b){
	if(abs(a - b) <= 1e-10)	return true;
	return false;
}