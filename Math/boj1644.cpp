#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
bool eratos[4000010];
vector<long long> v;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N;
	
	fill(&eratos[1],&eratos[4000010],true);
	
	for(int i = 2 ; i < 2000 ; i++){
		if(!eratos[i])	continue;
		
		int now = 2*i;
		while(now <= N){
			eratos[now] = false;
			now += i;
		}
	}
	
	v.push_back(0);
	eratos[2] = true;
	long long sum = 0;
	for(int i = 2 ; i <= N ; i++){
		if(eratos[i]){
			sum += i;
			v.push_back(sum);
		}
	}
	
	int cnt = 0;
	int start = 0,end = 0;
	while(end < v.size() || start < end){
		if(v[end]-v[start] < N){
			if(end == v.size() - 1)	break;
			end++;
		}
		else if(v[end]-v[start] > N){
			start++;
		}
		else{
			cnt++;
			start++;
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}