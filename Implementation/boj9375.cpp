#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C,N;
	
	cin >> C;
	for(int c = 0 ; c < C ; c++){
		cin >> N;
		
		string name,Type;
		map<string,int> ma;
		vector<string> cloth_type;
		for(int i = 0 ; i < N ; i++){
			cin >> name >> Type;
			ma[Type]++;
			if(ma[Type] == 1){
				cloth_type.push_back(Type);
			}
		}
		int day = 1;
		
		for(int i = 0 ; i < cloth_type.size() ; i++){
			day *= ma[cloth_type[i]]+1;
		}
		
		cout << day-1 << endl;
	}
	
	return 0;
}