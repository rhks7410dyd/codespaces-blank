#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int k;
int dp[1<<15];
int overlap_length[15][15];
vector<string> input;
int Solve(int Set,int index,int str);
int get_minus_length(int a,int b);
bool compare(string& a,string& b);
bool is_included(string& a,string& b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	while(C--){
		memset(&dp[0],-1,sizeof(dp));
		memset(&overlap_length[0][0],-1,sizeof(overlap_length));
		cin >> k;
		for(int i = 0 ; i < k ; i++){
			string temp;
			cin >> temp;
			input.push_back(temp);
		}
		
		sort(input.begin(),input.end(),compare);
		
		for(int i = 0 ; i < k ; i++){
			for(int j = i+1 ; j < k ; j++){
				if(input[j].find(input[i]) != std::string::npos){
					input.erase(input.begin()+i);
					break;
				}
			}
		}
		/*
		cout << "input list\n";
		for(int i = 0 ; i < input.size() ; i++){
			cout << input[i] << '\n';
		}
		*/
		int ans = INF;
		
		for(int i = 0 ; i < input.size() ; i++){
			int temp = Solve(1<<i,0,i);
			cout << "temp_i(" << i <<") " << temp << '\n';
			if(temp < ans)	ans = temp;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}

int Solve(int Set,int index,int str){
	if(index == input.size()-1){
		return input[str].size();
	}
	
	int& ret = dp[Set];
	if(ret != -1)	return ret;
	
	ret = INF;
	for(int next = 0 ; next < input.size() ; next++){
		if(!(Set & (1 << next))){
			int temp = Solve(Set | (1 << next),index+1,next) - get_minus_length(str,next);
			if(temp + input[str].size() < ret)	ret = temp + input[str].size();
		}
	}
	
	cout << "Set " << Set << " str " << str << " : " << input[str] << " ret " << ret << '\n';
	return ret;
}

int get_minus_length(int a,int b){
	int ret = overlap_length[a][b];
	if(ret != -1)	return ret;
	
	string& f = input[a];
	string& e = input[b];
	
	ret = 0;
	int f_pos = f.size()-1;
	int e_pos = 0;
	//여기 비교를 잘못하고 있음.
	while(f_pos >= 0 && e_pos < e.size()){
		if(f[f_pos] == e[e_pos]){
			ret++;
			f_pos--;
			e_pos++;
		}
		else	break;
	}
	cout << f << ' ' << e << ' ' << ret << '\n';
	return ret;
}

bool compare(string& a,string& b){
	return a.size() < b.size();
}