#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
	if(a.second < b.second)	return true;
	if(a.second > b.second)	return false;
	return a.first < b.first;
}

int main(){
	vector<pair<int,int>> v;
	int N,st,et;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> st >> et;
		v.push_back({st,et});
	}

	sort(v.begin(),v.end(),compare);
	
	int i = 0, meeting_count = 0 , temp_end_time = 0;
	while(true){
		if(i >= N)	break;
		if(temp_end_time <= v[i].first){
			meeting_count++;
			temp_end_time = v[i].second;
		}
		i++;
	}
	cout << meeting_count << endl;
}