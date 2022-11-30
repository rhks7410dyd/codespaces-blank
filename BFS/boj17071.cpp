#include <iostream>
#include <queue>

using namespace std;

struct info{
	int pos,time;
};

int brother_pos[500001];
bool soobin_visit[500001];
int N,K;

void calcul_bro_pos(int pos){
	int n = 1;
	brother_pos[pos] = 0;
	int t = pos + 1;
	
	while(t<=500000){
		brother_pos[t] = n;
		n++;
		t += n;
	}
	
	t = pos - 1;
	n = 1;
	while(t >= 0){
		brother_pos[t] = n;
		n++;
		t -= n;
	}
}

bool calcul_soo_pos(int pos){
	queue<info> q;
	q.push({pos,0});
	soobin_visit[pos] = true;
	int tpos,tt;
	while(!q.empty()){
		tpos = q.front().pos;
		tt = q.front().time;
		q.pop();
		
		if(brother_pos[tpos] == tt){
			cout << tt << '\n';
			return true;
		}
		
		if(tpos + 1 <= 500000 && !soobin_visit[tpos + 1]){
			soobin_visit[tpos + 1] = true;
			q.push({tpos + 1 , tt + 1});
		}
		
		if(tpos - 1 >= 0 && !soobin_visit[tpos - 1]){
			soobin_visit[tpos - 1] = true;
			q.push({tpos - 1 , tt + 1});
		}
		
		if(tpos * 2 <= 500000 && !soobin_visit[2 * tpos]){
			soobin_visit[2 * tpos] = true;
			q.push({tpos * 2 , tt + 1});
		}
	}
	return false;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	
	for(int i = 0 ; i < 500001 ; i++)	brother_pos[i] = -1;
	
	calcul_bro_pos(K);
	
	bool meet = calcul_soo_pos(N);
	if(!meet){
		cout << -1 << '\n';
	}
	return 0;
}