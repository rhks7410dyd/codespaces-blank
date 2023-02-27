#include <iostream>

using namespace std;

int L_type[4][2][2] = {{{1,0},{1,1}},{{1,0},{0,1}},{{0,1},{1,1}},{{0,1},{-1,1}}};
int map[20][20];//-1은 검은색, 0은 블록이 없는 흰색, 1은 블록이 있는 흰색
int C,h,w;

bool is_in_arrange_and_blank(int now_w,int now_h);
int recursive_func();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> C;
	
	for(int i = 0 ; i < C ; i++){
		cin >> h >> w;
		char temp_c;
		int white_tile_num=0;
		for(int j = 0 ; j < h ; j++){
			for(int k = 0 ; k < w ; k++){
				cin >> temp_c;
				if(temp_c == '#'){
					map[j][k] = -1;
				}
				else{
					map[j][k] = 0;
					white_tile_num++;
				}
			}
		}
		
		int result;
		if(white_tile_num % 3 == 0){
			result = recursive_func();
		}
		else{
			result = 0;
		}
		
		cout << result << endl;
	}
	
}


bool is_in_arrange_and_blank(int now_w,int now_h){
	if(now_w >= w || now_w < 0 || now_h >= h || now_h < 0 || map[now_h][now_w] != 0)	return false;
	return true;
}

int recursive_func(){
	int first_h,first_w;
	int ret = 0;
	bool blank_is_exist = false;
	
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			if(map[i][j] == 0){
				blank_is_exist = true;
				first_h = i;
				first_w = j;
				break;
			}
		}
	}
	
	if(!blank_is_exist)	return 0;
	
	for(int i = 0 ; i < 4 ; i++){
		int next_w1 = first_w + L_type[i][0][0];
		int next_h1 = first_h + L_type[i][0][1];
		int next_w2 = first_w + L_type[i][1][0];
		int next_h2 = first_h + L_type[i][1][1];
		
		if(!is_in_arrange_and_blank(next_w1,next_h1) || !is_in_arrange_and_blank(next_w2, next_h2))	continue;
		
		map[first_h][first_w] = 1;
		map[next_h1][next_w1] = 1;
		map[next_h2][next_w2] = 1;
		ret += recursive_func();
		map[first_h][first_w] = 0;
		map[next_h1][next_w1] = 0;
		map[next_h2][next_w2] = 0;
	}
	
	return ret;
}
/*
3 
3 7 
#.....# 
#.....# 
##...## 
3 7 
#.....# 
#.....# 
##..### 
8 10 
########## 
#........# 
#........# 
#........# 
#........# 
#........# 
#........# 
########## 
*/