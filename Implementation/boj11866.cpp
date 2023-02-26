#include <iostream>
#include <queue>

using namespace std;

/*
시간이 엄청 여유 있어서 그냥 계속 돌릴려고 했는데, 문제를 보니까 알고리즘 분류에 큐가 있는 걸 보니 숫자를 다 넣고 반복 될 때마다 pop만 하고 다시 push를 하지 않는 식으로
숫자가 쓰였는지 아닌지 확인하지 않고 돌아갈 수 있게 만들고 돌리라는 것 같다.
*/

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,K;
	
	cin >> N >> K;
	
	queue<int> q;
	for(int i = 1 ; i <= N ; i++){
		q.push(i);
	}
	
	//이미 돈 곳이 있는데 1부터 시작하니까 틀림. 시작점을 특정해주기 위해서 위에 for문의 조건을 다르게 제한할 필요가 있음.
	cout << '<';
	int temp,circle=1;
	bool not_first = false;
	while(!q.empty()){
		if(circle == K){
			if(not_first)	cout << ", ";
			cout << q.front();
			q.pop();
			circle = 1;
			not_first = true;
			continue;
		}
		circle++;
		temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << ">\n";
}