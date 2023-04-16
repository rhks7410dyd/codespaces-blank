//이거 외않댐?
#include <iostream>

using namespace std;

int R,C;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[21][21];
bool using_alphabet[30]={0,};
int recur(int r,int c);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> R >> C;
	for(int i = 0 ; i < R ; i++){
		for(int j = 0 ; j < C ; j++){
			cin >> map[i][j];
		}
	}
	
	using_alphabet[map[0][0]-'a'] = true;
	int cnt = recur(0,0)+1;
	
	cout << cnt << '\n';
	
	return 0;
}

int recur(int r,int c){
	int ret = 0;
	for(int i = 0 ; i < 4 ; i++){
		int n_r = r + dir[i][0];
		int n_c = c + dir[i][1];
		
		if(n_r < 0 || n_c < 0 || n_r >= R || n_c >= C)	continue;
		char alp = map[n_r][n_c];
		if(using_alphabet[alp-'a'])	continue;
		
		using_alphabet[alp-'a'] = true;
		int temp = recur(n_r,n_c)+1;
		using_alphabet[alp-'a'] = false;
		
		if(temp > ret)	ret = temp;
	}
	
	return ret;
}