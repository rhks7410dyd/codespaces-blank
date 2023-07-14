//방향을 숫자로 바꿔서 넣는게 간단할 듯
//뭔가 동작이 안됨;
#include <iostream>
#include <vector>

using namespace std;

struct info{
	int c,r,dir;
};
struct com{
	int mach_num;
	int times;
	char command;
};

int a,b,n,m,crashed_mach_num;
int map[101][101];
int Dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

vector<info> v;
vector<com> com_lis;

char move_machine(int c_num);
void print_map();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&a,&b);
	scanf("%d %d",&n,&m);
	
	int p,q,dir;
	char d;
	v.push_back({0,0,0});
	for(int i = 1 ; i <= n ; i++){
		scanf("%d %d %c",&p,&q,&d);
		switch(d){
			case 'N':
				dir = 0;
				break;
			case 'E':
				dir = 1;
				break;
			case 'S':
				dir = 2;
				break;
			case 'W':
				dir = 3;
				break;
		}
		v.push_back({p,q,dir});
		map[q][p] = i;
	}
	
	for(int i = 0 ; i < m ; i++){
		scanf("%d %c %d",&p,&d,&q);
		com_lis.push_back({p,q,d});
	}
	
	for(int i = 0 ; i < m ; i++){
		auto& now = com_lis[i];
		//cout << "i : " << i << '\n';
		//print_map();
		char is_crash = move_machine(i);
		if(is_crash > 0){
			if(is_crash == 1){
				printf("Robot %d crashes into the wall\n",now.mach_num);
			}
			else{
				printf("Robot %d crashes into robot %d\n",now.mach_num,crashed_mach_num);
			}
			return 0;
		}
	}
	
	printf("OK\n");
	return 0;
}

char move_machine(int c_num){
	auto& now = com_lis[c_num];
	auto& mach = v[now.mach_num];
	if(now.command == 'F'){
		map[mach.r][mach.c] = 0;
		for(int i = 0 ; i < now.times ; i++){
			mach.r += Dir[mach.dir][0];
			mach.c += Dir[mach.dir][1];
			if(mach.r <= 0 || mach.r > b || mach.c <= 0 || mach.c > a)	return 1;
			if(map[mach.r][mach.c] != 0){
				crashed_mach_num = map[mach.r][mach.c];
				return 2;
			}
		}
		map[mach.r][mach.c] = now.mach_num;
	}
	else{
		int delta;
		now.times %= 4;
		if(now.command == 'L'){
			delta = +3;
		}
		else{
			delta = +1;
		}
		mach.dir = (mach.dir + delta*now.times)%4;
	}
	return 0;
}

void print_map(){
	for(int i = 1 ; i <= b ; i++){
		for(int j = 1 ; j <= a ; j++){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}