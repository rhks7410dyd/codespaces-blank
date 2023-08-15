#include <iostream>
#include <map>
#define INF 1225000

using namespace std;

long long eratos[INF];
bool is_eratos(long long n);

int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	
	for(long long i = 1  ; i < INF ; i++){
		eratos[i] = i*i;
	}
	
	long long n;
	cin >> n;
	long long lim,lim2 = (n-1)/2;
	
	for(int i = 1 ; i < INF ; i++){
		if(n == eratos[i]){
			cout << -1 << '\n';
			return 0;
		}
		if(n/2 >= eratos[i])	lim = i;
		if(n < eratos[i])	break;
	}
	
	int t=0;
	//case 1
	
	int i = 1;
	while(true){
		if(eratos[INF-1]-n < eratos[i]){
			lim2 = i;
			break;
		}
		i++;
	}
	cout << lim << '\n' << lim2 << '\n';
	
	for(long long i = 1 ; i <= lim ; i++){
		long long temp = n - eratos[i];
		if(is_eratos(temp))	t++;
	}
	
	for(long long i = 1 ; i <= lim2 ; i++){
		long long temp = n + eratos[i];
		if(is_eratos(temp))	t++;
	}
	cout << t << '\n';
	return 0;
}

bool is_eratos(long long n){
	int start = 0,end = INF;
	while(start < end){
		int mid = (start+end)/2;
		
		if(eratos[mid] == n)	return true;
		
		if(eratos[mid] > n)	end = mid;
		else	start = mid+1;
	}
	
	return false;
}