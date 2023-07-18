/*
인접행렬과 인접행렬의 거듭제곱
https://blog.naver.com/PostView.naver?blogId=gt7461&logNo=110151975370&redirect=Dlog&widgetTypeCall=true&topReferer=https%3A%2F%2Fstack07142.tistory.com%2F119&directAccess=false
행렬의 곱과 거듭제곱
https://mathbang.net/562
*/
#include <iostream>
#define mod 1000000007LL

using namespace std;

int map[8][8] =
{{0,1,1,0,0,0,0,0},
 {1,0,1,1,0,0,0,0},
 {1,1,0,1,1,0,0,0},
 {0,1,1,0,1,1,0,0},
 {0,0,1,1,0,1,0,1},
 {0,0,0,1,1,0,1,0},
 {0,0,0,0,0,1,0,1},
 {0,0,0,0,1,0,1,0}
};

long long ans[8][8]=
{{0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0},
 {	0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0}
};

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}