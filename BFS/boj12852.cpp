#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,Time=0;
int history[1000010];
queue<int> q;

bool put_in_que(int val);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	if(N == 1){
		printf("0\n1\n");
		return 0;
	}
	int t;
	
	q.push(N);
	bool find_rute = false;
	while(!find_rute){
		Time++;
		int qsize = q.size();
		for(int i = 0 ; i < qsize ; i++){
			t= q.front();
			q.pop();

			if(t % 3 == 0 && history[t/3] == 0){
				history[t/3] = t;
				find_rute = put_in_que(t/3);
				if(find_rute)	break;
			}
			
			if(t % 2 == 0 && history[t/2] == 0){
				history[t/2] = t;
				find_rute = put_in_que(t/2);
				if(find_rute)	break;
			}
			
			if(history[t-1] == 0){
				history[t-1] = t;
				find_rute = put_in_que(t-1);
				if(find_rute)	break;
			}
		}
	}
}

bool put_in_que(int val){
	if(val == 1){
		vector<int> v;
		int t=1;
		
		v.push_back(1);
		while(t != N){
			t = history[t];
			v.push_back(t);
		}
		
		printf("%d\n",Time);
		for(int i = v.size() - 1 ; i >= 0 ; i--){
			printf("%d ",v[i]);
		}
		printf("\n");
		return true;
	}
	
	q.push(val);
	
	return false;
}