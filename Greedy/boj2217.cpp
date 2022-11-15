#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N,tempweight;
	vector<int> weight;	
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> tempweight;
		weight.push_back(tempweight);
	}
	
	sort(weight.begin(),weight.end());
	
	int Maxval = -1;
	for(int i = 0 ; i < N ; i++){
		tempweight = (N - i) * weight[i];
		if(Maxval < tempweight)	Maxval = tempweight;
	}
	
	cout << Maxval << '\n';
	
	return 0;
}