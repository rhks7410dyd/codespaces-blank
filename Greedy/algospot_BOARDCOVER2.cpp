#include <iostream>

using namespace std;

int h,w,r,c;
bool map[10][10];
bool piece[10][10];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t;
	char temp;
	cin >> t;
	
	while(t--){
		cin >> h >> w >> r >> c;

		for(int i = 0 ; i < h ; i++){
			for(int j = 0 ; j < w ; j++){
				cin >> temp;
				if(temp == '#'){
					map[i][j] = false;
				}
				else{
					map[i][j] = true;
				}
			}
		}
		
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				cin >> temp;
				if(temp == '#'){
					piece[i][j] = true;
				}
				else{
					piece[i][j] = false;
				}
			}
		}
		
		//piece를 상대 좌표로 바꿔서 벡터 형태로 저장 -> 이 벡터를 이중 벡터로 묶은다음에
		//정렬 이후 유니크 함수를 이용해 중복 제거
		
		
	}

	
	
	return 0;
}