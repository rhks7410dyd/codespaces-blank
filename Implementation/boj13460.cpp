#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct step{
	int Rx,Ry,Bx,By,Count;
};

int n,m;

char map[11][11];
bool visit[11][11][11][11];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void Solve();
void BFS(int Rx,int Ry,int Bx,int By);
void move(int& x,int& y,int& count,int& d);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Solve();
	
	return 0;
}

void Solve(){
	cin >> n >> m;
	
	int Rx,Ry,Bx,By;
	
	string input;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j ++){
			cin >> map[i][j];
			if(map[i][j] == 'B'){
				Bx = i;
				By = j;	
			}
			else if(map[i][j] == 'R'){
				Rx = i;
				Ry = j;
			}
		}
	}
	
	BFS(Rx,Ry,Bx,By);
}

void BFS(int Rx,int Ry,int Bx,int By){
	queue<step> q;
	q.push({Rx,Ry,Bx,By,0});
	visit[Rx][Ry][Rx][Ry] = true;
	
	while(!q.empty()){
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().Count;
		q.pop();
		
		if(count >= 10)	break;
		
		for(int d = 0 ; d < 4 ; d++){
			int nrx = rx,nry = ry,nbx = bx,nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			move(nrx, nry, rc, d);
			move(nbx, nby, bc, d);

			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O')
			{
				cout << ncount <<'\n';
				return;
			}

			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) nrx -= dir[d][0], nry -= dir[d][1];
				else nbx -= dir[d][0], nby -= dir[d][1];
			}

			if (visit[nrx][nry][nbx][nby]) continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });
		}
	}
	cout << -1 << '\n';
}

void move(int& x,int& y,int& count,int& d){
	while (map[x + dir[d][0]][y + dir[d][1]] != '#' && map[x][y] != 'O'){
		x += dir[d][0];
		y += dir[d][1];
		count ++;
	}
}