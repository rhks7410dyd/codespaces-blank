#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int a,int b){
	return a > b;
}

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N,temp;
	cin >> N;
	vector <int> v;
	for(int i = 0 ; i < N ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());

	int max_sum = 0;
/*
		양수 양수 / 양수 0 / 양수 음수 / 0 음수
		개수가 홀수냐 음수이냐, 음수가 홀수개인가 짝수개인가 모두 다른 경우로 취급해야됨
		양수의 경우에는 무지성으로 큰 것부터 곱해주면서 내려가고, 음수는 가장 작은 것부터 올라가면 됨.
		1의 경우에는 더해주는게 + 1이므로 더해줘야됨
		0의 경우에는 음수와는 곱하는 것이, 양수와는 더하는 것이 이득임
*/
	int pos = 0;
	while(v[pos] <= 0 && pos < v.size() - 1){
		if(v[pos + 1] <= 0){ // 0 or minus value
			max_sum += v[pos] * v[pos + 1];
			pos += 2;
		}
		else{//positive value
			max_sum += v[pos];
			pos++;
		}
	}
	
	if(pos == v.size()){
		cout << max_sum << endl;
		return 0;
	}
	
	if(pos == v.size() - 1){
		cout << max_sum + v[pos] << endl;
		return 0;
	}
	
	//여기부터는 양수인 값이 있다는 것이 확정이 되어있음!
	pos = v.size() - 1;
	while(pos > 0 && v[pos] > 0){
		if(v[pos - 1] <= 0){
			max_sum += v[pos];
			break;
		}
		else{
			if(v[pos - 1] == 1){
				max_sum += v[pos] + 1;
			}
			else{
				max_sum += v[pos]*v[pos - 1];
			}
			pos -= 2;
		}
	}

	if(pos == -1){
		cout << max_sum << endl;
		return 0;
	}
	
	if(pos == 0){
		cout << max_sum + v[pos] << endl;
		return 0;
	}
	
	cout << max_sum << endl;
	return 0;
}