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
    int y,x;
};

//vector < vector <int> > v(10,vector <int>(10,0));
vector < vector < vector < pos > > > switchinfo(101,vector < vector < pos > >(101,vector<pos>(1,{0,0})));
int N , M , light_up_room = 0 ;
bool lightup[101][101];
bool link[101][101];
bool visit[101][101];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void input(){
    int x,y,a,b;
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        cin >> x >> y >> a >> b;
        switchinfo[y][x].push_back({b,a});
    }
}

bool adjacent(int y,int x){
    int nx,ny;
    for(int i = 0 ; i < 4 ; i++){
        ny = y + dir[i][0];
        nx = x + dir[i][1];
        if(nx < 1 || nx > N || ny < 1 || ny > N)    continue;
        if(link[ny][nx])    return true;
    }
    return false;
}

void BFS(){
    int ty,tx,nx,ny,fx,fy;
    
    queue<pos> q;
    
    q.push({1,1});
    lightup[1][1] = true;
    link[1][1] = true;
    light_up_room++;
    
    while(!q.empty()){
        ty = q.front().y;
        tx = q.front().x;
        q.pop();
        for(int i = 1 ; i < switchinfo[ty][tx].size() ; i++){
            ny = switchinfo[ty][tx][i].y;
            nx = switchinfo[ty][tx][i].x;
            if(link[ny][nx])    continue;
            light_up_room++;
            lightup[ny][nx] = true;
            if(adjacent(ny,nx)){ 
                link[ny][nx] = true;
                visit[ny][nx] = true;
                q.push({ny,nx});
                for(int j = 0 ; j < 4 ; j++){
                    fy = ny + dir[i][0];
                    fx = nx + dir[i][1];
                    if(fy < 1 || fy > N || fx < 1 || fx > N)    continue;
                    if(!link[fy][fx] && lightup[fy][fx] && !visit[fy][fx]){
                        visit[fy][fx] = true;
                        link[fy][fx] = true;
                        q.push({fy,fx});
                    }
                }
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    input();
    
    BFS();
    
    cout << light_up_room;
    return 0;
}

