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

int map[25][25];
bool check[25][25];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,maxv = 1;
priority_queue<int> val;

void BFS(int sx,int sy)
{
    queue<pair<int,int>> q;
    int tx,ty,x,y,c = 0;
    q.push(make_pair(sx,sy));
    check[sx][sy] = true;
    while(!q.empty()){
        c++;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < n && !check[tx][ty] && map[tx][ty]){
                check[tx][ty] = true;
                //cout << "x " << x << " y " << y << " tx " << tx << " ty " <<ty<<endl;
                q.push(make_pair(tx,ty));
            }
        }
    }
    val.push(-c);
}

int main()
{
    int count = 0;
    string tstring;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tstring;
        //cout << tstring<<endl;
        for(int j = 0 ; j < n ; j++){
            map[i][j] = tstring[j] - '0';
        }
    }
    /*
    for(int i = 0 ; i < n ; i++){
        cout << endl;
        for(int j = 0 ; j < n ; j++){
            cout << map[i][j] <<' ';
        }
    }
    cout << endl;
    */
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] && !check[i][j]){
                count ++;
                BFS(i,j);
            }
        }
    }
    cout << count << endl;
    while(!val.empty()){
        cout << -val.top() << endl;
        val.pop();
    }
    return 0;
}