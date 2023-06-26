#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int scores[1000006];
int cards[1000006];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++){
		int temp;
		cin >> temp;

		numbers.push_back(temp);
		cards[temp] = 1;
	}

	for (int i = 0; i < N; i++){
		for (int j = numbers[i] * 2; j < 1000001; j += numbers[i])
		{
			if (cards[j] == 1)
			{
				scores[numbers[i]]++;
				scores[j]--;
			}
		}
	}

	for (int i = 0; i < N; i++)	cout << scores[numbers[i]] << " ";

	return 0;
}