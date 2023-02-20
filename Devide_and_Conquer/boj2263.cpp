#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;

void recurfunc(int st,int ed);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	sync_with_stdio(false);
	
	int n;
	
	cin >> n;
	
	int t;
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		inorder.push_back(t);
	}
	for(int i = 0 ; i < n ; i++){
		cin >> t;
		preorder.push_back(t);
	}
	
	recurfunc(0,n);
	
	return 0;
}

void recurfunc(int pst,int ped,int ist,int ied){
	cout << postorder[ped-1]  << ' ';
	
	int root_node_index_in_inorder;
	for(int i = ist ; i < ied ; i++){
		if(inorder[i] == postorder[ped-1]){
			root_node_index_in_inorder = i;
			break;
		}
	}
	
	recurfunc()
}