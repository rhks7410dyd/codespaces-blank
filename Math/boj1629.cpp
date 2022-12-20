/*
(int)(log_2(C))의 값이 num이라하자.
remainder_of_power[1] = A%C 로 설정
remainder_of_power[2] = remainder_of_power[1]^2 %c
이런식으로 저장을 한다면 이진탐색을 메모리를 아끼면서 사용할 수 있음
반복문을 사용해서 만드는 것도 생각해볼만함.

시간초과가 떳음.
exponent == log_2(B) 임
즉 B값에 따라 계산 횟수가 달라짐.
B 값이 최대이더라도 계산횟수가 31회 이내가 되야된다고 생각했는데, 그게 아닌가봄
*/
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    long long A,B,C;
    long long remainder_of_power[32];
	
    cin >> A >> B >> C;
    
    remainder_of_power[0] = A%C;
    
    int temp = 1;
    int exponent = -1;
    
    while(temp <= B){
        temp *= 2;
        exponent++;
    }
	
    for(int i = 1 ; i <= exponent ; i++){
        remainder_of_power[i] = (remainder_of_power[i-1]*remainder_of_power[i-1])%C;
    }
    	
    long long result = 1;
    
    for(int i = 0 ; i <= exponent ; i++){
        if(!(B%2)){
            result *= remainder_of_power[i];
            result %= C;
        }
        B /= 2;
    }
    
    cout << result << endl;
    
    return 0;
}

