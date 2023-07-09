//방향을 숫자로 바꿔서 넣는게 간단할 듯
#include <iostream>
#include <vector>

using namespace std;

struct info{
	int r,c;
	char dir;
};
struct com{
	int mach_num;
	int times;
	char command;
}

int a,b,n,m,crashed_mach_num;
int map[101][101];
vector<info> v;
vector<com> com_lis;

char move_machine(int c_num);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d %d",&a,&b);
	scanf("%d %d",&n,&m);
	
	int p,q;
	char d;
	for(int i = 0 ; i < n ; i++){
		scanf("%d %d %c",&p,&q,&d);
		v.push_back({p,q,d});
	}
	
	for(int i = 0 ; i < m ; i++){
		scanf("%d %c %d",&p,&d,&q);
		com_lis.push_back({p,q,d});
	}
	
	for(int i = 0 ; i < m ; i++){
		auto& now = com_lis[i];
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
	
	return 0;
}

char move_machine(int c_num){
	auto& now = com_lis[c_num];
	if(now.command == 'F'){
		
	}
	else{
		now.times %= 4;
		for(int i = 0 ; i < now.times ; )
	}
}