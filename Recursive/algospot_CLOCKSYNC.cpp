#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int input[16];
vector<int> temp;
vector<int> swit[10] = {
	{0,1,2},
	{3,7,9,11},
	{4, 10, 14, 15},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15},
	{3,14,15},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};

/* information of switch
0	0, 1, 2
1	3, 7, 9, 11
2	4, 10, 14, 15
3	0, 4, 5, 6, 7
4	6, 7, 8, 10, 12
5	0, 2, 14, 15
6	3, 14, 15
7	4, 5, 7, 14, 15
8	1, 2, 3, 4, 5
9	3, 4, 5, 9, 13
*/

int get_minimum(int idx,int push_count);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	
	for(int c = 0 ; c < C ; c++){
		for(int i = 0 ; i < 16 ; i++){
			cin >> input[i];
			input[i] %= 12; // 12를 0으로 바꿔주는 식
			temp.push_back(input[i]);
		}
		
		int res = get_minimum(0,0);
		
		cout << res << endl;
	}
	
	return 0;
}

int get_minimum(int idx,int push_count){
	if(idx > 9){
		bool all_clock_is_12 = true;
		for(int i = 0 ; i < 16 ; i ++){
			if(input[i]){
				all_clock_is_12 = false;
				break;
			}
		}
		
		if(all_clock_is_12){
			return push_count;
		}
		else{
			return INF;
		}
	}
	
	int ret = INF;
	
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < swit[idx].size() ; j++){
			int now_num = swit[idx][j];
			input[now_num] += i*3;
			input[now_num] %= 12;
		}
		
		int temp = get_minimum(idx+1,push_count + i);
		
		if(temp < ret){
			if(ret != INF && idx == 0)	cout << "return value is changed : " << ret << ' ' << temp << endl;
			ret = temp;
		}
		
		for(int j = 0 ; j < swit[idx].size() ; j++){
			int now_num = swit[idx][j];
			input[now_num] -= i*3;
			if(input[now_num] < 0)	input[now_num] += 12;
		}
	}
	
	return ret;
}

/*
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6*/