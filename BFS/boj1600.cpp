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
    short y,x,pk;
};

short K,H,W;
bool visit[200][200][31];
short shrtpath[200][200][31];
short map[200][200];
short dir[12][2] = {{2,1},{2,-1},{-2,1},{-2,-1},
{1,2},{1,-2},{-1,2},{-1,-2},
{1,0},{-1,0},{0,1},{0,-1}};

void BFS(){
    if(W == 1 && H == 1){
        cout<< 0;
        return;
    }
    int tx,ty,nx,ny,tk;
    queue<pos> q;
    q.push({0,0,K});
    visit[0][0][K] = true;
    while(!q.empty()){
        ty = q.front().y;
        tx = q.front().x;
        tk = q.front().pk;
        q.pop();
        //cout << "ty " << ty << " tx " << tx << " tk " << tk << endl;
        if(ty == H - 1 && tx == W - 1){
            cout << shrtpath[ty][tx][tk];
            return;
        }
        for(int i = 0 ; i < 12 ; i++){
            ny = ty + dir[i][0];
            nx = tx + dir[i][1];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W)  continue;
            if(map[ny][nx])   continue;
            //cout << "ny " << ny << " nx " << nx << " tk " << tk << endl;
            if(i < 8){//말처럼 뛰는 경우
                if(tk > 0 && !visit[ny][nx][tk-1]){
                    q.push({ny,nx,tk - 1});
                    visit[ny][nx][tk-1] = true;
                    shrtpath[ny][nx][tk-1] = shrtpath[ty][tx][tk] + 1;
                }
            }
            else{//상하좌우
                if(!visit[ny][nx][tk]){
                    q.push({ny,nx,tk});
                    visit[ny][nx][tk] = true;
                    shrtpath[ny][nx][tk] = shrtpath[ty][tx][tk] + 1;
                }
            }
        }
    }
    cout << -1;

    return;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> K >> W >> H;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> map[i][j];
        }
    }
    
    BFS();
    
    return 0;
}
