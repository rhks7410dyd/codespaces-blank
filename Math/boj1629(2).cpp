#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	long long a,b,c;
	
	cin >> a >> b >> c;
	
	long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % c;
        a = ((a % c) * (a % c)) % c;
        b /= 2;
    }
	
	cout << res << endl;
	
	return 0;
}