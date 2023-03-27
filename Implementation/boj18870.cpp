#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> v_sort;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	
	int t;
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&t);
		v.push_back(t);
		v_sort.push_back(t);
	}
	
	sort(v_sort.begin(),v_sort.end());
	v_sort.erase(unique(v_sort.begin(), v_sort.end()), v_sort.end()); 
	
	for(int i = 0 ; i < N ; i++){
		printf("%ld ",lower_bound(v_sort.begin(),v_sort.end(),v[i])-v_sort.begin());
	}
	
	return 0;
}