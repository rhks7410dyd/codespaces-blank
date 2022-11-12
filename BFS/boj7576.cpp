/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000];
int N,M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int,int>> q;

void BFS(){
    int x,y,tx,ty;
    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < M && ty < N && ty >=0 && map[ty][tx] != -1){
                if(!map[ty][tx]){
                    map[ty][tx] = map[y][x]+1;
                    q.push(make_pair(ty,tx));
                }
            }
        }
    }
}

int main()
{
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }
    
    BFS();
    
    int minday = -1;   
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(map[i][j] > minday){
                minday = map[i][j];
            }
            if(map[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }
    

    cout << minday-1;
    return 0;
}

