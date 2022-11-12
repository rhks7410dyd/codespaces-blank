/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int map[100][100];
int n,m;

void BFS(){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int x,y,ty,tx;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] == 1){
                map[tx][ty] = max(map[tx][ty],map[x][y]+1);
                q.push(make_pair(tx,ty));
            }
        }
    }
    cout << map[n-1][m-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j;
    string tstring;
    cin >> n >> m;
    for(i = 0 ; i < n ; i++){
        cin >> tstring;
        for(j = 0 ; j < m ; j++){
            map[i][j] = tstring[j] - '0';
        }
    }
    BFS();
    
    return 0;
}