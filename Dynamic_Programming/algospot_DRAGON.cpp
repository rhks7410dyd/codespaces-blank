#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000000+1

using namespace std;

int lengthdp[51];

string X = "X+YF";
string Y = "FX-Y";
int n,p,l;

char get_one_char(string d,int skip,int gen);

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
		for(int i = p ; i < p+l ; i++){
			int gen;
			for(int j = 0 ; j < 51 ; j++){
				if(p < lengthdp[j]){
					gen = j;
					break;
				}
			}
			if(i == 1){
				ans = 'F';
			}
			else{
				ans = get_one_char(X,i-1,gen);
			}
			cout << ans;
		}
	}
	
	return 0;
}

char get_one_char(string d,int skip,int gen){
	if(gen == 0){
		return d[skip];
	}
	for(int i = 0 ; i < d.size() ; i++){
		if(d[i] == 'X' || d[i] == 'Y'){
			if(skip >= lengthdp[gen]){
				skip -= lengthdp[gen];
			}
			else if(d[i] == 'Y'){
				return get_one_char(Y,gen-1,skip);
			}
			else{
				return get_one_char(X,gen-1,skip);
			}
		}
		else if(skip > 0)	skip--;
		else	return d[i];
	}
	return '#';
}