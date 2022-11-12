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

char map[1001][1001];
long long shortpath[2][1001][1001]; // [0]... -> 불 , [1]... -> 지훈이
int R,C;
queue<pair<int,int>> fire;
queue<pair<int,int>> man;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool inthemap(int x,int y){
    return (x >= 0 && x < R && y >= 0 && y < C);
}

void fireBFS(){
    int x,y,tx,ty;
    while(!fire.empty()){
        x = fire.front().first;
        y = fire.front().second;
        fire.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(inthemap(tx,ty) && map[ty][tx] != '#' && !shortpath[0][ty][tx]){
                fire.push(make_pair(tx,ty));
                shortpath[0][ty][tx] = shortpath[0][y][x]+1;
            }
        }
    }
}

void jihoonBFS(){
    int x,y,tx,ty;
    while(!man.empty()){
        x = man.front().first;
        y = man.front().second;
        man.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(inthemap(tx,ty) && map[ty][tx] == '.' && (shortpath[0][ty][tx] > shortpath[1][y][x]+1 || !shortpath[0][ty][tx]) && !shortpath[1][ty][tx]){
                if(shortpath[1][ty][tx])    continue;
                man.push(make_pair(tx,ty));
                shortpath[1][ty][tx] = shortpath[1][y][x]+1;
            }
        }
    }
}

void print(){
    for(int k = 0 ; k < 2 ; k++){
        for(int i = 0 ; i < C ; i++){
            for(int j = 0 ; j < R ; j++){
                cout << shortpath[k][i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    cin >> R >> C;
    string tstring;
    for(int i = 0 ; i < C ; i++){
        cin >> tstring;
        for(int j = 0 ; j < R ; j++){
            map[i][j] = tstring[j];
            if(map[i][j] == 'J'){
                man.push(make_pair(j,i));
                shortpath[1][i][j] = 1;
            }
            else if(map[i][j] == 'F'){
                fire.push(make_pair(j,i));
                shortpath[0][i][j] = 1;
            }
        }
    }
    
    //print();
    
    fireBFS();
    jihoonBFS();
    long long fastway = 9223372036854775807;
    for(int i = 0 ; i < C ; i++){
        if(shortpath[1][i][0])      fastway = min(fastway,shortpath[1][i][0]);
        if(shortpath[1][i][R-1])    fastway = min(fastway,shortpath[1][i][R-1]);
    }
    for(int i = 1 ; i < R-1 ; i++){
        if(shortpath[1][0][i])      fastway = min(fastway,shortpath[1][0][i]);
        if(shortpath[1][C-1][i])    fastway = min(fastway,shortpath[1][C-1][i]);
    }

    print();

    if(fastway != 9223372036854775807) cout << fastway;
    else    cout << "IMPOSSIBLE";

    return 0;
}

