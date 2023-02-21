/*
반례를 못찾고 있음.
어디서 무슨 인덱스 실수가 났는지 확인해봐야됨.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
bool visit[100001];
void recurfunc(int pst,int ped,int ist,int ied);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	
	cin >> n;
	
	int t;
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		inorder.push_back(t);
	}
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		postorder.push_back(t);
	}
	
	recurfunc(0,n,0,n);
	
	cout << '\n';
	
	return 0;
}

void recurfunc(int ist,int ied,int pst,int ped){
	if(visit[ped-1])	return;
	visit[ped-1] = true;
	cout << postorder[ped-1]  << ' ';
	//cout << "postorder[ped-1] : " << postorder[ped-1] << endl;
	int root_node_index_in_inorder;
	
	if(pst+1 == ped){
		return;
	}
	
	for(int i = ist ; i < ied ; i++){
		if(inorder[i] == postorder[ped-1]){
			root_node_index_in_inorder = i;
			break;
		}
	}
	
	int left_tree_size = root_node_index_in_inorder - ist;
	int right_tree_size = ied - root_node_index_in_inorder-1;
	
	//여기서 한 쪽 노드가 없는 경우를 고려를 안했음! -> 완전이진트리인 경우만을 상정하고 문제를 풀었음
	//cout << "left node func : " << ist << " , " << ist+left_tree_size << " , " << pst << " , " << pst+left_tree_size << endl;
	//cout << "right node func : "  << ied-right_tree_size << " , " << ied << " , " << ped-right_tree_size-1 << " , " << ped - 1 << endl;
	recurfunc(ist,ist+left_tree_size,pst,pst+left_tree_size);
	recurfunc(ied-right_tree_size,ied,ped-right_tree_size-1,ped-1);
}

/*
10
4 2 1 6 5 7 3 10 9 8
4 2 6 7 5 10 9 8 3 1
1 2 4 3 5 6 7 8 9 10
ln76에서 이상한 값이 잡히는 이유는 root_node_index_in_inorder 가 제대로 명명되지 않아서이다. 
가장 단순하게 생각나는건 bool visit 어레이를 만들어서 이미 출력된 위치는 true로 바꿔놓고, return;으로 강제로 함수를 끝내는 방법이다.
*/

/*
10
5 3 6 2 7 4 9 8 10 1
5 6 3 7 9 10 8 4 2 1
1 2 3 5 6 4 7 8 9 10

*/