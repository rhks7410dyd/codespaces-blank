//https://nstgic3.tistory.com/33
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> listen;
vector<int> see;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,M;
	
	cin >> N >> M;
	
	map<string,int> ma;
	vector<string> in;
	
	string input;
	for(int i = 0 ; i < N ; i++){
		cin >> input;
		ma[input]++;
	}
	
	for(int i = 0 ; i < M ; i++){
		cin >> input;
		if(ma[input] > 0){
			in.push_back(input);
		}
	}
	
	sort(in.begin(),in.end());
	
	cout << in.size() << endl;
	for(int i = 0 ; i < in.size() ; i++)	cout << in[i] << endl;
	return 0;
}