/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int x,y,z;
};

int map[100][100][100];//순서대로 x,y,z
int N,M,H;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<pos> q;

bool possiblepos(int x,int y,int z){
    if(x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H)   return true;
    return false;
}

void BFS(){
    int x,y,z,tx,ty,tz;
    pos tval;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        z = q.front().z;
        q.pop();
        for(int i = 0 ; i < 6 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            tz = z + dz[i];
            if(possiblepos(tx,ty,tz) && map[ty][tx][tz] != -1){
                if(!map[ty][tx][tz]){
                    map[ty][tx][tz] = map[y][x][z]+1;
                    tval = {tx,ty,tz};
                    q.push(tval);
                }
            }
        }
    }
}

int main()
{
    
    cin >> M >> N >> H;
    pos tval;
    for(int k = 0 ; k < H ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                cin >> map[i][j][k];
                if(map[i][j][k] == 1){
                    tval = {j,i,k};
                    q.push(tval);
                }
            }
        }
    }
    
    BFS();
    
    int minday = -1;
    for(int k = 0 ; k < H ; k++){   
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < M ; j++){
                if(map[i][j][k] > minday){
                    minday = map[i][j][k];
                }
                if(map[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << minday-1;
    return 0;
}
