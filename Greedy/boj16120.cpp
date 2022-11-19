#include <iostream>
#include <string>

using namespace std;

int main() {
	string input_str;
	cin >> input_str;
	
	int count = 0;
	
	for(int i = 0; i < input_str.length(); i++){
		if(input_str[i] == 'P'){
			count++;
			continue;
		}
		
		if(count >=2 && input_str[i+1] == 'P'){
			count--;
			i++;
		}
		
		else{
			cout << "NP\n";
			return 0;
		}
	}
	
	if(count == 1) cout << "PPAP\n";
	else cout << "NP\n";
	
	return 0;
}

/*#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> s;
string input_str;

bool PPAP(int pos){
	char first,second;
	if(pos == input_str.length() - 1)	return false;
	if(input_str[pos+1] == 'P'){		
		if(s.top() == 'P'){
			s.pop();
			if(s.top() == 'P')	return true;
			return false;
		}
		return false;
	}
	else	return false;
}

int main(){
	cin >> input_str;
	
	/*
	스택에 순서대로 넣으면서 "ppap가 만들어지면", 위에 3개를 pop()하고 다시 스택에 쌓으면 됨
	A는 PPAP로 바뀔 수 없기 때문에, A가 나왔다면 반드시 다음은 P가 된다. 즉, A를 기준으로 앞의 두개가 P인가를 확인하면 된다.
	즉, 무지성으로 쌓다가 A가 나왔을 경우에 bool PPAP(int pos) 이런 함수를 만들면 된다. 이렇게 모든 값에 대하여 순서대로 처리하면, 마지막에 PPAP 4글자만이 남게 되고, 여기서 뒤에 세 문자를 지워버린 P가 남게된다.
	이 때 P만 남으면 PPAP를 출력하고, P가 아닌 다른 값도 남는다면 NP를 치면 된다
	*/
	char temp;
	for(int i = 0 ; i < input_str.length() ; i++){
		temp = input_str[i];
		if(temp == 'P'){
			s.push(temp);
		}
		else{
			if(PPAP(i)){
				s.pop();
			}
			else{
				cout << "NP\n";
				return 0;
			}
		}
	}
	
	if(s.size() > 1)	cout << "NP\n";
	else	cout << "PPAP\n";

	return 0;
}*/