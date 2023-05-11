//아니, 이분탐색을 하면 안되는듯?
/*
<케이스>

6
-104336608 239510944 997686289 627058077 722156401 -942278495

=>-942278495 -104336608 239510944 627058077 722156401 997686289

<답>

-942278495 239510944 722156401

<케이스>

7
912022275 -968846127 195376182 -212509759 589371385 817446019 -59843192

<답>

-968846127 195376182 817446019
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N;
vector<long> v;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	int t;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	
	int best[3];//오름차순으로 3개
	long best_val=98765432123456789;
	
	for(int s = 0 ; s < N - 2; s++){
		int m = s + 1,e = N - 1;
		while(m<e){
			long long temp = v[s] + v[m] + v[e];
			if(abs(temp) < best_val){
				best[0] = s;
				best[1] = m;
				best[2] = e;
				best_val = abs(temp);
			}
			if(temp < 0){
				m++;
			}
			else{
				e--;
			}
		}
	}
	
	printf("%ld %ld %ld\n",v[best[0]],v[best[1]],v[best[2]]);
	
	return 0;
}