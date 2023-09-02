#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,tot_time=0;
int problem_count[5];
vector<int> problem_info[5];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio;

    cin >> N;
    for(int i = 0 ; i < 5 ; i++){
        cin >> problem_count[i];
    }

    int k,j;
    for(int i = 0 ; i < N ; i++){
        cin >> k >> j;
        problem_info[k-1].push_back(j);
    }

    for(int i = 0 ; i < 5 ; i++){
        sort(problem_info[i].begin(),problem_info[i].end());

        tot_time += problem_info[i][0];
        for(int j = 1 ; j < problem_count[i] ; j++){
            tot_time += problem_info[i][j];
            tot_time += problem_info[i][j] - problem_info[i][j-1];
        }
        tot_time+=60;
    }

    cout << tot_time-60 << '\n';
    return 0;    
}