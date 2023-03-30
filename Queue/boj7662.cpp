#include <iostream>
#include <set>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	char c;
	int T,k,n;
	cin >> T;
	for(int C = 0 ; C < T ; C++){
		cin >> k;
		multiset<int> q;
		for(int i = 0 ; i < k ; i++){
			cin >> c >> n;
			if(c == 'I'){
				q.insert(n);
				continue;
			}
			
			if(q.empty())	continue;
			if(n == -1){
				q.erase(q.begin());
				continue;
			}
			auto iter = q.end();
			iter--;
			q.erase(iter);
		}
		if(q.empty()){
			cout << "EMPTY\n";
		}
		else{
			auto iter = q.end();
			iter--;
			cout << *iter << ' ' << *q.begin() << '\n';
		}
	}
	
	return 0;
}