#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int n,m,r;
int item_info[101];
int map[101][101];

void print_map(){
	cout << endl;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> r;
	
	fill(&map[0][0],&map[100][101],INF);
	
	int t;
	for(int i = 1 ; i <= n ; i++){
		cin >> t;
		item_info[i] = t;
		map[i][i] = 0;
	}
	
	int a,b;
	for(int i = 1 ; i <=r ; i++){
		cin >> a >> b >> t;
		if(map[a][b] > t){
			map[a][b] = t;
			map[b][a] = t;
		}
	}
	/*
	for(int i = 1; i <= n ; i++){
		cout << item_info[i] << ' ';
	}
	cout << endl;
	
	print_map();
	*/
	
	for(int i = 1 ; i <= n ; i++){
		for(int n1 = 1 ; n1 <= n ; n1++){
			for(int n2 = 1 ; n2 <= n ; n2++){
				map[n1][n2] = min(map[n1][n2] , map[n1][i] + map[i][n2]);
			}
		}
	}
	
	//print_map();
	
	int max_item = 0;
	int t_item;
	for(int n1 = 1 ; n1 <= n ; n1++){
		t_item = 0;
		for(int n2 = 1 ; n2 <= n ; n2++){
			if(map[n1][n2] <= m)	t_item += item_info[n2];
		}
		max_item = max(t_item,max_item);
	}
	
	cout << max_item << '\n';
	
	return 0;
}