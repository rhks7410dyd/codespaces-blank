#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	vector<int> v;
	vector<int> freq;
	
	int N;
	
	scanf("%d",&N);
	
	int t,sum = 0;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
		sum += t;
	}
	
	sort(v.begin(),v.end());
	
	int temp_v=-987654321,temp_c=-1,max_c=0;
	for(int i = 0 ; i < N ; i++){
		if(temp_v != v[i]){
			if(temp_c > max_c){
				max_c = temp_c;
				freq.clear();
				freq.push_back(temp_v);
			}
			else if(temp_c == max_c){
				freq.push_back(temp_v);
			}
			temp_v=v[i];
			temp_c=1;
		}
		else{
			temp_c++;
		}
	}
	if(temp_c >= max_c){
		freq.push_back(temp_v);
	}
	
	int aver = floor((float)sum/N + 0.5);
	int mid_val = v[(N-1)/2];
	int dif = v[N-1] - v[0];
	int max_freq;
	
	if(N!=1){
		if(freq.size() == 1){
			max_freq = freq[0];
		}
		else{
			max_freq = freq[1];
		}
	}
	else{
		max_freq = v[0];
	}
	printf("%d\n%d\n%d\n%d\n",aver,mid_val,max_freq,dif);
	
	return 0;
}