#include <iostream>
#include <string>

using namespace std;

string a,b;
int asize,bsize;
bool a_used[1000];
bool b_used[1000];
int Solve(int a_p,int b_p);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> a >> b;
	if(a.size() < b.size()){
		string temp = a;
		a = b;
		b = temp;
	}
	
	asize = a.size();
	bsize = b.size();
	
	int ans = Solve(0,0);
	
	
	
	return 0;
}

int Solve(int a_p,int b_p){
	if(a[a_p] == b[b_p]){
		return Sovle(a_p+1,b_p+1);
	}
	
	
}