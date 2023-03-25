#include <iostream>
#include <cstring>

using namespace std;

bool poly[200][200];
int is_there_square_on_row[200];//행에서 가장 왼쪽 인덱스에 위치한 정사각형의 위치 저장

int recursive(int n);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		memset(is_there_square_on_row,-1,sizeof(is_there_square_on_row));
		memset(poly,0,sizeof(poly));

		int N;
		cin >> N;
		
		poly[100][100] = true;
		int ans = recursive(N);
		
		cout << ans << '\n';
	}
	
	return 0;
}

int recursive(int n){
	if(!n)	return 1;
	
	
}