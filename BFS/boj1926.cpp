/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[500][500];
int n,m,maxa = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void BFS(int sx,int sy){
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    int x,y,tx,ty,ta = 0;
    arr[sx][sy]++;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        ta++;
        cout << "x : " << x << " y : " << y << endl;
        for(int i = 0 ; i < 4 ; i++){
            tx = x + dx[i];
            ty = y + dy[i];
            if(tx >= 0 && tx < n && ty < m && ty >=0 && arr[tx][ty] == 1){
                q.push(make_pair(tx,ty));
                arr[tx][ty]++;
            }
        }
    }
    maxa = max(maxa,ta);
    cout << "sx : " << sx << " sy : " << sy << " ta : " << ta << endl;
}

int main()
{
    int i,j,count = 0;
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < n*m ; i++){
        cin >> arr[i/m][i%m];
    }
    
    for(int i = 0 ; i < n*m ; i++){
        if(arr[i/m][i%m] == 1){
            BFS(i/m,i%m);
            count++;
        }
    }
    
    cout << count << '\n' << maxa;
    return 0;
}