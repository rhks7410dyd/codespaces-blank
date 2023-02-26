#include <iostream>

using namespace std;

int map[50][50];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n-7 ; i++){
		for(int j = 0 ; j < m-7 ; j++){
			int temp = count_change(i,j);
		}
	}
}