//스위핑 알고리즘을 사용하지 않은 방식을 만들기 위해서 작성
//백준 6549 문제와 동일한 문제임.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solve();
int Recursive(int left,int right,vector<int>& h);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	
	scanf("%d",&C);
	
	for(int i = 0 ; i < C ; i++){
		int ans = Solve();
		printf("%d\n",ans);
	}
	
	return 0;
}


int Solve(){
	int N,t;
	scnaf("%d",&N);
	vector<int> v;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	
	int ret = Recursive(0,N-1,v);
	return ret;
}

int Recursive(int left,int right,vector<int>& h){
	if(left == right)	return h[left];
	
	int mid = (left + right)/2;
	int ret = 0;
	ret = max(ret,Recursive(left,mid,h));
	ret = max(ret,Recursive(mid+1,right,h));
	
	//while()	//<- 여길 어떻게 짤지가 핵심이니까 여기는 좀있다 구성해보고 짜기
	
	return ret;
}