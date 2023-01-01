/*
일단 인접리스트로 구현해서 맞춰보고 맞고 나면 이후 다른 사람의 정답 코드를 확인해 피드백 할 것
*/
#include <iostream>
#define nodeptr node*

using namespace std;

struct node{
	node *left = NULL , *right = NULL;
	int key;
};

nodeptr head = NULL;

void postorder(nodeptr t){
	if(t-> left != NULL) postorder(t->left);
	if(t-> right != NULL) postorder(t->right);
	cout << t-> key << '\n';
}

int main(){
	nodeptr temp;
	int temp_val;
	bool first_input = true;
	while(true){
		cin >> temp_val;
		if(cin.eof() == true || temp_val == -1)	break;
		
		if(first_input){
			head = new node();
			head -> key = temp_val;
			first_input = false;
			temp = head;
			//cout << "ln35 " << temp -> key << endl;
			continue;
		}
		
		//cout << temp_val << ' ';
		while(true){
			if(temp_val < temp -> key){
				if(temp -> left == NULL){
					temp -> left = new node();
					temp -> left -> key = temp_val;
					//cout << "add new node to left\n";
					break;
				}
				else{
					temp = temp -> left;
					//cout << "now temp is previous temp's left\n";
				}
			}
			else{
				if(temp -> right == NULL){
					temp -> right = new node();
					temp -> right -> key = temp_val;
					//cout << "add new node to right\n";
					break;
				}
				else{
					temp = temp -> right;
					//cout << "now temp is previous temp's right\n";
				}
			}
		}
		temp = head;
	}
	
	postorder(head);
	
	return 0;
}