#include <iostream>
#include <map>
#include <algorithm>
#define INF 987654321

using namespace std;

int N;
string mbti[16] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP", "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"};
map<string,int> m;
int dis_table[16][16];

int get_triple_dis(int a,int b,int c);
int get_dis(int a,int b);
void cal_table();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cal_table();

	int C;
	cin >> C;
	while(C--){
		for(int i = 0 ; i < 16 ; i++){
			m[mbti[i]] = 0;
		}
		cin >> N;
		string t;
		for(int i = 0 ; i < N ; i++){
			cin >> t;
			m[t]++;
		}
		
		if(N >= 33){
			cout << 0 << '\n';
			continue;
		}
		
		bool Pass = false;
		for(int i = 0 ; i < 16 ; i++){
			if(m[mbti[i]] >= 3){
				Pass = true;
				cout << 0 << '\n';
				break;
			}
		}
		if(Pass)	continue;
		
		int ans = INF;
		for(int i = 0 ; i < 16 ; i++){
			for(int j = i ; j < 16 ; j++){
				for(int k = j ; k < 16 ; k++){
					if(!m[mbti[i]] || !m[mbti[j]] || !m[mbti[k]])	continue;
					ans = min(ans,get_triple_dis(i,j,k));
				}
			}
		}
		cout << ans << '\n';
	}
}

int get_triple_dis(int a,int b,int c){
	if(a == b && b == c)	return INF;
	
	if(a == b || b == c){
		if(m[mbti[b]] < 2)	return INF;
		
		if(a == b){
			return 2*dis_table[a][c];
		}
		else{
			return 2*dis_table[a][b];
		}
	}
	
	return dis_table[a][b]+dis_table[a][c]+dis_table[b][c];
}

int get_dis(int a,int b){
	int ret = 0;
	for(int i = 0 ; i < 4 ; i++){
		if(mbti[a][i] != mbti[b][i])	ret++;
	}
	return ret;
}
void cal_table(){
	for(int i = 0 ; i < 16 ; i++){
		for(int j = 0 ; j < 16 ; j++){
			if(i==j)	continue;
			dis_table[i][j] = get_dis(i,j);
		}
	}
}