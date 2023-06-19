#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int w,h,x,y,P;
	cin >> w >> h >> x >> y >> P;
	
	int p[50][2];
	for(int i = 0 ; i < P ; i++){
		cin >> p[i][0] >> p[i][1];
	}
	
	int cnt = 0;
	for(int i = 0 ; i < P ; i++){
		if(p[i][0] >= x && p[i][0] <= x + w && p[i][1] >= y && p[i][1] <= y + h){
			cnt++;
			continue;
		}
		int d[2];
		d[0] = x-p[i][0];
		d[1] = y+h/2-p[i][1];
		
		int l = d[0]*d[0] + d[1]*d[1];
		if(l <= h*h/4){
			cnt++;
			continue;
		}
		
		d[0] += w;
		l = d[0]*d[0] + d[1]*d[1];
		if(l <= h*h/4){
			cnt++;
			continue;
		}
	}
	
	cout << cnt << '\n';
	
	return 0;
}