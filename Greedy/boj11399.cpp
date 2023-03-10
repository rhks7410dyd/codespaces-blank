#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> v;
	int t;
	for(int i = 0 ; i < N ; i++){
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i = 0 ; i < N ; i++){
		sum += (N-i)*v[i];
	}
	cout << sum << endl;
	return 0;
}