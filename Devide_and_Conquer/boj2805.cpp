#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;
int N;
long long M;
int is_enough_area[1000005];//초기값 -1, 불가능 0, 가능 1로 저장

bool compare(long long& a,long long& b){
	return a > b;
}

long long cal_get_wood(long long h){
	int i = 0,ret = 0;
	while(v[i] > h){
		ret += v[i]-h;
		i++;
	}
	return ret;
}

int reculsive(int low,int high){
	int mid = (low + high)/2;
	
	int ret = 
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M;
	
	long long t;
	for(int i = 0 ; i < N ; i++){
		cin >> t;
		v.push_back(t);
	}
	
	sort(v.begin(),v.end(),compare);
	
	int high,low;
	for(int i = 0 ; i < N - 1 ; i++){
		high = v[i];
		low = v[i-1];
		long long t = cal_get_wood(low);
		if(t >= M)	break;
	}
	
	int ans = reculsive(low,high);
	
	return 0;
}