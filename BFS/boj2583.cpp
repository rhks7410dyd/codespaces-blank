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
int N,M,K;
priority_queue<int> val;

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

void BFS(int sx,int sy)
{
    queue<pair<int,int>> q;
    int tx,ty,x,y,c = 0;
    q.push(make_pair(sy,sx));
    check[sy][sx] = true;
    while(!q.empty()){
        c++;
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < N && ty >= 0 && ty < M && !check[ty][tx] && !map[ty][tx]){
                check[ty][tx] = true;
                //cout << "x " << x << " y " << y << " tx " << tx << " ty " <<ty<< endl;
                q.push(make_pair(ty,tx));
            }
        }
    }
    //cout << c << endl;
    val.push(-c);
}

int main()
{
    int count = 0;
    int x1,x2,y1,y2;
    cin >> M >> N >> K;
    for(int i = 0 ; i < K ; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1 ; j < y2 ; j++){
            for(int k = x1 ; k < x2 ; k++){
                map[j][k] = 1;//여기까지하면 입력부 완성
            }
        }
    }

    //printmap();

    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!map[i][j] && !check[i][j]){
                count ++;
                //cout << "x " << j << " y " << i << " count " << count << endl;
                BFS(j,i);
            }
        }
    }
    
    cout << count << endl;
    while(!val.empty()){
        cout << -val.top() << ' ';
        val.pop();
    }
    return 0;
}

