#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct ans_type{
	int num,floor;
	ans_type(int n,int f) : num(n),floor(f) {}
	bool operator<(const ans_type A) const {
		if(this->floor != A.floor){
			return this->floor > A.floor;
		}
		return this-> num > A.num;
	}
};

int n,m;
vector<int> v[32001];
priority_queue<ans_type> answer;
queue<int> q;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&n,&m);
	for(int i = 1 ; i <= n ; i++){
		v[i].push_back(0);
	}
	
	int a,b;
	for(int i = 1 ; i <= m ; i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b][0]++;
	}
	
	for(int i = 1 ; i <= n ; i++){
		if(v[i][0] == 0){
			q.push(i);
		}
	}
	
	//여기가 잘못됨
	int t = 0;
	while(!q.empty()){
		int qsize = q.size();
		for(int c = 0 ; c < qsize ; c++){
			int now = q.front();
			q.pop();
			answer.push(ans_type(now,t));

			for(int i = 1 ; i < v[now].size() ; i++){
				int next = v[now][i];
				v[next][0]--;
				if(v[next][0] == 0){
					q.push(next);
				}
			}
		}
		t++;
	}
	
	while(!answer.empty()){
		int t = answer.top().num;
		answer.pop();
		printf("%d ", t);
	}
	
	return 0;
}

/*테케
6 7
5 6
5 2
2 1
6 1
2 4
1 3
4 3
답) 5 2 4 6 1 3

5 3
4 1
3 1
5 3
2 4 5 3 1

5 4
5 4
4 3
3 2 
2 1
5 4 3 2 1

4 2
4 2
3 1
3 1 4 2

5 4
4 1
5 1
2 5 
3 5
2 3 4 5 1

6 7
5 6
5 2
2 4
4 3
2 1
6 1
1 3
5 2 4 6 1 3

4 2
1 4
3 2
1 3 2 4

5 4
4 1
5 1
2 5
3 5
2 3 4 5 1
*/