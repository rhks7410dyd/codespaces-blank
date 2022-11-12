#include <iostream>
#include <queue>
using namespace std;

int k,times;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int arr[50][50];

void Solve(){
    int n,m;
    cin >> m >> n >>k;
    queue<pair<int,int>> q;
    int i,j,k,x,y,tx,ty,c = 0;
    bool check[m][n] = {false};
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            arr[i][j] = 0;
        }
    }
    for(i = 0 ; i < k ; i++){
        cin >> x >> y;
        arr[x][y] = 1;
    }
    cout << "input arr" << endl;
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    
    for(i = 0 ; i < m ; i++){
        for(j = 0 ; j < n ; j++){
            if(arr[i][j] == 1 && !check[i][j]){
                c++;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    cout << "ln34" << endl;
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    check[x][y] = true;
                    for(k = 0 ; k < 4 ; k++){
                        tx = x + dx[k];
                        ty = y + dy[k];
                        cout << "x : " << x << " y : " << y << " tx : " << tx << " ty : " << ty << endl;
                        if(tx >= 0 && tx < n && ty < m && ty >= 0){
                            if(arr[tx][ty] == 1 && !check[tx][ty]){
                                q.push(make_pair(tx,ty));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << c << endl;
}

int main()
{
    cin >> times;
    int i,j,x,y;
    for(i = 0 ; i < times ; i++){
        Solve();
    }
    return 0;
}

