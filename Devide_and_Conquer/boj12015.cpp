#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	scanf("%d",&N);
	
	int t;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		if(!i || t > v[v.size()-1]){
			v.push_back(t);
		}
		else{
			int start = 0,end = v.size();
			while(start<end){
				int mid = (start+end)/2;
				if(v[mid] == t)	break;
				else if(v[mid] < t){
					if(t < v[mid+1]){
						v[mid+1] = t;
						break;
					}
					start = mid+1;
				}
				else if(v[mid] > t){
					if(mid == 0 || t > v[mid-1]){
						v[mid] = t;
						break;
					}
					end = mid;
				}
			}
		}
	}
	
	printf("%d\n",(int)v.size());
	
	return 0;
}

