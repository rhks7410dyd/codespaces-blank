//시간초과
#include <iostream>
#include <vector>

using namespace std;

int g,p;
int info[100001];
bool doking[100001];
vector<int> v;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> g >> p;
	
	int temp;
	int ans = 0;
	bool end = false;
	doking[0] = true;
	
	for(int i = 0 ; i < p ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i = 0 ; i < p ; i++){
		temp = v[i];
		
		while(temp > 0){
			if(!doking[temp]){
				ans++;
				doking[temp]=true;
				break;
			}
			else{
				temp--;
			}
		}
		if(temp <= 0)	end = true;
		
		
		if(end) break;
	}
	
	cout << ans << '\n';
	
	return 0;
}