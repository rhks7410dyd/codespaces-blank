#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
	int left,right;
};

node arr[26];

void preorder(int rt){
	cout << (char)(rt+'A');
	if(arr[rt].left != -19)	preorder(arr[rt].left);
	if(arr[rt].right != -19)	preorder(arr[rt].right);
}

void inorder(int rt){
	if(arr[rt].left != -19)	inorder(arr[rt].left);
	cout << (char)(rt+'A');
	if(arr[rt].right != -19)	inorder(arr[rt].right);	
}

void postorder(int rt){
	if(arr[rt].left != -19)	postorder(arr[rt].left);
	if(arr[rt].right != -19)	postorder(arr[rt].right);	
	cout << (char)(rt+'A');
}

int N;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	//cout << '.'-'A' << endl; -19
	
	cin >> N;
	
	char left,right,root;
	for(int i = 0 ; i < N ; i++){
		cin >> root >> left >> right;
		arr[(int)(root-'A')] = {left-'A',right-'A'};
	}
	
	/*
	for(int i = 0 ; i < N ; i++){
		cout << arr[i].root << ' ' << arr[i].left << ' ' << arr[i].right << ' ' << endl;
	}*/
	
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	
	return 0;
}