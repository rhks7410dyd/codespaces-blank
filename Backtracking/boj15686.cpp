#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct pos{
	int c,r;
};

int N,M;
int map[50][50];
int dist_to_chiken[100][13];
vector <pos> home;
vector <pos> chiken;
vector<int> combination;
/*비트마스킹을 응용하면 vector <int> comb 이런식으로 일차원 벡터를 이용해서도 저장 가능하다.
M <= 13 이므로 2^13 까지 사용가능하면 되는데, int 범위로도 충분히 커버가 됨.
그냥 공부 겸용으로 이런식으로 구현하기 -> 찾아보니 비트마스킹 + 해쉬라고 생각하면 될듯
비트마스킹의 의미가 이진수 구조를 응용해 자료구조를 구현하는 것이므로 해시 함수를 이진수를 통해 구현했다! 라고 생각하면 될듯
*/

void comb(int set,int count,int p){//set은 비트마스킹된 조합 집합, count는 현재 집합에 포함된 개수, p는 이번에 넣을지 말지 결정할 치킨 벡터의 인덱스 위치
	if(count == M){//m개의 치킨집을 모두 고른 경우
		combination.push_back(set);
	}
	else{//치킨 집을 추가적으로 선택해야되는 경우 (count < M)
		if(p == chiken.size() - 1){//마지막 인덱스인 경우
			if(count == M - 1){
				set += 1 << (chiken.size() - 1);
				combination.push_back(set);
			}
		}
		else{
			comb(set,count,p+1);
			set += 1 << p;
			comb(set,count+1,p+1);
		}
	}
}

void calcule_chiken_dis(){
	int hsize,csize;
	hsize = home.size();
	csize = chiken.size();
	//cout << "size " << hsize << ' ' << csize << endl;
	for(int i = 0 ; i < hsize ; ++i){
		auto h = home[i];
		for(int j = 0 ; j < csize ; ++j){
			//cout << "i & j " << i << ' ' << j << endl;
			auto c = chiken[j];
			dist_to_chiken[i][j] = abs(h.c - c.c) + abs(h.r - c.r);
		}
	}
}

int get_chiken_dis(int set){
	bool in_combination[100];
	int dis[100];
	
	for(int i = 0 ; i < 100 ; i++)	dis[i] = 987654321;		
	//hearthstone
	int i = 0;
	while(set > 0){
		if(set % 2 == 1){
			in_combination[i] = true;
		}
		i++;
		set >> 1;
	}
	
	for(int i = 0 ; i < home.size() ; i++){
		for(int j = 0 ; j < chiken.size() ; j++){
			if(in_combination[j] && dis[i] > dist_to_chiken[i][j])	dis[i] = dist_to_chiken[i][j];
		}
	}
	
	int sum = 0;
	for(int i = 0 ; i < home.size() ; i++)	sum += dis[i];
	
	return sum;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for(int c = 0 ; c < N ; c++){
		for(int r = 0 ; r < N ; r++){
			cin >> map[c][r];
			if(map[c][r]){//1 or 2인 경우
				if(map[c][r] == 1){
					home.push_back({c,r});
				}
				else{
					chiken.push_back({c,r});
				}
			}
		}
	}
	
	comb(0,0,0);
	
	/*//비트마스킹된 조합 집합 출력함. 이상 X
	cout << endl << "chiken_count " << chiken.size() << " N " << N << " M " << M << endl;
	for(int i = 0 ; i < combination.size() ; i++){
		cout << combination[i] << endl;
	}
	*/
	
	//반복되는 계산이 많이 나올 수 밖에 없으므로, 각 치킨 집에서 각 집까지의 거리 값을 저장하기
	//이후에는 단순히 값을 불러와서 더해주는 방식으로 get_chiken_dis()함수를 구현하면 동일 계산을 적게 할 수 있음.
	
	calcule_chiken_dis();
	
	cout << "ln117\n";
	
	int t,min_chiken_dis = 987654321;
	for(int i = 0 ; i < combination.size() ; i++){
		t = get_chiken_dis(combination[i]);
		if(t < min_chiken_dis){
			min_chiken_dis = t;
		}
	}
	
	cout << min_chiken_dis << endl;
	
	return 0;
}