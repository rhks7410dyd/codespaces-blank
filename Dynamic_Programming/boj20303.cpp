#include <iostream>
#include <vector>

using namespace std;

int n,m,k;
int Uni[30000];
int candy[30000];

void merge_set(int a,int b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	
	for(int i = 0 ; i < n ; i++){
		cin >> candy[i];
	}
	
	int a,b;
	for(int i = 0 ; i < m ; i++){
		cin >> a >> b;
		merge_set(a,b);
	}
	
	
	
	return 0;
}