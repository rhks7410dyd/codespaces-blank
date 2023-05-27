#include <iostream>
#include <algorithm>

using namespace std;

void swap(int& a,int& b);
double slope(int x1,int x2,int y1,int y2);
double lin_func(double m,int x1,int y1,int x);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int x1,x2,x3,x4,y1,y2,y3,y4;
	
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
	if(x1 >= x2){
		if(x1 == x2 && y1 > y2){
			swap(y1,y2);
		}
		else if(x1 != x2){
			swap(x1,x2);
			swap(y1,y2);
		}
	}
	if(x3 > x4){
		if(x3 == x4 && y3 > y4){
			swap(y3,y4);
		}
		else if(x3 != x4){
			swap(x3,x4);
			swap(y3,y4);
		}
	}
	
	//printf("%d %d %d %d\n",x1,x2,x3,x4);
	
	int ans;
	// 두 개의 선분이 y 축에 평행한 경우
	if(x1 == x2 && x3 == x4){
		if(x1 == x3)	ans = 1;
		else	ans = 0;
	}
	else if(x1 == x2 || x3 == x4){// 하나만 두 x 값이 같은 경우
		if(x3 == x4){//x1,y1 x2,y2 이 선분이 y축에 평행한 선분으로 가정하고 뒤에 구현을 간단히 하기위한 전처리 과정
			swap(x1,x3);
			swap(x2,x4);
			swap(y1,y3);
			swap(y2,y4);
		}
		if(x1 < x3 || x1 > x4){
			ans = 0; //printf("41ln\n");
		}
		else{
			double m = slope(x3,x4,y3,y4);
			double h = lin_func(m,x3,y3,x1);
			if((h > y1 - (1/1e10) && h < y2 + (1/1e10)))	ans = 1;
			else{
				ans = 0; //printf("48ln\n");
			}
		}
	}
	else{// 둘다 기울기가 있는 경우
		if((min(y1,y2) > max(y3,y4)) || (min(y3,y4) > max(y1,y2)))	ans = 0;
		else{
			int s = max(x1,x3);
			int e = min(x2,x4);
			if(s > e){
				ans = 0; //printf("58ln\n");
			}
			else{
				double m1,m2,y_s,y_e;
				m1 = slope(x1,x2,y1,y2);
				m2 = slope(x3,x4,y3,y4);
				y_s = lin_func(m1,x1,y1,s) - lin_func(m2,x3,y3,s);
				y_e = lin_func(m1,x1,y1,e) - lin_func(m2,x3,y3,e);
				//printf("s %d e %d m1 %lf m2 %lf y_s %lf y_e %lf\n",s,e,m1,m2,y_s,y_e);
				if(y_s * y_e <= 0){
					ans = 1; //printf("66ln\n");
				}
				else{
					ans = 0; //printf("69ln\n");
				}
			}
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

void swap(int& a,int& b){
	int t = a;
	a = b;
	b = t;
}

double slope(int X1,int X2,int Y1,int Y2){
	return ((double)Y2-Y1)/(X2-X1);
}

double lin_func(double M,int X,int Y,int x){
	return (M*(x-X)+Y);
}