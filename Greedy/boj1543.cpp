// 중간에 빠진 내용이 없어져서 앞 뒤가 이어지는 것이 아니기 때문에, 탐욕법으로 최대한 앞쪽부터 해야 최대 값이 나올 수 있다. 따라서 맨 앞 글자부터 하나씩 맞는지 확인을 하면 됨

#include <iostream>
#include <string>

using namespace std;

int main(){
	string word,str;
	bool correct;
	int c = 0;
	
	getline(cin, str);
	getline(cin, word);
	
	//cout << str << ' ' << str.size() << endl << word << ' ' << word.size() << endl;
	for(int i = 0 ; i < str.size() - word.size() + 1;){
		//cout << i << endl;
		correct = true;
		for(int j = 0 ; j < word.size() ; j++){
			if(i + j >= str.size()){
				cout << c << endl;
				return 0;
			}
			if(str[i+j] != word[j]){
				correct = false;
				break;
			}
		}
		if(correct){
			i += word.size();
			c++;
		}
		else	i++;
	}
	
	cout << c << '\n';
	
	return 0;
}