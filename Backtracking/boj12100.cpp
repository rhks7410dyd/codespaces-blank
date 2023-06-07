#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int,int> m;
int Map[20][20];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	int t = 2;
	for(int i = 1 ; i < 11 ; i++){
		m[t] = i;
		t *=2 ;
	}
	m[0] = 0;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> Map[i][j];
			Map[i][j] = m[Map[i][j]];
		}
	}
	
	
	
	return 0;
}