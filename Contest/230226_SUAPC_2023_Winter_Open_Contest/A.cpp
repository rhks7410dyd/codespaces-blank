#include <iostream>
#include <queue>
#include <string>

using namespace std;

int point[8] = {10,8,6,5,4,3,2,1};
pair<int,char> info[8];

int form_change(string str){
	int t = 0;
	t += 1000*((str[0]-'0')*60 + (str[2]-'0')*10 + (str[3]-'0')) + (str[5]-'0')*100 + (str[6]-'0')*10 + (str[7]-'0');
	return t;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	priority_queue<int> pq;
	
	int temp,b_point=0,r_point=0;
	string input_str;
	char input_c;
	
	for(int i = 0 ; i < 8 ; i++){
		cin >> input_str >> input_c;
		temp = form_change(input_str);
		pq.push(-temp);
		//cout << input_str << endl;
		info[i].first = temp;
		info[i].second = input_c;
	}
	
	for(int i = 0 ; i < 8 ; i++){
		temp = - pq.top();
		pq.pop();
		for(int j = 0 ; j < 8 ; j++){
			if(info[j].first == temp){
				if(info[j].second == 'B'){
					b_point += point[i];
				}
				else{
					r_point += point[i];
				}
				break;
			}
		}
	}
	
	if(b_point > r_point){
		cout << "Blue\n";
	}
	else{
		cout << "Red\n";
	}
	
	return 0;
}