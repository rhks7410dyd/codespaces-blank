#include <iostream>
#include <pair>

using namespace std;

pair<int,int> info[50];
int c[50];
int rank[50];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base:sync_with_stdio(false);
	
	int N;
	cin >> N;
	int a,b;
	for(int i = 0 ; i < N ; i++){
		cin >> a >> b;
		info[i] = {a,b};
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(info[i].first > info[j].first && info[i].second > info[j].second){
				c[i]++;
			}
		}
	}
		
	int temp_c = 0;//현재 자기보다 덩치가 작은 사람이 몇명인가?
	int temp_r = N;//현재 등수
	int temp_num = 0;//동순위인 사람 수
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			
		}
	}
}