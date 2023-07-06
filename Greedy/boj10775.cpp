#include <iostream>
#include <vector>

using namespace std;

int g,p;
int uni[100010];
vector<int> v;

int get_root(int num);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> g >> p;
	
	int temp;
	int ans = 0;
	bool end = false;
	
	for(int i = 0 ; i < p ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i = 0 ; i < p ; i++){
		temp = v[i];
		
		if(temp > g){
			temp = g;
		}
		
		if(uni[temp]){
			while(uni[temp] != 0){
				temp = get_root(temp)-1;
			}
			
			if(temp == 0){
				break;
			}
			uni[temp] = temp;
			uni[temp+1] = temp;
			ans++;
		}
		else{
			uni[temp] = temp;
			ans++;
		}
	}
	
	/*
	cout << "---------------------------\n";
	for(int i = 0 ; i < p ; i++){
		cout << uni[i] << ' ';
	}
	cout << '\n' << '\n';
	*/
	
	cout << ans << '\n';
	
	return 0;
}

int get_root(int num){
	if(uni[num] == num)	return num;
	return uni[num] = get_root(uni[num]);
}