#include <iostream>
#include <utility>

using namespace std;

struct sharkinfo{
	int r,c,s,d,z;
	bool catched;
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
int map[2][101][101];
int R,C,M;

void move_point(int num,int map_idx);
void print_map(int map_idx);
void moving_ver(int num,bool up);
void moving_hor(int num,bool right);

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
		map[0][info[i].r][info[i].c] = i;
		if(info[i].d < 3 && R != 2){
			info[i].s %= 2*(R-1);
		}
		if(info[i].d > 2 && C != 2){
			info[i].s %= 2*(C-1);
		}
	}
	
	int ans = 0;
	for(int i = 1 ; i <= C ; i++){
		//printf("i %d ",i);
		//print_map((i-1)%2);
		for(int j = 1 ; j <= R ; j++){
			if(map[(i-1)%2][j][i]){
				ans+= info[map[(i-1)%2][j][i]].z;
				info[map[(i-1)%2][j][i]].catched = true;
				break;
			}
		}
		
		for(int a = 1 ; a <= R ; a++){
			for(int b = 1 ; b <= C ; b++){
				map[i%2][a][b] = 0;
			}
		}
		
		for(int j = 1 ; j <= M ; j++){
			if(!info[j].catched){
				move_point(j,i%2);
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

void move_point(int num,int map_idx){
	auto& now = info[num];
	
	/*if(now.s == 1 || now.s == 2){
		moving_ver(num,now.s%2);
	}
	else{
		moving_hor(num,now.s%2);
	}*/
	if(now.s != 0){
		switch(now.d){
			case 1://up
				moving_ver(num,true);
				break;
			case 2://down
				moving_ver(num,false);
				break;
			case 3://right
				moving_hor(num,true);
				break;
			case 4://left
				moving_hor(num,false);
				break;
		}
	}
	
	if(map[map_idx][now.r][now.c] == 0){
		map[map_idx][now.r][now.c] = num;
	}
	else{
		auto& same_pos_shark = info[map[map_idx][now.r][now.c]];
		if(now.z > same_pos_shark.z){
			same_pos_shark.catched = true;
			map[map_idx][now.r][now.c] = num;
		}
		else{
			now.catched = true;
		}
	}
}

void print_map(int map_idx){
	printf("print map\n");
	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			printf("%d ",map[map_idx][i][j]);
		}
		printf("\n");
	}
}

//이동해야되는 남은 거리량 > (가로or세로의 길이 - 1) 인 경우, 우항의 값만큼 dis에서 빼주고 bool 값을 뒤집음
//이동해야되는 남은 거리량 <= (가로or세로의 길이 - 1) 일 때는 그냥 이만큼 이동시킴
void moving_ver(int num,bool up){
	auto& now = info[num];
	int start = now.r;
	int dis = now.s;
	if(dis == 0){
		return;
	}
	
	if(up && (start - dis) > 0){
		start = start - dis;
	}
	else if(!up && (start + dis) <= R){
		start = start + dis;
	}
	else{//한번은 턴을 하는 경우
		if(up){
			dis -= (start-1);
			start = 1;
			up = false;
		}
		else{
			dis -= (R-start);
			start =R;
			up = true;
		}
		
		while(dis >= R){
			if(up){
				dis -= (start-1);
				start = 1;
				up = false;
			}
			else{
				dis -= (R-start);
				start = R;
				up = true;
			}
		}
		if(up){
			now.d = 1;
			start = R-dis;
		}
		else{
			now.d = 2;
			start = 1+dis;
		}
	}
	
	now.r = start;
	return;
}

void moving_hor(int num,bool right){
	auto& now = info[num];
	int start = now.c;
	int dis = now.s;
	if(dis == 0){
		return;
	}
	
	if(!right && start - dis > 0){
		start = start - dis;
	}
	else if(right && start + dis <= C){
		start = start + dis;
	}
	else{//한번은 턴을 하는 경우
		if(!right){
			dis -= (start-1);
			start = 1;
			right = true;
		}
		else{
			dis -= (C-start);
			start = C;
			right = false;
		}
		
		while(dis >= C){
			if(!right){
				dis -= (start-1);
				start = 1;
				right = true;
			}
			else{
				dis -= (C-start);
				start = C;
				right = false;
			}
		}
		if(right){
			now.d = 3;
			start = 1+dis;
		}
		else{
			now.d = 4;
			start = C-dis;
		}
	}
	
	now.c = start;
	return;
}