#include <iostream>
#include <queue>

//세그폴트 떳음
using namespace std;

int visit[1000000010];
long long A,B;
queue<long long> q;

void BFS(){
	//cout <<"ln23\n"
	visit[A] = true;
	q.push(A);
	long long n;
	while(!q.empty()){
		n = q.front();
		q.pop();
		
		if(2*n <= B){
			visit[n*2] = visit[n] + 1;
			q.push(n*2);
		}
		if(10*n+1 <= B){
			visit[10*n + 1] = visit[n]+1;
			q.push(10*n + 1);
		}
	}
	if(!visit[B])	cout << -1 << endl;
	else{
		cout << visit[B] << endl;
	}
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> A >> B;
	
	BFS();

	return 0;
}