#include <iostream>
#include <queue>

using namespace std;

struct info{
	int pos,time;
};

/*
result를 2차원 배열로 만들어서 짝홀을 나누어 저장해야됨. 왜냐하면 88, 89 이렇게 더라도 89일 때 brother_pos의 값이 홀수여서 더 작을 수도 있음. 예시를 들자면
N 5434 K 6689일때 tpos 10875 tt 5  brother_pos[tpos] 91라고 나옴.
하지만 tpos 10694 tt 88  brother_pos[tpos] 89 여기서 만약에 위치 10694에 89번만에 도착할 수 있다면, 이 값이 최소가 될 수 있기 때문이다.
즉, 한 위치에 대하여 홀수인 최소 거리, 짝수인 최소 거리를 따로 구분해서 모두 해야될 필요가 있다. 이를 위해서는
bool soobin_visit[] 또한 2차원 배열로 변경해주어야 한다. 그리고 각 if 문에서의 값은 그 때 그 때 적절하게 알맞은 위치를 이미 방문했는지 식을 변경 시켜줘야 한다.
이것만 하면 될것 같은 느낌이 듬!
*/

int brother_pos[500001];
bool soobin_visit[500001][2];
int result = 1000000000;
int N,K;

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

int calcul_soo_pos(){
	queue<info> q;
	int pos = N;
	q.push({pos,0});
	soobin_visit[pos][0] = true;
	int tpos,tt;
	while(!q.empty()){
		tpos = q.front().pos;
		tt = q.front().time;
		q.pop();
		if(result < tt)	break;
		if(!((brother_pos[tpos] - tt) % 2) && brother_pos[tpos] >= tt){
			if(result > brother_pos[tpos]){
				result = brother_pos[tpos];
				//cout << "tpos " << tpos << " tt " << tt << "  brother_pos[tpos] " << brother_pos[tpos] << '\n';
			}
		}
		
		if(tpos + 1 <= 500000 && !soobin_visit[tpos + 1][(tt + 1) % 2]){
			soobin_visit[tpos + 1][(tt + 1) % 2] = true;
			q.push({tpos + 1 , tt + 1});
		}
		
		if(tpos - 1 >= 0 && !soobin_visit[tpos - 1][(tt + 1) % 2]){
			soobin_visit[tpos - 1][(tt + 1) % 2] = true;
			q.push({tpos - 1 , tt + 1});
		}
		
		if(tpos * 2 <= 500000 && !soobin_visit[2 * tpos][(tt + 1) % 2]){
			soobin_visit[2 * tpos][(tt + 1) % 2] = true;
			q.push({tpos * 2 , tt + 1});
		}
	}
	return result;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;
	
	for(int i = 0 ; i < 500001 ; i++)	brother_pos[i] = -1;
	
	calcul_bro_pos();
	
	int meet = calcul_soo_pos();
	
	if(meet == 1000000000){
		cout << -1 << '\n';
	}
	else{
		cout << meet << '\n';
	}
	

	return 0;
}
