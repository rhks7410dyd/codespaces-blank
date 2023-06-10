#include <iostream>
#include <vector>

using namespace std;

vector<int> min_val;
vector<int> ans_arr;
int Input[1000000];

void put_num(int num);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,t;
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&Input[i]);
		put_num(Input[i]);
	}
	
	/*
	이 파트는 이렇게 하면 안되고 첫 크기에 대한 답을 이용해서 배열을 찾아야할듯
	똑같은 과정을 거꾸로 큰 수를 입력하게 만들어주면 될듯?
	*/
	
	ans_arr.push_back(987654321);
	int now_pos = 0;
	int max_point;
	for(int i = N -1 ; i >= 0 ; i--){
		if(Input[i] == min_val[min_val.size()-1]){
			max_point = i;
			break;
		}
	}
	for(int i = max_point ; i >= 0 ; i--){
		if(ans_arr[now_pos] > Input[i]){
			ans_arr.push_back(Input[i]);
			now_pos++;
		}
		else if(ans_arr[now_pos-1] > Input[i]){
			ans_arr[now_pos] = Input[i];
		}
	}
	
	printf("%ld\n",min_val.size());
	for(int i = ans_arr.size()-1 ; i > 0 ; i--){
		printf("%d ",ans_arr[i]);
	}
	printf("\n");
	
	return 0;
}

void put_num(int num){
	if(min_val.empty()){
		min_val.push_back(num);
		return;
	}
	
	if(min_val[0] >= num)	min_val[0] = num;
	else if(min_val[min_val.size()-1] < num)	min_val.push_back(num);
	else if(min_val[min_val.size()-1] != num){
		int start = 0,end = min_val.size();
		while(start < end){
			int mid = (start+end)/2;
			if(min_val[mid] > num && min_val[mid-1] < num){
				min_val[mid] = num;
				return;
			}
			
			if(min_val[mid] < num){
				start = mid+1;
			}
			else{
				end = mid;
			}
		}
	}
}