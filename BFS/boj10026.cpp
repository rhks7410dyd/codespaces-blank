#include <iostream>
#include <queue>

using namespace std;

bool check[100][100];
char picture[100][100];
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool samecolor(bool nor,char a,char b){
    if(nor){
        if(a == b){
            return true;
        }
    }
    else{
        if(a == b || abs(a-b) == 11){
            return true;
        }
    }
    return false;
}

void BFS(int sy,int sx,bool nor){
    int tx,ty,x,y;
    queue<pair<int,int>> q;
    q.push(make_pair(sy,sx));
    check[sy][sx] = true;
    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < N && ty >= 0 && ty < N && samecolor(nor,picture[ty][tx],picture[y][x]) && !check[ty][tx]){
                q.push(make_pair(ty,tx));
                check[ty][tx] = true;
            }
        }
    }
}

int main()
{
    cin >> N;
    string tstring;
    for(int i = 0 ; i < N ; i++){
        cin >> tstring;
        for(int j = 0 ; j < N ; j++){
            picture[i][j] = tstring[j];
        }
    }

    /*
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << picture[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */
    int norcount = 0,blicount = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!check[i][j]){
                norcount++;
                BFS(i,j,true);
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            check[i][j] = false;
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!check[i][j]){
                blicount++;
                BFS(i,j,false);
            }
        }
    }
    
    cout << norcount << ' ' << blicount << endl;
    return 0;
}