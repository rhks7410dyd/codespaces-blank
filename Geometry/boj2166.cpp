//1/2 * (abs)(sigma_(i=1) ^(N){(x_i + x_(i+1))*(y_i - y_(i+1))})
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

pair<double,double> pos[10000];
int N;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	scanf("%d",&N);
	int x,y;
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&x,&y);
		pos[i] = {x,y};
	}
	
	double ans = 0;
	for(int i = 0 ; i < N - 1 ; i++){
		ans += (pos[i].first + pos[i+1].first)*(pos[i].second - pos[i+1].second);
	}
	ans += (pos[N-1].first + pos[0].first)*(pos[N-1].second - pos[0].second);
	ans = abs(ans/2);
	printf("%.1lf\n",ans);
	return 0;
}