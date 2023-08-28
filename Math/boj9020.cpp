//8:20
#include <iostream>
#define INF 10001
using namespace std;

bool eratoth[INF];

int get_ans(int n)
{
	for(int i = n/2 ; i >= 2 ; i--)
	{
		if(!eratoth[i] && !eratoth[n-i])	return i;
	}
	return 0;
}

void get_eratoth()
{
	eratoth[1] = true;
	for(int i = 2 ; i < INF ; i++)
	{
		if(!eratoth[i])
		{
			int temp = 2*i;
			while(temp < INF)
			{
				eratoth[temp] = true;
				temp += i;
			}
		}
	}
}

void Solve()
{
	get_eratoth();
	
	int n,T,ans;
	cin >> T;
	while(T--){
		cin >> n;
		ans = get_ans(n);
		cout << ans << ' ' << n - ans << '\n';
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	Solve();
	
	return 0;
}