#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
int order[101];
int multiTap[101] = { 0, };

int main() 
{
    int count = 0;
    cin >> N >> K;
    for (int i = 0; i < K; i++) 
        cin >> order[i];

    for (int i = 0; i < K; i++)
    {
        bool flag = false;
        //1) 이미 꽂혀 있다면 pass
        for (int j = 0; j < N; j++)
        {
            if (multiTap[j] == order[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        //2)빈칸이 있으면 꼽아
        for (int j = 0; j < N; j++)
        {
            if (multiTap[j] == 0)
            {
                multiTap[j] = order[i];
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;


        //3) 빈칸 필요
        int last_need = -1; // 가장 늦게 다가올 차례
        int index = -1; // 뺄 멀티탭 자리
        for (int j = 0; j < N; j++)
        {
            int tmp = 0;
            for (int t = i+1;t < K; t++)
            {
                if (order[t] == multiTap[j])
                {
                    break;
                }
                tmp++;
            }
            if (tmp > last_need)
            {
                last_need = tmp;
                index = j;
            }
        }

        multiTap[index] = order[i];
        count++;

    }
    cout << count<< endl;
}