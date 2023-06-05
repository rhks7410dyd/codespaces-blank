#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int cnt[31];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,t;
	cin >> N;
	vector<int> v;
	for(int i = 0 ; i < N ; i++){
		cin >> t;
		v.push_back(t);
	}
	
	float m_num =	round(0.15 * N);
	sort(v.begin(),v.end());
	
	float avg = 0;
	for(int i = m_num ; i < N - m_num ; i++){
		avg += v[i];
	}
	
	avg /= (N - m_num*2);
	avg = round(avg);
	cout << (int)avg << endl;
	return 0;
}