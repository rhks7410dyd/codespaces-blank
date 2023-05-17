#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000000+1

using namespace std;

int lengthdp[51];

const string X_Y[2] = {"X+YF","FX-Y"};
int n,p,l;

char get_one_char(const string& d,int skip,int gen);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	
	lengthdp[0] = 1;
	for(int i = 1 ; i < 51 ; i++){
		lengthdp[i] = min(2+2*lengthdp[i-1],INF);
	}
	
	for(int c = 0 ; c < C ; c++){
		cin >> n >> p >> l;
		
		
		char ans;
		for(int i = 0 ; i < l ; i++){
			cout << get_one_char("FX",p+i-1,n);
		}
		cout << '\n';
	}
	
	return 0;
}

char get_one_char(const string& d,int skip,int gen){
	if(gen == 0){
		return d[skip];
	}
	for(int i = 0 ; i < d.size() ; i++){
		if(d[i] == 'X' || d[i] == 'Y'){
			if(skip >= lengthdp[gen]){
				skip -= lengthdp[gen];
			}
			else if(d[i] == 'Y'){
				return get_one_char(X_Y[1],skip,gen-1);
			}
			else{
				return get_one_char(X_Y[0],skip,gen-1);
			}
		}
		else if(skip > 0)	--skip;
		else	return d[i];
	}
	return '#';
}