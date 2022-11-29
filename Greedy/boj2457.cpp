#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int month_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int N;
vector <flower> v;

struct flower{
	int blossom_m,blossom_d,wither_m,wither_d;
};

/*
정렬 기준
1. 꽃이 빠르게 피는 순으로 정렬 
2. 피는 날짜가 같다면 빠르게 지는 순으로 정렬
*/
bool compare(flower& a, flower& b){
	if(a.blossom_m != b.blossom_m){//꽃이 다른 달에 피는 경우
		return a.blossom_m < b.blossom_m;
	}
	else{//꽃이 같은 달에 피는 경우
		if(a.blossom_d != b.blossom_d){//꽃이 같은 달 다른 날에 피는 경우
			return a.blossom_d < b.blossom_d;
		}
		else{//꽃이 같은 날 피는 경우
			if(a.wither_m != b.wither_m){//꽃이 다른 달에 지는 경우
				return a.wither_m < b.wither_m;
			}
			else{//꽃이 같은 달에 지는 경우
				return a.wither_d < b.wither_d;
			}
		}
	}
}

/*
꽃(3)이 이전 것(1)이 지기 전에는 먼저 펴야하고, 그중에서 가장 늦게 지는 거(2)를 선택해야됨
여기서 중요한 건 이전 꽃(1),다음 예정인 꽃(2), 지금 비교해야되는 꽃(3)
이렇게 3개의 꽃을 동시에 기억해야된다는 점임
이를 통해 생각해볼 수 있는 것은 함수에 3개의 꽃에 대한 변수를 받아서 한번에 고민하는 것이 좋을 것
같다는 거다 
before_flower : 이전 차시에서 가장 최선이었던 꽃
expected_flower : 다음 꽃 예정인 꽃(현재까지의 최선의 꽃)
now_flower : 지금 비교해보려는 꽃
1. 이전 꽃이 지기 전에 피는지 확인한다. 아니라면 false를 반환하고 이 경우에는 현재 예정된 꽃을 
2. 현재 예정된 꽃보다 지는 날짜가 늦으면 지금 꽃을 예정된 꽃으로 바꾼다.
*/
bool maintain(flower& before_flower, flower& expected_flower, flower& now_flower){
	if(befo)
}

void printvector(){
	for(int i = 0 ; i < N ; i++){
		cout << v[i].blossom_m << ' ' << v[i].blossom_d << ' ' << v[i].wither_m << ' ' << v[i].wither_d << '\n';
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	cin >> N;
	
	int first_month, first_day, second_month, second_day;
	for(int i = 0 ; i < N ; i++){
		cin >> first_month >> first_day >> second_month >> second_day;
		v.push_back({first_month,first_day,second_month,second_day});
	}
	
	sort(v.begin(),v.end(),compare);
	
	//printvector();
	
/*
첫 꽃 선정 기준
1. 3월 1일 전에는 피어야 한다
2. 1번을 만족시키면서 가장 늦게 져야 한다
*/
	
	flower before_flower = {1,1,3,1};
	flower temp_flower;
	int wither_m = 3,wither_d = 1;
	int latest_m = 3,latest_d = 1;
	for(int i = 0 ; i < N ; i++){
		temp_flower = v[i];
		if(compare(before_flower,temp_flower)){
			cout << before_flower.blossom_m << ' ' << before_flower.blossom_d << ' ' << before_flower.wither_m << ' ' << before_flower.wither_d << '\n';
			cout << temp_flower.blossom_m << ' ' << temp_flower.blossom_d << ' ' << temp_flower.wither_m << ' ' << temp_flower.wither_d << '\n';
			before_flower = temp_flower;
		}
	}
	
	return 0;
}