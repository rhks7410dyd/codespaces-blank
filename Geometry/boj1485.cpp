#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long x[4], y[4], s[6];

int main()
{
	int i, j, k, tc;
	cin >> tc;
	while (tc--)
	{
		k = 0;
		for (i = 0; i < 4; i++)
			cin >> x[i] >> y[i];

		for (i = 0; i < 4; i++)	
			for (j = i + 1; j < 4; j++)
			{
				s[k] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
				k++;
			}

		sort(s, s + 6);
		cout << (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5]) << '\n';
	}
}