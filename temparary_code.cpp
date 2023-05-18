#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	// 1부터 4까지 저장할 벡터 선언
	// 배열도 가능!
	vector<int> v(4);

	// 4부터 1까지 벡터에 저장
	for(int i=0; i<4; i++){
		v[i] = 4-i;
	}
	v.push_back(1);

	// prev_permutation을 통해서 이전 순열 구하기
	do{

		for(int i=0; i<5; i++){
			//cout << v[i] << " ";
		}

		//cout << '\n';

	}while(prev_permutation(v.begin(),v.end()));

	int C = 5;
	while(C--){
		cout << C << endl;
	}
	
	return 0;

}