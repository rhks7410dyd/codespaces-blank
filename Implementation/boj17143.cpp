#include <iostream>
#include <utility>

using namespace std;

struct sharkinfo{
	int r,c,s,d,z;
	bool catched = false;
	sharkinfo(){
		r = 0;
		c = 0;
		s = 0;
		d = 0;
		z = 0;
		catched = false;
	}
};

struct sharkinfo info[10001];
int map[101][101];
int R,C,M;

void move_point(int num);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d %d",&R,&C,&M);
	
	if(!M){
		printf("0\n");
		return 0;
	}
	
	for(int i = 1 ; i <= M ; i++){
		scanf("%d %d %d %d %d",&info[i].r,&info[i].c,&info[i].s,&info[i].d,&info[i].z);
		map[info[i].r][info[i].c] = i;
	}
	
	int ans = 0;
	bool get_shark;
	for(int i = 1 ; i <= C ; i++){
		for(int j = 1 ; j <= R ; j++){
			if(map[i][j]){
				ans++;
				info[map[i][j]].catched = true;
				break;
			}
		}
		
		for(int j = 1 ; j <= M ; j++){
			if(!info[j].catched){
				move_point(j);
			}
		}
	}
	
	return 0;
}

void move_point(int num){
	auto& now = info[num];
	
	if(now.s == 0){
		return;
	}
	
	switch(now.d){
		case 1://up
			now.r = moving_ver(now.r,now.s,true);
			break;
		case 2://down
			now.r = moving_ver(now.r,now.s,false);
			break;
		case 3://right
			now.c = moving_hor(now.c,now.s,true);
			break;
		case 4://left
			now.c = moving_hor(now.c,now.s,false);
			break;
	}
	
	if(map[now.r][now.c] != 0){
		auto& same_pos_shark = info[map[now.r][now.c]];
		if(now.z > same_pos_shark.z){
			same_pos_shark.catched = true;
		}
		else{
			now.catched = true;
		}
	}
}

//이동해야되는 남은 거리량 > (가로or세로의 길이 - 1) 인 경우, 우항의 값만큼 dis에서 빼주고 bool 값을 뒤집음
//이동해야되는 남은 거리량 <= (가로or세로의 길이 - 1) 일 때는 그냥 이만큼 이동시킴
int moving_ver(int start,int dis,bool up){
	while(dis > 0){
		
	}
}

int moving_hor(int start,int dis,bool right){
	
}