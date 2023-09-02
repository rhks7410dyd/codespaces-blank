#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

pair<int,int> A[4];
pair<int,int> B[4];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i = 0 ; i < 4 ; i++){
        cin >> A[i].first >> A[i].second;
    }
    
    for(int i = 0 ; i < 4 ; i++){
        cin >> B[i].first >> B[i].second;
    }


    return 0;
}
