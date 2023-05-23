/*
왜..안되는 걸까......
내일은 책 보고 제대로 비교해보기
*/
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
string reconstruct(int last,int Set);
int Solve(int Set,int str);
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
		input.clear();
		cin >> k;
		for(int i = 0 ; i < k ; i++){
			string temp;
			cin >> temp;
			input.push_back(temp);
		}
		
		sort(input.begin(),input.end(),compare);
		
		bool is_overlapped[15];
		for(int i = 0 ; i < k ; i++){
			is_overlapped[i]=false;
			for(int j = i+1 ; j < k ; j++){
				if(input[j].find(input[i]) != string::npos){
					is_overlapped[i] = true;
					break;
				}
			}
		}
		
		int erase_cnt = 0;
		for(int i = 0 ; i < k ; i++){
			if(is_overlapped[i]){
				input.erase(input.begin()+i-erase_cnt);
				erase_cnt++;
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
			int temp = Solve(1<<i,i);
			//cout << "temp_i(" << i <<") " << temp << '\n';
			if(temp < ans)	ans = temp;
		}
		
		string s_ans;
		for(int i = 0 ; i < input.size() ; i++){
			string temp = input[i];
			temp += reconstruct(i,1<<i);
			//cout << "i " << i << " temp " << temp << " ans " << ans << '\n';
			if(temp.size() == ans){
				s_ans = temp;
				break;
			}
		}
		
		cout << s_ans << '\n';
	}
	
	return 0;
}

int Solve(int Set,int str){
	if(Set == (1<<input.size())-1){
		return input[str].size();
	}
	
	int& ret = dp[Set];
	if(ret != -1)	return ret;
	
	ret = INF;
	for(int next = 0 ; next < input.size() ; next++){
		if(!(Set & (1 << next))){
			int temp = Solve(Set + (1 << next),next) - get_minus_length(str,next);
			if(temp + input[str].size() < ret){
				ret = temp + input[str].size();
			}
		}
	}
	
	//cout << "Set " << Set << " str " << str << " : " << input[str] << " ret " << ret << '\n';
	return ret;
}

int get_minus_length(int a,int b){
	int& ret = overlap_length[a][b];
	if(ret != -1)	return ret;
	
	string& f = input[a];
	string& e = input[b];
	int fsize = f.size();
	int Size = f.size() < e.size() ? f.size() : e.size();
	
	ret = 0;
	for(int l = 1 ; l < Size; l++){
		bool can_overlap = true;
		for(int i = 0 ; i < l ; i++){
			if(f[fsize-l+i] != e[i]){
				can_overlap = false;
				break;
			}
		}
		if(can_overlap)	ret = l;
	}
	
	
	//cout << f << ' ' << e << ' ' << ret << '\n';
	return ret;
}

bool compare(string& a,string& b){
	return a.size() < b.size();
}

//아직도 맨 아래 워닝이 나옴
string reconstruct(int last,int Set){
	if(Set == (1<<input.size())-1)	return "";
	
	for(int next = 0 ; next < input.size() ; next++){
		if(Set & (1<<next))	continue;
		int ifUsed = Solve(Set+(1<<next),next) + input[last].size() - get_minus_length(last,next);
		/*
		cout << "Set " << Set << " last " << last << " next " << next << '\n'
			<< "Solve(Set+(1<<next),next) " << Solve(Set+(1<<next),next) << "  input[last].size() " <<  input[last].size()
			<< " overlap_length[last][next] " << overlap_length[last][next] << '\n';
		cout << "ifUsed " << ifUsed << " Solve(Set,last) " << Solve(Set,last) << '\n';
		*/
		if(Solve(Set,last) == ifUsed){
			return (input[next].substr(overlap_length[last][next]) + reconstruct(next, Set + (1<<next)));
		}
	}
	return "***** WARNING! *****";
}