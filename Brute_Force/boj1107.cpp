#include <iostream>
#include <string>

#define INF 500000;

using namespace std;

int push_count[500001];
int N,M;
string str_n;
bool is_break_button[10];

int can_move_use_number_button(int n);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	int t;
	for(int i = 0 ; i < M ; i++){
		cin >> t;
		is_break_button[t] = true;
	}
	
	if(N == 100){
		cout << 0 << '\n';
		return 0;
	}
	
	int diff = 0;
	while(true){
		if(M == 10 || (N < 100 && N+diff >= 100) || (N > 100 && N - diff <= 100)){//단순히 N-diff로 하면 안됨! 왜냐면 버튼 누르는 '횟수'이기 때문
			cout << abs(N-100) << '\n';
			break;
		}
		
		int p_case = can_move_use_number_button(N+diff);
		int m_case = -1;
		if(N-diff >= 0)	m_case = can_move_use_number_button(N-diff); 
		if(m_case > 0){
			cout << diff + m_case << '\n';
			break;
		}
		if(p_case > 0){
			cout << diff + p_case << '\n';
			break;
		}
		diff++;
	}
	
	return 0;
}

int can_move_use_number_button(int n){
	string str_n = to_string(n);
	for(int i = 0 ; i < str_n.size() ; i++){
		if(is_break_button[str_n[i]-'0'])	return -1;
	}
	return str_n.size();
}