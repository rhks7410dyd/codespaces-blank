#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long student_head_count,temp_num;
	vector<long long> expect_num;
	cin >> student_head_count;
	for(int i = 0 ; i < student_head_count ; i++){
		cin >> temp_num;
		expect_num.push_back(temp_num);
	}
	sort(expect_num.begin(),expect_num.end());
	long long dissat = 0;
	for(long long i = 0 ; i < student_head_count ; i++){
		dissat += abs(i-expect_num[i]+1);
	}
	cout << dissat << endl;
	return 0;
}