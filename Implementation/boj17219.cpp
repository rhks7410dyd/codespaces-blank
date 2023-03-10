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
	
	map<string,string> ma;
	vector<string> in;
	
	string site,password;
	for(int i = 0 ; i < N ; i++){
		cin >> site >> password;
		ma[site]=password;
	}
	
	for(int i = 0 ; i < M ; i++){
		cin >> site;
		in.push_back(ma[site]);
	}

	for(int i = 0 ; i < in.size() ; i++)	cout << in[i] << endl;
	return 0;
}