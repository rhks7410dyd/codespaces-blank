#include <iostream>
#include <vector>
using namespace std;

vector<int> hopestu;
vector<short> maketeam; 
vector<int> temparr;

int N;

int BFS(int nxt){//재귀함수로 만들기
/*
팀이 편성된 인원을 희망하면 -1 출력같은 걸로 안만들어진다고 리턴하기
*/
    if(maketeam[hopestu[nxt]])  return -1;
    int siz = temparr.size();
    //cout << "ln 26 " << nxt << endl;
    for(int i = 1 ; i <= siz ; i++){
        if(hopestu[nxt] == temparr[i]){
            return nxt;
        }
    }
    temparr.push_back(nxt);
    return BFS(hopestu[nxt]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,t,i,j,k,nxt,count;
    cin >> T;
    for(i = 0 ; i < T ; i++){
        //cout << i << endl;
        cin >> N;
        hopestu.assign(N+1,0);
        maketeam.assign(N+1,-1);
        
        count = 0;
        for(j = 1 ; j <= N ; j++){
            cin >> hopestu[j];
        }
                
        for(j = 1 ; j <= N ; j++){
            //cout << "ln56\n";
            if(!maketeam[j]){
                //cout << "ln58\n";
                t = BFS(j);
                //t == -1 이면 이미 팀이 있는 애랑 하고 싶어하는 것 -1이 아니면 팀을 이루는 한 명의 번호를 꽂아주는 것
                if(t != -1){//이렇게하면 되긴 하는데 문제가 이미 안되는 것을 검증한 이후에도 중복해서 검사하게 되는 것 같음
                 //이러한 문제를 해결하려면 bool이 아닌 정수형을 사용하여 상태를 세가지(팀을 이룸, 이룰 수 없음, 검사 안함)로 나눠야됨
                 //실제로 시간초과가 되서 바꿈
                    nxt = hopestu[t];
                    maketeam[t] = 1;
                    while(nxt != t){
                        maketeam[nxt] = 1;
                        nxt = hopestu[nxt];
                    }
                }
                else{
                    nxt = hopestu[j];
                    maketeam[j] = -1;
                    while(!maketeam[nxt]){
                        maketeam[nxt] = -1;
                        nxt = hopestu[nxt];
                    }
                }
            }
        }
        
        for(j = 1 ; j <= N ; j++){
            cout << maketeam[j] << ' ';
            if(maketeam[j] == -1) count++;
        }
        cout << endl;
        cout << count <<'\n';
        hopestu.clear();
        maketeam.clear();
    }

    return 0;
}