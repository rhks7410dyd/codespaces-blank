#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<int> v[32001];
vector<int> ans;
queue<int> q;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&N,&M);
	
	for(int i = 1 ; i <= N ; i++){
		v[i].push_back(0);
	}
	
	int n1,n2;
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d",&n1,&n2);
		v[n1].push_back(n2);
		v[n2][0]++;
	}
	
	for(int i = 1 ; i <= N ; i++){
		if(v[i][0] == 0){
			ans.push_back(i);
		}
	}
	
	int pos = 0;
	
	while(pos < ans.size()){
		int now = ans[pos];
		for(int i = 1 ; i < v[now].size() ; i++){
			int nxt = v[now][i];
			v[nxt][0]--;
			if(v[nxt][0] == 0){
				ans.push_back(nxt);
			}
		}
		pos++;
	}
	
	if(ans.size() == N){
		for(int i = 0 ; i < ans.size() ; i++){
			printf("%d ",ans[i]);
		}
	}
	else{
		bool is_printed[N+1];
		for(int i = 0 ; i < ans.size() ; i++){
			printf("%d ",ans[i]);
			is_printed[ans[i]] = true;
		}
		for(int i = 1 ; i <= N ; i++){
			if(!is_printed[i]){
				printf("%d ",i);
			}
		}
	}
	printf("\n");
	return 0;
}