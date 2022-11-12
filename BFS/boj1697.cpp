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

bool check[100010];
int map[100010];
int n,m;

//bool함수를 넣어도 안됨. 우선순위 큐를 이용해서 무조건 시간이 적게 걸리는데부터 찾게 하는게 좋은 방법임.
void BFS(){
    queue<int> q;
    q.push(n);
    int x,tx;
    check[n] = true;
    while(!q.empty()){
        x = q.front();
        q.pop();
        tx = 2 * x;
        if(tx <= 100000 && !check[tx]){
            map[tx] = max(map[tx],map[x]+1);
            q.push(tx);
            check[tx] = true;
        }
        tx = x - 1;
        if(tx <= 100000 && tx >= 0 && !check[tx]){
            map[tx] = max(map[tx],map[x]+1);
            q.push(tx);
            check[tx] = true;        
        }
        tx = 1 + x;
        if(tx <= 100000 && !check[tx]){
            map[tx] = max(map[tx],map[x]+1);
            q.push(tx);
            check[tx] = true;
        }
    }
    cout << map[m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j;
    cin >> n >> m;
    BFS();
    
    return 0;
}
