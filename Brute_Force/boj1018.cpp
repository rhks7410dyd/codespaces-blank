#include <iostream>

using namespace std;

string map[50];

int count_change(int a,int b);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		cin >>map[i];
	}
	
	int min = 987654321;
	for(int i = 0 ; i < n-7 ; i++){
		for(int j = 0 ; j < m-7 ; j++){
			int temp = count_change(i,j);
			if(temp < min)	min = temp;
		}
	}
	
	cout << min << endl;
}

int count_change(int a,int b){
	int c = 0;
	char first_c;
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			if(i == 0 && j == 0){
				first_c = map[a][b];
				continue;
			}
			
			if((i+j)%2 == 1){
				if(first_c == map[a+i][b+j])	c++;
			}
			else{
				if(first_c != map[a+i][b+j])	c++;
			}
		}
	}
	
	if(c > (64 - c)){
		c = 64 - c;
	}
	return c;
}