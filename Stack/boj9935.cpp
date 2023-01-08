#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	
    string input_str,boom_str,temp="";
    cin >> input_str >> boom_str;
    for(int i=0; i<input_str.size(); i++){// 2
        temp+=input_str[i];
        if(temp.back()==boom_str.back()){ // 3
            bool ch = true;
            if(temp.size()<boom_str.size()) continue; // 4
            for(int j=0; j<boom_str.size(); j++){ // 5
                if(temp[temp.size()-boom_str.size()+j]!=boom_str[j]){
                    ch = false;
                    break;
                }
            }
            if(ch){ // 6
                for(int j=0; j<boom_str.size(); j++) temp.pop_back();
            }
        }
    }
	
    if(temp.empty()) cout << "FRULA" << "\n"; // 7
    else cout << temp << "\n";
    return 0;
}