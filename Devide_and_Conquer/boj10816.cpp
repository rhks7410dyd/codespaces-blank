/*
엄청나게 절지는 않았는데, 인풋 확인하는데 1분, 이진 탐색에서 절어서 5분정도 까먹어서 20분 49초 걸림
1. 알고리즘 정리 -> 1~2분
2. 타이핑 -> 15분 안쪽
3. 이진탐색에서 헤맨 시간 -> 5분 내외
4. 변수 어떻게 설정할지, 전역으로할지 지역으로 할지 등등 쓸데없는데 2~3분 정도

결론적으로 바로 확신을 가지고 푼다고 가정하면, 15분 안쪽으로 풀이 가능함.
알고리즘 구현할 때 세밀한 부분에 대한 암기 부족, 변수 설정 능력 부족, 문제 해결 개관에 대한 설계 능력 부족
이정도의 단점이 드러났다고 할 수 있음.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_n,g_m;
vector<int> input;
vector<pair<int,int>> v;//first가 val, second가 개수

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&g_n);

	int t;
	for(int i = 0 ; i < g_n ; i++){
		scanf("%d",&t);
		input.push_back(t);
	}
	
	sort(input.begin(),input.end());
	
	int idx = 0;
	v.push_back({input[0],1});
	for(int i = 1 ; i < g_n ; i++){
		if(v[idx].first != input[i]){
			v.push_back({input[i],1});
			idx++;
		}
		else{
			v[idx].second++;
		}
	}
	
	scanf("%d",&g_m);
	
	for(int i = 0 ; i < g_m ; i++){
		scanf("%d",&t);
		int c = 0;
		
		int st = 0, ed = v.size()-1;
		
		while(st <= ed){
			int mid = (st+ed)/2;
			int now_val = v[mid].first;
			if(now_val == t){
				c = v[mid].second;
				break;
			}
			
			if(now_val > t){
				ed = mid-1;
			}
			else{
				st = mid + 1;
			}
		}
		
		printf("%d ",c);
	}
	printf("\n");
	
	return 0;
}

