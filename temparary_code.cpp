#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<double> v;
	
	int N,t,max=-1;
	cin >> N;

	for(int i = 0 ; i < N ; i++){
		cin >> t;
		v.push_back(t);
		if(max < t)	max = t;
	}
	
	double average=0;
	for(int i = 0 ; i < N ; i++){
		v[i] = v[i]/max * 100;
		average += v[i];
	}
	cout << average/N << endl;
	
	return 0;
}