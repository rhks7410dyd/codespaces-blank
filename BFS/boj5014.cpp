/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>

using namespace std;
// bool 배열을 이용해서 방문여부를 확인 안해서 틀리는 건지 확인해볼것!
long long shortpath[1000010];
int F,S,G,U,D;

void BFS(){
    int nf;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        nf = q.front();
        if(nf == G) break;
        q.pop();
        if(nf + U <= F && !shortpath[nf+U]){
            shortpath[nf+U] = shortpath[nf]+1;
            q.push(nf+U);
        }
        if(nf - D > 0 && !shortpath[nf-D]){
            shortpath[nf-D] = shortpath[nf]+1;
            q.push(nf-D);
        }
    }
    if(shortpath[G])    cout << shortpath[G];
    else    cout << "use the stairs";
}

int main()
{
    cin >> F >> S >> G >> U >> D;
    BFS();
    return 0;
}