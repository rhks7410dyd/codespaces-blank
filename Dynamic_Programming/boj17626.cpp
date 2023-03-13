/*
종만북에서 기본적으로 DP는 재귀 함수를 활용한 완전 탐색 형태에서 변경되었다고 했기 때문에, 이 문제는 우선 재귀 함수를 활용해 완전 탐색하는 형태에서
변형하는 방식으로 풀어보도록 했음 하지만 머리가 안굴러가서 그냥 다 구해버림
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	int N,ans,temp;
	cin >> N;
	
	vector<int> one;
	vector<int> two;
	vector<int> three;
	bool find_ans = false;
	for(int i = 1 ; i < 240 ; i++){
		temp = i*i;
		if(temp == N){
			cout << 1 << "\n";
			return 0;
		}
		one.push_back(i*i);
	}
	
	for(int i = 0 ; i < one.size() ; i++){
		for(int j = i ; j < one.size() ; j++){
			temp = one[i] + one[j];
			if(temp == N){
				cout << 2 << "\n";
				return 0;
			}
			two.push_back(one[i] + one[j]);
		}
	}
	
	for(int i = 0 ; i < one.size() ; i++){
		for(int j = 0; j < two.size() ; j++){
			temp = one[i] + two[j];
			if(temp == N){
				cout << 3 << "\n";
				return 0;
			}
		}
	}
	
	cout << 4 << "\n";
	return 0;
}