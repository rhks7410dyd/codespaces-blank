#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#define MOD 1000000007
using namespace std;

int dp[1<<14][20][2];
string e,digit;
int m,cnt,esize;

int can_be_price(int index,int Set,int mod,int is_low);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	while(C--){
		cin >> e >> m;
		
		memset(&dp[0][0][0],-1,sizeof(dp));
		cnt = 0;
		esize = e.size();
		
		vector<int> v;
		for(int i = 0 ; i < esize ; i++){
			v.push_back(e[i]-'0');
		}
		sort(v.begin(),v.end());
		
		digit = "";
		for(int i = 0 ; i < esize ; i++){
			digit += (char)(v[i]+'0');
		}
		
		int ans = can_be_price(0,0,0,0);
		cout << ans << '\n';
	}
}

int can_be_price(int index,int Set,int mod,int is_low){
	if(index == esize){//모든 숫자를 다 사용했을 때
		return (is_low && mod == 0) ? 1 : 0;
	}
	
	int& ret = dp[Set][mod][is_low];
	
	if(ret != -1)	return ret;
	
	ret = 0;
	for(int i = 0 ; i < esize ; i++){
		if((Set & (1<<i)) == 0){
			if(!is_low && digit[i] > e[index])	continue;

			if(i > 0 && digit[i-1] == digit[i] && (Set & (1<<(i-1))) == 0)	continue;

			int nextSet = Set | (1<<i);
			int nextmod = (mod*10 + digit[i]-'0')%m;
			bool next_is_low = is_low || e[index] > digit[i];
			//cout << "next val : digit[i] - " << digit[i] << " Set - " << bitset<4>(nextSet) << " mod - " << nextmod << " is_low - " << next_is_low << '\n'; 
			ret += can_be_price(index+1,nextSet,nextmod,next_is_low);
			ret %= MOD;
		}
	}
	return ret;
}