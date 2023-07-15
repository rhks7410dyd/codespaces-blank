#include <iostream>
#include <string>

using namespace std;

bool is_end_num(int n);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	long long num = 665;
	
	cin >> N;
	
	while(N != 0){
		num++;
		if(is_end_num(num)){
			N--;
		}
	}
	
	cout << num << endl;
}

bool is_end_num(int n){
	while(n>=666){
        if(n%10 == 6 && (n/10)%10 == 6 && (n/100)%10 == 6){
            return true;
        }
        n /= 10;
    }
	
	return false;
}