//3^7 = 2187
#include <iostream>

using namespace std;

int paper[130][130];
int ans[2];
int N;

void recursive(int r_s,int c_s,int l);
bool same_color(int r_s,int c_s,int l);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	int check = 0;
	bool one_tile = true;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> paper[i][j];
			if(!i&&!j)	check = paper[i][j];
			if(check != paper[i][j])	one_tile = false;
		}
	}
	
	if(one_tile){
		ans[check]++;
	}
	else{
		recursive(0,0,N);
	}
	
	for(int i = 0 ; i< 2; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}

void recursive(int c_s,int r_s,int l){//column_start,row_start,length_of_square
	//cout << "c_s " << c_s << " r_s " << r_s << " L " << l << '\n';
	if(l == 1){
		ans[paper[c_s][r_s]]++;
		return;
	}
	
	int n_l = l/2;
	
	for(int i = 0 ; i < 2; i++){
		for(int j = 0 ; j < 2 ; j++){
			int n_r = r_s+i*n_l,n_c=c_s+j*n_l;
			bool now_section = same_color(n_c, n_r, n_l);
			if(now_section){
				ans[paper[n_c][n_r]]++;
			}
			else{
				recursive(n_c,n_r,n_l);
			}
		}
	}
	return;
}

bool same_color(int c_s,int r_s,int l){
	for(int i = 0 ; i < l ; i++){
		for(int j = 0 ; j < l ; j++){
			if(paper[c_s][r_s] != paper[c_s+i][r_s+j])	return false;
		}
	}
	return true;
}