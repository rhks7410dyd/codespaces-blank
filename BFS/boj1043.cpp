#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> who_attend[50];
queue<int> q;
int N,M,people_num;
bool graph[51][51];
bool listen_true_story[51];

void get_edge();
void add_edge(int party_num);
void BFS();
int lied_party_count();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M>>people_num;
	
	int t;
	for(int i = 0 ; i < people_num ; i++){
		cin >> t;
		q.push(t);
		listen_true_story[t] = true;
	}
	
	get_edge();
	//입력부 끝
	
	BFS();
	
	int count = lied_party_count();
	
	cout << count << endl;
	
	return 0;
}

void get_edge(){
	for(int i = 0 ; i < M ; i++){
		cin >> people_num;
		add_edge(i);
	}
}

void add_edge(int party_num){
	int t;
	for(int i = 0 ; i < people_num ; i++){
		cin >> t;
		who_attend[party_num].push_back(t);
	}
	
	int person_1,person_2;
	for(int i = 0 ; i < who_attend[party_num].size() ; i++){
		for(int j = i + 1 ; j < who_attend[party_num].size() ; j++){
			person_1 = who_attend[party_num][i];
			person_2 = who_attend[party_num][j];
			graph[person_1][person_2] = true;
			graph[person_2][person_1] = true;
		}
	}
}

void BFS(){
	int t_person;
	while(!q.empty()){
		t_person = q.front();
		q.pop();
		for(int i = 1 ; i <= N ; i++){
			if(graph[t_person][i] && !listen_true_story[i]){
				q.push(i);
				listen_true_story[i] = true;
			}
		}
	}
}

int lied_party_count(){
	int count = 0,person;
	bool can_lied;
	for(int party_num = 0 ; party_num < M ; party_num++){
		can_lied = true;
		for(int i = 0 ; i < who_attend[party_num].size() ; i++){
			person = who_attend[party_num][i];
			if(listen_true_story[person]){
				can_lied = false;
				break;
			}
		}
		if(can_lied)	count++;
	}
	
	return count;
}