/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={-2,2,-2,2,1,-1,1,-1};

void BFS()
{
    int n,sx,sy,ex,ey,tx,ty,x,y;//start / end / temporary / now
    cin >> n >> sx >> sy >> ex >> ey;
    int map[n][n];
    bool check[n][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            map[i][j] = 0;
            check[i][j] = false;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    check[sx][sy] = true;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x==ex && y == ey)    break;
        for(int i = 0 ; i < 8 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < n && !check[tx][ty]){
                check[tx][ty] = true;
                //cout << "x " << x << " y " << y << " tx " << tx << " ty " <<ty<<" map[x][y] " <<map[x][y]<<endl;
                map[tx][ty] = map[x][y] + 1;
                q.push(make_pair(tx,ty));
            }
        }
    }
    cout << map[ex][ey] << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        BFS();
    }
    return 0;
}
