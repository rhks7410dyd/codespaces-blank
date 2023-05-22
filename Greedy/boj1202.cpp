#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 300001
using namespace std;

int N,K;
int backpack[MAX];
pair<int,int> info[MAX];
priority_queue<int, vector<int>, less<int>> pq;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&N,&K);
	
	int w,v;
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&info[i].first,&info[i].second);
	}
	
	for(int i = 0 ; i < K ; i++){
		scanf("%d",&backpack[i]);
	}
	
	sort(info,info+N);
	sort(backpack,backpack+K);
	
	long long ans = 0;
	int index = 0;
	for(int i = 0 ; i < K ; i++){
		while(index < N && backpack[i] >= info[index].first){
			pq.push(info[index].second);
			index++;
		}
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}	