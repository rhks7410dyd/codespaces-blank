/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
여러개의 q를 돌리면 메모리 초과가 나올 가능성이 높음. 각각을 돌리고 이후 비교하는 형태가 이상적임
log( 1002001 ) × 1001 × 1001 × 10 + 1001 × 1001 × 10 × 10 = 160,328,859
n^2으로 비교를 극한으로 간단하게 한다면 가능할듯
왠지 모르겠는데 입력이 안됨! 어디서 놓친건지 다시 한번 확인해보고 모르겠으면 테스트로
cout 다 돌려봐야할듯
*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;

struct pos{
    int y,x;
};

int pS[10];
int presult[10];
int N,M,P;
int map[1001][1001] = {};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pos> q[10];

int main()
{
    int i,j,k,t;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> P;
    for(i = 1 ; i <= P ; i++){
        cin >> pS[i];
    }
    
    char inp;
    
    for(i = 1 ; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            cin >> inp;
            if(inp > '0' && inp <= '9'){
                q[inp-'0'].push({i,j});
                map[i][j] = inp - '0';
                presult[inp - '0']++;
                
            }
            else if(inp == '#'){
                map[i][j] = -1;
            }
        }
    }
    // input seccion end(clear)
    
    /*
    for(i = 1; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */
    
    int tx,ty,nx,ny,s;
    int clear = 0;
    while(clear < P){//S를 까먹고 고려를 안함!
        clear = 0;
        for(i = 1 ; i <= P ; i++){
            //cout << "P " << i << "   S " << p[i].S << endl;
            if(q[i].empty()){
                clear++;
                continue;
            }
            for(int c = 0 ; c < pS[i] ; c++){
                int qsize = q[i].size();
                for(j = 0 ; j < qsize ; j++){
                    ty = q[i].front().y;
                    tx = q[i].front().x;
                    q[i].pop();
                    //cout << "{ tx , ty } { "<< tx << " , " << ty << '}'<<endl;
                    for(k = 0 ; k < 4 ; k++){
                        ny = ty + dir[k][0];
                        nx = tx + dir[k][1];
                        if(ny <= 0 || nx <= 0 || ny > N || nx > M)  continue;
                        if(map[ny][nx] == 0){//아직 방문한적이 없으며 벽이 아닌 곳
                            //cout << "{ nx , ny } { "<< nx << " , " << ny << '}'<<endl;
                            map[ny][nx] = i;
                            presult[i]++;
                            q[i].push({ny,nx});
                        }
                    }
                }
            }
        }
    }
    
    //BFS session end
    
    /*
    for(i = 1; i <= N ; i++){
        for(j = 1 ; j <= M ; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */
    
    for(i = 1 ; i <= P ; i++){
        cout << presult[i] << ' ';
    }
    
    return 0;
}
