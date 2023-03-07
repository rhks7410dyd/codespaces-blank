//hint : 두 큰 수의 곱으로 변형하기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
vector<int> Idol;
vector<int> Fan;
vector<int> ans;

vector<int> Karatsuba(const vector<int>& a,const vector<int>& b);
void addTo(vector<int>& a,const vector<int>& b,int k);
void subFrom(vector<int>& a,const vector<int>& b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string fan,idol;
	int C,t;
	
	cin >> C;
	
	for(int c = 0 ; c < C ; c++){
		cin >> idol >> fan;
		
		int N = idol.size(), M = fan.size();
		for(int i = 0 ; i < N ; i++)	Idol.push_back(idol[i]=='M');
		for(int i = M - 1 ; i >= 0 ; i--)	Fan.push_back(fan[i]=='M');
		
		ans = Karatsuba(Idol,Fan);
		
		int count = 0;
		for(int i = 0 ; i < ans.size() ; i++)	if(ans[i] == 0)	count++;
		
		cout << count << endl;
		
		Idol.clear();
		Fan.clear();
		ans.clear();
	}
	
	
	return 0;
}

vector<int> Karatsuba(const vector<int>& a,const vector<int>& b){
	int an = a.size(), bn = b.size();

	if(an < bn)	return Karatsuba(b,a);
	
	if(an == 0 || bn == 0)	return vector<int>();
	
	int half = an/2;
	
	vector<int> a0(a.begin(),a.begin()+half);
	vector<int> a1(a.begin() + half,a.end());
	vector<int> b0(b.begin(),b.begin()+min<int>(b.size(),half));
	vector<int> b1(b.begin()+min<int>(b.size(),half),b.end());
	
	vector<int> z2 = Karatsuba(a1,b1);
	vector<int> z0 = Karatsuba(a0,b0);
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	
	vector<int> z1 = Karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);
	
	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	return ret;
}

//an 보다 k가 큰 경우를 생각하지 않음.
void addTo(vector<int>& a,const vector<int>& b,int k){
	int an = a.size(), bn = b.size();
	
	if(an - k >= bn){
		for(int i = k ; i < bn+k ; i++)	a[i] += b[i-k];
	}
	else{
		for(int i = k ; i < an ; i++)	a[i] += b[i-k];
		for(int i = an ; i < bn + k ; i++)	a.push_back(b[i-k]);
	}
	
	return ;
}

void subFrom(vector<int>& a,const vector<int>& b){
	int an = a.size(), bn = b.size();
	
	if(an <= bn){
		for(int i = 0 ; i < an ; i++)	a[i] += a[i] - b[i];
		for(int i = an ; i < bn ; i++)	a.push_back(-b[i]);
	}
	else{
		for(int i = 0 ; i < bn ; i++)	a[i] += a[i] - b[i];
	}
	
	return ;
}