#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	int n,m;
	while(T--){
		cin >> n >> m;
		if(n <= 2 || m <= 2)	cout << "First\n";
		else	cout << "Second\n";
	}
	
	return 0;
}