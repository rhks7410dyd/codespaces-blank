/*
세그멘테이션 오류가 뜨는 걸로 봐서 스택 오버플로우 같은데, 어디서 줄여야할지모르겠음...
multifly에서 무작정 키워버리는 게 문제인가 싶기도 하다가도, 책에서 그냥 만들어버리는 걸 보면 이거 때문이 아닌 것 같기도 함
*/
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
vector<int> multifly(const vector<int>& a,const vector<int>& b);
void print_karatsuba_return(const vector<int>& a,const vector<int>& b,const vector<int>& c);
void print_vector(const vector<int> v,string input);
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
		for(int i = N-1 ; i < M ; i++)	if(ans[i] == 0)	count++;
		
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
	
	if(an <= 50)	return multifly(a,b);
	
	/*
	if(an <= 2){
		vector<int> c = multifly(a,b);
		print_karatsuba_return(a,b,c);
		return c;
	}*/
	
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
	
	//print_vector(z1,"Final z1");
	
	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	
	//print_karatsuba_return(a,b,ret);
	return ret;
}

//a += b*(10^k)
void addTo(vector<int> &a, const vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

//a -= b
void subFrom(vector<int> &a, const vector<int> &b){
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> multifly(const vector<int>& a,const vector<int>& b){
	vector<int> c(a.size()+b.size()+1,0);
	for(int i = 0 ; i < a.size() ; i++){
		for(int j = 0 ; j < b.size() ; j++){
			c[i+j] += a[i]*b[j];
		}
	}
	
	while(c.size() > 1 && c.back() == 0)	c.pop_back();
	return c;
}

void print_vector(const vector<int> v,string input){
	cout << input << endl;
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << ' ';
	}
	cout << endl;
	return;
}

void print_karatsuba_return(const vector<int>& a,const vector<int>& b,const vector<int>& c){
	print_vector(a,"a");
	print_vector(b,"b");
	print_vector(c,"return");
	
}