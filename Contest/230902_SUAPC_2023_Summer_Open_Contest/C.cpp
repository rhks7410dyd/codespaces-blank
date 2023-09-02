#include <iostream>
#define endl '\n'
#define mod 1000000007
using namespace std;

/*

*/

int Q;

long long get_ans(int h,int w);
void Solve();

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio;

    Solve();

    return 0;
}

void Solve(){
    cin >> Q;

    while(Q--){
        int h,w;
        cin >> h >> w;
        long long ans = get_ans(h,w);
        cout << ans << endl;
    }
}

long long get_ans(int h,int w){
    
}