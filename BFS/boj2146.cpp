/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

한 대륙을 찾고, 이 대륙에 대하여 탐색 실행
그리고 소속한 대륙을 v[i].push_back으로 저장
저장된 위치끼리 모두 비교하여 최솟값을 구함
최악의 경우라도 50*50번 미만으로 진행함
*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
vector<vector<pair<int,int>>> islandinfo;
int map[100][100];
bool visit[100][100];
int N,num;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


void BFS(){
/*
bfs 내에서 해야할 일
1. 너비우선탐색을 상하좌우로 탐색할 것
2. 탐색 이후 q에 푸쉬
3. q에서 뽑아온 위치는 지금 islandinfo 위치에 push_back으로 값 저장
4. visit은 true로 바꾸기
*/
    int tx,ty,nx,ny;
    while(!q.empty()){
        ty = q.front().first;
        tx = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            ny = ty + dir[i][0];
            nx = tx + dir[i][1];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N)  continue;
            if(!visit[ny][nx] && map[ny][nx]){
                visit[ny][nx] = true;
                islandinfo[num].push_back({ny,nx});
                q.push({ny,nx});
            }
        }
    }
}

int main()
{
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> map[i][j];
        }
    }
    
    num = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] && !visit[i][j]){//육지이고 아직 탐색이 안된 경우 == 새로운 섬
                vector<pair<int,int>> newland;
                islandinfo.push_back(newland);
                islandinfo[num].push_back({i,j});
                q.push({i,j});
                visit[i][j] = true;
                BFS();
                num++;
            }
        }
    }
    
    int tval,min = 999999999;
    //bfs이후로 islandinfo를 이용하여 하나하나 비교해서 최솟값 찾기
    for(int i = 0 ; i < islandinfo.size() ; i++){
        for(int j = i + 1 ; j < islandinfo.size() ; j++){
            for(int k = 0 ; k < islandinfo[i].size() ; k++){
                for(int l = 0 ; l < islandinfo[j].size() ; l++){
                    tval = abs(islandinfo[i][k].first - islandinfo[j][l].first) + abs(islandinfo[i][k].second - islandinfo[j][l].second) - 1;
                    if(tval < min){
                        min = tval;
                        /*cout << "i " << i << " j " << j << endl <<
                        "first pos " << islandinfo[i][k].first << ',' << islandinfo[i][k].second << " second pos " << islandinfo[j][l].first << ',' << islandinfo[j][l].second << endl;
                        cout << min << endl;*/
                    }
                }
            }
        }
    }
    
    cout << min;
    return 0;
}

