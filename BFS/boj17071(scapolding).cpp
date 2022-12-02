#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <climits>
#include <random>
using namespace std;
 
#define X first 
#define Y second 
 
struct info{
	int pos,time;
};

int brother_pos[500001];
bool soobin_visit[500001];
int N,K;
int n, k; 
bool visited[500001][2];

void calcul_bro_pos(){
	int n = 1, pos = K;
	brother_pos[pos] = 0;
	int t = pos + 1;
	
	while(t<=500000){
		brother_pos[t] = n;
		n++;
		t += n;
	}
	
	//뒤로 이동할 수는 없다는 이야기인 것 같아서 테스트 해봐야됨.
	/*t = pos - 1;
	n = 1;
	while(t >= 0){
		brother_pos[t] = n;
		n++;
		t -= n;
	}*/
}

int calcul_soo_pos_scapolding(){
	int result = 1000000000;
	queue<info> q;
	int pos = N;
	q.push({pos,0});
	soobin_visit[pos] = true;
	int tpos,tt;
	while(!q.empty()){
		tpos = q.front().pos;
		tt = q.front().time;
		q.pop();
		//
		if(result < tt)	break;
		if(!((brother_pos[tpos] - tt) % 2) && brother_pos[tpos] >= tt){
			if(result > brother_pos[tpos]){
				result = brother_pos[tpos];
				//cout << "tpos " << tpos << " tt " << tt << "  brother_pos[tpos] " << brother_pos[tpos] << '\n';
			}
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
	return result;
}

int scapolding(){
	n = N;
	k = K;
    queue<pair<int, int> > Q;
    Q.push({ n, 0 });
    visited[n][0] = true;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if (k + cur.Y * (cur.Y + 1) / 2 > 500000) {
            return -1;
        }
        if (visited[k + cur.Y * (cur.Y + 1) / 2][cur.Y % 2]) {
            return cur.Y;
        }
        if (2 * cur.X <= 500000 && !visited[2 * cur.X][(cur.Y + 1) % 2]) {
            Q.push({2 * cur.X, cur.Y + 1 });
            visited[2 * cur.X][(cur.Y + 1) % 2] = cur.Y + 1;
        }
        if (cur.X + 1 <= 500000 && !visited[cur.X + 1][(cur.Y + 1) % 2]) {
            Q.push({cur.X + 1, cur.Y + 1 });
            visited[cur.X + 1][(cur.Y + 1) % 2] = cur.Y + 1;
        }
        if (cur.X - 1 >= 0 && !visited[cur.X - 1][(cur.Y + 1) % 2]) {
            Q.push({cur.X - 1, cur.Y + 1 });
            visited[cur.X - 1][(cur.Y + 1) % 2] = cur.Y + 1;
        }
    }
	return -1;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	//스캐폴딩
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 10000);
		
	while(true){
		for(int i = 0 ; i < 500001 ; i++){
			brother_pos[i] = -1;
			soobin_visit[i] = false;
			visited[i][0] = 0;
			visited[i][1] = 0;
		}
		N = dis(gen);
		K = dis(gen);
		calcul_bro_pos();
		int cal = calcul_soo_pos_scapolding();
		int scapolding_cal = scapolding();
		if(cal == scapolding_cal) continue;
		else{
			cout << "It's error! origin code val " << cal << " and scapolding val " << scapolding_cal;
			cout << endl << "N " << N << " K " << K << endl;
			break;
		}
	}
	return 0;
}



