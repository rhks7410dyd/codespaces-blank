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

int map[100][100];
bool check[100][100];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,maxval=0;

/*
void printmap(){
    cout << endl;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }   
    cout << endl;
}

void printcheck(){
    cout << endl;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << check[i][j] << ' ';
        }
        cout << endl;
    }   
    cout << endl;    
}
*/

void clearcheck(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            check[i][j] = false;
        }
    }       
}

void BFS(int sx,int sy,int dep)
{
    queue<pair<int,int>> q;
    int tx,ty,x,y;
    q.push(make_pair(sy,sx));
    check[sy][sx] = true;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < N && ty >= 0 && ty < N && !check[ty][tx] && map[ty][tx] > dep){
                check[ty][tx] = true;
                //cout << "x " << x << " y " << y << " tx " << tx << " ty " <<ty<< endl;
                q.push(make_pair(ty,tx));
            }
        }
    }
    //cout << c << endl;
}

int main()
{
    cin >> N;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }

    //printmap();
    int tval;
    for(int d = 1 ; d <= 100 ; d++){
        tval = 0;
        cout << "depth " << d << endl;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(d < map[i][j] && !check[i][j]){
                    tval++;
                    cout << "x " << j << " y " << i<<endl;
                    BFS(j,i,d);
                }
            }
        }
        cout << "safe zone "<<tval << endl;
        maxval = max(maxval,tval);
        clearcheck();
    }
    
    cout << maxval << endl;
    return 0;
}

