#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v;
int N;
long long M;

bool compare(long long& a,long long& b){
	return a > b;
}

long long cal_get_wood(int h){
	int i = 0;
	long long ret = 0;
	while(v[i] > h){
		ret += v[i]-h;
		i++;
	}
	return ret;
}

int reculsive(int low,int high){
	int mid = (low + high)/2;
	long long temp;
	
	if(mid == 0)	return 0;
	
	long long mid_area = cal_get_wood(mid);
	if(mid_area == M)	return mid;
	
	if(mid_area > M){
		temp = cal_get_wood(mid+1);
		if(temp == M)	return mid+1;
		if(temp < M)	return mid;
		return reculsive(mid+1,high);
	}
	else{
		temp = cal_get_wood(mid-1);
		if(temp == M)	return mid-1;
		if(temp > M)	return mid-1;
		return reculsive(low,mid);
	}
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
	
	int ans;
	if(M == 1){
		ans = v[0]-1;
	}
	else{
		ans = reculsive(0,v[0]);
	}
	
	cout << ans << endl;
	
	return 0;
}