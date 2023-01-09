#include <iostream>

using namespace std;

int N,pattern = -1,rec_c=3;
char ln_in_3[4][6] = {"","*","* *","*****"};

void print_star(int ln,int blank_count){
	if(ln <= 3){
		printf("%s",ln_in_3[ln]);
		return;
	}
	
	if(pattern <= 0){
		pattern = 2*ln - 3;
		rec_c *= 2;
		if()
	}
	
	print_star()
	
	for(int i = 0 ; i < blank_count ; i++){
		printf(" ");
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 0 ; j < N - i ; j++){
			printf(" ");
		}
		
		print_star(i,pattern);
		printf("\n");
	}
}