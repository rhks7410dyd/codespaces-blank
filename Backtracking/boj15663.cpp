#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
조건은 동일하나 같은 수가 입력될 수가 있다는 사실을 알아야됨. 즉, a b_1 b_2 와 a b_2 b_1를 같은 것으로 보아야함. 

3 1
4 4 2
2
4

4 2
9 7 9 1
1 7
1 9
7 1
7 9
9 1
9 7
계속해서 스킵이 될 수 밖에 없으므로 문제가 생김. 가장 단순한 해결방식은 저장할 때 한 숫자가 얼만큼 반복되는지도 저장하는 것이지만, 이건 처리상에 속도가
너무 느리고 용량 낭비가 크다. 
*/

using namespace std;

vector<int> input;

bool is_used[8];
int N,M;

void Recursive_func(int pos, string ans){
	if(pos == M){
		cout << ans << '\n';
		return ;
	}
	else{
		int xx = 0;
		string temp;
		for(int i = 0 ; i < N ; i++){
			if(!is_used[i] && xx != input[i]){
				xx = input[i];
				temp = to_string(input[i]);
				is_used[i] = true;
				Recursive_func(pos + 1 , ans + temp + ' ');
				is_used[i] = false;
			}
		}
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	int temp;
	for(int i = 0 ; i < N ; i++){
		cin >> temp;
		input.push_back(temp);
	}
	
	sort(input.begin(),input.end());
	
	Recursive_func(0,"");
	
	return 0;
}