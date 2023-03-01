/*
시간 20:05 걸림
1. 벡터 erase 함수에 대한 부족한 이해(iter를 사용해보려다가 오류가 나서 처음에 생각한대로 v.erase(v.begin())을 사용하게 된 것)
2. t 초기화 위치 문제
전체적으로 보면 자주 사용하지 않는 erase 함수 자체에 대한 문제였다고 생각이 든다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int C;
	scanf("%d",&C);
	
	int t;
	vector<pair<int,int>> v;
	for(int c = 0 ; c < C ; c++){
		int n,m,t;
		scanf("%d %d",&n,&m);
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&t);
			v.push_back({i,t});
		}
		
		t=1;
		bool is_most_important;
		while(true){
			is_most_important = true;
			
			int f_val = v[0].second;
			int f_num = v[0].first;
			
			
			for(int i = 1 ; i < v.size() ; i++){
				if(v[i].second > f_val){
					is_most_important = false;
					break;
				}
			}
			
			v.erase(v.begin());
			if(is_most_important){
				if(f_num == m){
					printf("%d\n",t);
					break;
				}
				//printf("%d is deleted\n",f_num);
				t++;
			}
			else{
				v.push_back({f_num,f_val});
			}
		}
		v.clear();
	}
}