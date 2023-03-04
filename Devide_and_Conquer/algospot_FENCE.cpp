//백준 6549 문제와 동일한 문제임.
#include <iostream>
#include <stack>

using namespace std;

stack<pair<int,int>> st;//first -> height, second -> index number

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C,N,t;
	scanf("%d",&C);
	
	for(int c = 0 ; c < C ; c++){
		int max = -1;
		scanf("%d",&N);
		for(int i = 0 ; i < N ; i++){
			scanf("%d",&t);
			if(st.empty() || st.top().first < t){
				st.push({t,i});
				continue;
			}
			
			while(!st.empty() && st.top().first > t){
				int dif = i - st.top().second;
				int t_area = dif * st.top().first;
				if(t_area > max){
					max = t_area;
				}
				st.pop();
			}
			
			if(!st.empty() && st.top().first == t){
				continue;
			}
			
			st.push({t,i});
		}
		
		while(st.size() > 1){
			int dif = N - st.top().second;
			int t_area = dif * st.top().first;
			if(t_area > max){
				max = t_area;
			}
			st.pop();
		}
		
		int t_area = st.top().first * N;
		if(t_area > max){
			max = t_area;
		}
		cout << max << '\n';
		
		while(!st.empty()){
			st.pop();
		}
	}
	return 0;
}
/*
7
7 1 5 9 6 7 3
*/