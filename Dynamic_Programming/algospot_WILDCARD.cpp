/*
아래 주석 처리된 코드는 변형 전 완전 탐색 재귀 함수로 작성한 코드이다.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string wildcard;
vector<string> words;

bool recursive(string word,int pos,int now_command);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		int word_c;
		string temp;
		
		cin >> wildcard;
		cin >> word_c;
		
		for(int i = 0 ; i < word_c ; i++){
			cin >> temp;
			words.push_back(temp);
		}
		
		for(int i = 0 ; i < word_c ; i++){
			if(recursive(words[i],0,0)){
				cout << words[i] << '\n';
			}
		}
		
		words.clear();
	}
}

bool recursive(string word,int pos,int now_command){	
	if(pos >= word.size()){
		return (now_command == wildcard.size())||(wildcard[now_command]=='*' && now_command == wildcard.size()-1);
	}

	switch(wildcard[now_command]){
		case '*':
			return recursive(word,pos+1,now_command) || recursive(word,pos+1,now_command+1);
			break;
		case '?':
			return recursive(word,pos+1,now_command+1);
			break;
		default:
			if(word[pos] == wildcard[now_command])	return recursive(word,pos+1,now_command+1);
			break;
	}
	
	return false;
}

/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string wildcard;
vector<string> words;

bool recursive(string word,int pos,int now_command);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		int word_c;
		string temp;
		
		cin >> wildcard;
		cin >> word_c;
		
		for(int i = 0 ; i < word_c ; i++){
			cin >> temp;
			words.push_back(temp);
		}
		
		for(int i = 0 ; i < word_c ; i++){
			if(recursive(words[i],0,0)){
				cout << words[i] << '\n';
			}
		}
		
		words.clear();
	}
}

bool recursive(string word,int pos,int now_command){	
	if(pos >= word.size()){
		return (now_command == wildcard.size())||(wildcard[now_command]=='*' && now_command == wildcard.size()-1);
	}

	switch(wildcard[now_command]){
		case '*':
			return recursive(word,pos+1,now_command) || recursive(word,pos+1,now_command+1);
			break;
		case '?':
			return recursive(word,pos+1,now_command+1);
			break;
		default:
			if(word[pos] == wildcard[now_command])	return recursive(word,pos+1,now_command+1);
			break;
	}
	
	return false;
}
*/