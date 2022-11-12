/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 100001

using namespace std;

int shrtpath[100001];
int history[100001];//pos,root

void printpath(int pos){
    if(history[pos] != -1){
        printpath(history[pos]);
    }
    cout << pos << ' ';
    return ;
}

int main()
{
    int n,k,i;
    cin >> n >> k;
    for(int i = 0 ; i < 100001 ; i++){
        shrtpath[i] = INF;
    }
    queue<int> q;
    shrtpath[n] = 0;
    history[n]=-1;
    q.push(n);
    while(!q.empty()){
        i = q.front();
        q.pop();
        if(i == k)  break;
        if(i <= 50000){
            if(!i){
                if(shrtpath[1] == INF){
                    shrtpath[1] = shrtpath[0] + 1;
                    history[1] = 0;
                    q.push(1);
                }
            }
            else{
                if(shrtpath[i + 1] == INF){
                    shrtpath[i + 1] = shrtpath[i] + 1;
                    history[i + 1] = i;
                    q.push(i + 1);
                }
                if(shrtpath[i - 1] == INF){
                    shrtpath[i - 1] = shrtpath[i] + 1;
                    history[i - 1] = i;
                    q.push(i - 1);
                }
                if(shrtpath[i * 2] == INF){
                    shrtpath[i * 2] = shrtpath[i] + 1;
                    history[i * 2] = i;
                    q.push(i * 2);
                }
            }
        }
        else{
            if(i == 100000){
                if(shrtpath[99999] == INF){
                    shrtpath[99999] = shrtpath[100000] + 1;
                    history[99999] = 100000;
                    q.push(99999);
                }                
            }
            else{
                if(shrtpath[i + 1] == INF){
                    shrtpath[i + 1] = shrtpath[i] + 1;
                    history[i + 1] = i;
                    q.push(i + 1);
                }
                if(shrtpath[i - 1] == INF){
                    shrtpath[i - 1] = shrtpath[i] + 1;
                    history[i - 1] = i;
                    q.push(i - 1);
                }                
            }
        }
    }
    
    cout << shrtpath[k] << endl;
    printpath(k);
    return 0;
}