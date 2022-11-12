/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
continue를 이용한 방식으로 바꿔보기. 또 50 몇프로에서 뽀록 나는데 이거에 대한 예외 처리가 뭐가 안된건지 모르겠음.
답이 있는 글을 찾아보더라도 나랑 논리적으로 차이가 없는거 같은데 왜 이럴까?...
*******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T,h,w;
char map[1000][1000]; 
struct pos{
    short y,x;
};

pos start;
vector<pos> fire;
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};
bool check[1000][1000];
bool fcheck[1000][1000];

/*bool inthemap(int y,int x){
    return (x >= 0 && x < w && y >= 0 && y < h);
}*/

void printmap(){
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            cout << map[i][j] << ' ';
        }
        cout <<endl;
    }
}

void BFS(){
    //printmap();
    
    queue<pos> flame;
    queue<pos> person;
    pos now,next;
    for(int i = 0 ; i < fire.size() ; i++){
        auto tt = fire[i];
        flame.push({tt.y,tt.x});
    }
    person.push(start);
    int fsize,tsize,shortesttime = 0;
    int nexty,nextx,nx,ny;
    while(!person.empty()){
        //cout<< "ln53" << endl;
        fsize = flame.size();
        for(int i = 0 ; i < fsize ; i++){
            nx = flame.front().x;
            ny = flame.front().y;
            flame.pop();
            //cout << "FNOW x " << now.x << " y "<<now.y<<endl;
            for(int j = 0 ; j < 4 ; j++){
                nexty = ny + diry[j];
                nextx = nx + dirx[j];
                //cout << "FNEXT x " << nextx << " y "<<nexty<<endl;
                if(nexty < 0 || nexty >= h || nextx < 0 || nextx >= w)  continue;
                if(map[nexty][nextx] != '#' && !fcheck[nexty][nextx]){
                    fcheck[nexty][nextx] = true;
                    //cout << "FNEXT x " << next.x << " y "<<next.y<<endl;
                    map[nexty][nextx] = '*';
                    flame.push({nexty,nextx});}
            }
        }

        //printmap();

        tsize = person.size();
        for(int i = 0 ; i < tsize ; i++){
            nx = person.front().x;
            ny = person.front().y;
            person.pop();
            //cout << "pNOW x " << nx << " y "<<ny<<endl;
            for(int j = 0 ; j < 4 ; j++){
                nexty = ny + diry[j];
                nextx = nx + dirx[j];
                if(nextx < 0 || nextx > w-1 || nexty< 0 || nexty > h-1){
                    cout << shortesttime + 1<<endl;
                    return;
                }
                //cout << "PNEXT x " << nextx << " y "<<nexty<<endl;
                if(nexty < 0 || nexty >= h || nextx < 0 || nextx >= w)  continue;
                if(map[nexty][nextx] == '.' && !check[nexty][nextx]){
                    person.push({nexty,nextx});
                    check[nexty][nextx] = true;
                }
            }
        }
        shortesttime++;
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main(){
    string tstring;
    cin >> T;
    
    for(int t = 0 ; t < T ; t++){
        cin >> w >> h;
        /*cout << "w "<<w<< " h " << h << endl;
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                if(check[i][j]) cout << "T ";
                else    cout << "F ";
            }
            cout << endl;
        }*/
        
        for(int i = 0 ; i < h ; i++){
            cin >> tstring;
            for(int j = 0 ; j < w ; j++){
                map[i][j] = tstring[j];
                if(map[i][j] == '*'){
                    //cout << "fire pos   x " << j << " y " << i << endl;
                    fire.push_back({i,j});
                }
                if(map[i][j] == '@'){
                    //cout << "start pos   x " << j << " y " << i << endl;
                    start = {i,j};
                }
            }
        }
        //cout << "t " << t << endl;
        //printmap();
        BFS();
        //printmap();
        //cout << endl << endl;
        fire.clear();
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                check[i][j] = false;
                fcheck[i][j] = false;
            }
        }
    }
    return 0;
}