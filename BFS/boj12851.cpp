#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,K;
int shrt_path_count = -1;
int visit[100001];
vector<int> q;
bool endpos[100001];

/*
일단 중요한건 하나의 사이클을 깨지 않으면서, endpos 어레이를 트루로 바꿔줘야됨. 따라서 각 원소에 접근이 용이한
벡터를 사용하는 것이 좋을 것 같다. 다만 erase를 사용해 계속 앞에 있는 값을 지워줄 때, 시간 소모가 어떻게 되는지를 모르겠어서
일단 해보고 시간초과 나오면 유감이란 마인드로 가면 될것 같다. 여기서 qsize란 정수 값을 응용해서 한번에 삭제하는 방식도 나쁘지 않을 것 같다.
메모리초과가 뜰 수도 있겠지만 안뜬다는 가정하에 이게 빠름.
시간초과가 뜸.
*/

void BFS(){
	int pos,t_pos,qsize;
	bool visit_K = false;
	visit[N]=1;
	endpos[N] = true;
	q.push_back(N);
	
	while(!visit_K){
		shrt_path_count++;
		qsize = q.size();
		
		//cout << shrt_path_count << endl;
		
		for(int i = 0 ; i < qsize ; i++){
			//cout << "i " << q[i] << endl;
			pos = q[i];
			
			if(pos == K){
				visit_K = true;
				break;
			}
			
			t_pos = pos -1;
			if(t_pos > 0 && !endpos[t_pos]){
				//cout << "t_pos " << t_pos << endl;
				if(!visit[t_pos])	q.push_back(t_pos);
				visit[t_pos] += visit[pos];
			}
			
			t_pos = pos + 1;
			if(t_pos < 100001 && !endpos[t_pos]){
				//cout << "t_pos " << t_pos << endl;
				if(!visit[t_pos])	q.push_back(t_pos);
				visit[t_pos] += visit[pos];
			}
			
			t_pos = pos * 2;
			if(t_pos < 100001 && !endpos[t_pos]){
				//cout << "t_pos " << t_pos << endl;
				if(!visit[t_pos])	q.push_back(t_pos);
				visit[t_pos] += visit[pos];
			}
			//cout << endl;
		}
		//벡터에 여러번 푸쉬백 되는 문제를 해결해야됨.
		q.erase(q.begin(),q.begin()+qsize);
		
		for(int i = 0 ; i < q.size() ; i++){
			endpos[q[i]] = true;
		}
	}
	
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	
	BFS();
	
	cout << shrt_path_count << '\n' << visit[K] << '\n';
	
	/*
	for(int i = 1 ; i <= (N>K?N:K) + 1 ; i++){
		cout << visit[i] << ' ';
		if(i%10 == 0)	cout << endl;
	}
	cout << endl;
	*/
	
	return 0;
}