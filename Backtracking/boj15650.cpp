/*
백트래킹 문제지만 반복문에서 값을 조정해줌으로서 검사를 하지 않아도 되는 상태로 만들어서 구현으로 조건에 맞지 않는
경우를 제외시켜버림
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N,M;

void Recursive_func(int pos, int val, string ans){
	if(pos == M){
		cout << ans << '\n';
		return ;
	}
	else{
		for(int i = val + 1 ; i <= N - M + pos + 1 ; i++){
			//오름차순이 되야 되므로 val보단 큰 값이면서, 뒤에 추가적으로 남은 게 와야 되기 때문에 제한 값은 N-M+pos+1이다.
			Recursive_func(pos + 1 , i , ans + " " + (char)(i + '0'));
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i = 1 ; i <= N - M + 1 ; i++){
		string ans = "";
		ans += (char)(i + '0');
		Recursive_func( 1 , i ,ans);
	}
	
	return 0;
}