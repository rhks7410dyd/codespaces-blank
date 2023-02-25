#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int g_case_num,g_n,g_m;
vector<int> friends[10];
bool have_matching_friends[10];
void recursive_func(int remain_stu_count, int now_stu);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int C;
	
	cin >> C;
	
	int a,b;
	for(int i = 0 ; i < C ; i++){
		cin >> g_n >> g_m;
		
		for(int j = 0 ; j < g_m ; j++){
			cin >> a >> b;
			if(a > b){
				int temp = a;
				a = b;
				b = temp;
			}
			friends[a].push_back(b);
		}
		
		g_case_num = 0;
		recursive_func(g_n,0);
		for(int j = 0 ; j < g_n ; j++){
			have_matching_friends[j] = false;
			friends[j].clear();
		}
		
		cout << endl;
		cout << g_case_num << '\n';
	}
	
	return 0;
}

void recursive_func(int remain_stu_count, int now_stu){
	have_matching_friends[now_stu] = true;
	
	cout << "print now_stu's friends list(" << now_stu << ")\n";
	for(int i = 0 ; i < friends[now_stu].size() ; i++){
		cout << friends[now_stu][i] << ' ';
	}
	cout << endl;
	
	for(int i = 0 ; i < friends[now_stu].size() ; i++){
		int next_stu = friends[now_stu][i];
		if(have_matching_friends[next_stu])	continue;
		
		
		
		if(remain_stu_count == 2){
			cout << remain_stu_count << " make one comb " << now_stu << ' ' << next_stu << endl;
			g_case_num++;
			continue;
		}

		have_matching_friends[next_stu] = true;
		int temp;
		for(int j = 0 ; j < g_n ; j++){
			if(!have_matching_friends[j]){
				cout << remain_stu_count << " info " << now_stu << ' ' << j << endl;
				temp = j;
				break;
			}
		}
		recursive_func(remain_stu_count-2,temp);
		have_matching_friends[next_stu] = false;
	}
	
	have_matching_friends[now_stu] = false;
}