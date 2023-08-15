#include <iostream>
#include <map>

using namespace std;

map<string,int> m1;
string m2[3] = {"swimming", "bowling", "soccer"};
bool answer[1500][3];


int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	m1["swimming"] = 0;
	m1["bowling"] = 1;
	m1["soccer"] = 2;
	
	
	for(int i = 0 ; i < n ; i++){
		cout << m2[i%3] << ' ';
		answer[i][i%3] = true;
	}
	cout << '\n' << flush;
	
	string temp;
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		answer[i][m1[temp]] = true;
	}
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 3; j++){
			if(!answer[i][j]){
				cout << m2[j] << ' ';
				break;
			}
		}
	}
	cout << '\n';
	
	return 0;
}