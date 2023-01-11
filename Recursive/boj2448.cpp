#include <iostream>

using namespace std;

int N;
int b_c[3100];
char ln_in_3[4][6] = {"","*","* *","*****"};

void print_star(int ln,int blank_count,int p){
	if(ln <= 3){
		printf("%s",ln_in_3[ln]);
		return;
	}
	
	int t_p = p;
	while(t_p >= ln - p)	t_p /= 2;
	
	print_star(ln-p,b_c[ln-p],t_p);//여기서 0 부분을 채워주면됨!
	
	for(int i = 0 ; i < blank_count ; i++){
		printf(" ");
	}
	
	print_star(ln-p,b_c[ln-p],t_p);
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	int p=3;
	b_c[0] = 13;
	for(int i = 1 ; i <= N ; i++){
		if(2*p < i){
			p *= 2;
			b_c[i] = 2* p - 1;
		}
		else{
			b_c[i] = b_c[i-1] - 2;
		}
		
		//printf("%4d (%4d,%4d) : ",i,p,b_c[i]);
		for(int j = 0 ; j < N - i ; j++){
			printf(" ");
		}
		
		print_star(i,b_c[i],p);
		
		for(int j = 0 ; j < N - i ; j++){
			printf(" ");
		}
		
		printf("\n");
	}
}