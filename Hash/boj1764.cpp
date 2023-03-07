//https://nstgic3.tistory.com/33
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> listen;
vector<int> see;

int make_hash_val(string st);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,M;
	
	cin >> N >> M;
	
	string input;
	for(int i = 0 ; i < N ; i++){
		cin >> input;
		listen.push_back(make_hash_val(input));
	}
	
	for(int i = 0 ; i < M ; i++){
		cin >> input;
		see.push_back(make_hash_val(input));
	}
	
	for(int i = 0 ; i < N ; i++)
	return 0;
}