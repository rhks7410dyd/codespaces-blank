#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long total[12];
int best_val[12];
int N,K,minus_val=11;
vector<int> info[12];

int Solve(){


    for(int i = 1 ; i <= 11 ; i++){
        if(info[i].empty()) continue;

        int num_p = info[i].size();
        if(total[i] < K){
            best_val[i] = 1;
            continue;
        }

        sort(info[i].begin(),info[i].end());
        int tmp = K;
        for(int j = 0 ; j < num_p ; j++){
            if(tmp + info[i][j]+1 > 0){
                tmp += info[i][j]-1;
            }
            else{
                best_val[i] = -info[i][j] - tmp;
            }
        }
    }

    int ans = 0;
    for(int i = 1 ; i <= 11 ; i++){
        ans += best_val[i];
    }
    return ans;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    int p,w,total_val=0;
    for(int i = 0 ; i < N ; i++){
        cin >> p >> w;
        total[p] += w-1;
        info[p].push_back({-w});
    }
    
    Solve();

    return 0;
}