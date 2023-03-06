#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int time_[257];
int N,M,B;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> B;
	
	int t;
	for(int i = 0 ; i < N*M ; i++){
		cin >> t;
		v.push_back(t);
	}
	
	sort(v.begin(),v.end());
	
	for(int h = 0 ; h < 257 ; h++){
		int t = 0;
		int now_b = B;
		for(int i = N*M-1 ; i >= 0 ; i--){
			if(v[i] > h){
				t += 2*(v[i]-h);
				now_b += v[i]-h;
			}
			else{
				t += h-v[i];
				now_b -= h-v[i];
				if(now_b < 0){
					time_[h] = 987654321;
					break;
				}
			}
		}
		if(time_[h] != 987654321){
			time_[h] = t;
		}
	}
	
	int min_time = 987654321;
	int min_height;
	for(int i = 256 ; i >= 0 ; i--){
		if(min_time > time_[i]){
			min_time = time_[i];
			min_height = i;
		}
	}
	
	cout << min_time << ' ' << min_height << endl;
	
	return 0;
}