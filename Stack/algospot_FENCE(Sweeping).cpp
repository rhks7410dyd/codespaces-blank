//백준 6549 문제와 동일한 문제임.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack<int> st;
vector<int> v;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C,N,t;
	scanf("%d",&C);
	
	for(int c = 0 ; c < C ; c++){
		scanf("%d",&N);
		
		for(int i = 1 ; i <= N ; i++){
			scanf("%d",&t);
			v.push_back(t);
		}
		
		
		int ans = 0;
		v.push_back(0);
		for(int i = 0 ; i <= N ; i++){
			while(!st.empty() && v[st.top()] >= v[i]){
				int c = st.top();
				st.pop();
				int width = st.empty() ? i : (i - st.top() - 1);
				ans = max(ans,v[c]*width);//이 식이 맞고 기존의 내가 낸 식이 틀린 이유가 중요함
			}
			st.push(i);
		}
		
		printf("%d\n",ans);
		
		v.clear();
		while(!st.empty()){
			st.pop();
		}
	}
	return 0;
}

/*
6
7
2 1 4 5 1 3 3
4
1000 1000 1000 1000
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2
7
15 2 2 2 2 2 1

8
4000
20
16
8
16
*/