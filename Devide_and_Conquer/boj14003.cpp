#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1000000
using namespace std;

vector<pair<int,int>> min_val[MAX];
vector<int> ans_arr;
int Input[MAX];
int l_of_min_val[MAX];
int m_size=0;

void put_num(int num,int pos);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,t;
	scanf("%d",&N);
	
	memset(l_of_min_val,-1,sizeof(l_of_min_val));
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&Input[i]);
		put_num(Input[i],i);
	}
	
	auto pre = min_val[m_size-1][l_of_min_val[m_size-1]];
	ans_arr.push_back(pre.first);
	int now_pos = m_size-2;
	while(now_pos >= 0){
		int idx = l_of_min_val[now_pos];
		while(idx>=0){
			auto now = min_val[now_pos][idx];
			if(now.first < pre.first && now.second < pre.second){
				pre = now;
				ans_arr.push_back(pre.first);
				now_pos--;
				break;
			}
			else{
				idx--;
			}
		}
	}
	
	printf("%d\n",m_size);
	for(int i = ans_arr.size()-1 ; i >= 0 ; i--){
		printf("%d ",ans_arr[i]);
	}
	printf("\n");
	
	return 0;
}

void put_num(int num,int pos){
	if(pos == 0){
		min_val[0].push_back({num,0});
		l_of_min_val[0]++;
		m_size++;
		return;
	}
	
	if(min_val[0][l_of_min_val[0]].first >= num){
		min_val[0].push_back({num,pos});
		l_of_min_val[0]++;
	}
	else if(min_val[m_size-1][l_of_min_val[m_size-1]].first < num){
		min_val[m_size].push_back({num,pos});
		l_of_min_val[m_size]++;
		m_size++;
	}
	else if(min_val[m_size-1][l_of_min_val[m_size-1]].first != num){
		int start = 0,end = m_size;
		while(start < end){
			int mid = (start+end)/2;
			if(min_val[mid][l_of_min_val[mid]].first > num && min_val[mid-1][l_of_min_val[mid-1]].first < num){
				min_val[mid].push_back({num,pos});
				l_of_min_val[mid]++;
				return;
			}
			
			if(min_val[mid][l_of_min_val[mid]].first < num){
				start = mid + 1;
			}
			else{
				end = mid;
			}
		}
	}
}
/*
#1
20
85 46 20 32 34 90 61 96 52 9 70 57 59 15 37 82 75 44 12 52
정답)

출력)
7
9 15 37 82

#2
*/