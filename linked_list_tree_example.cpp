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

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	nodeptr alpha;//nodeptr alpha,beta라 적으면 beta의 타입이 node가 되지 node*이 되지 않는다.
	nodeptr beta;
	nodeptr gamma;
	
	alpha = new node();
	beta = new node();
	gamma = new node();
	alpha -> key = a;
	alpha -> left = beta;
	alpha -> right = gamma;
	beta -> key = b;
	gamma -> key = c;
	node *temp;
	temp = alpha;
	cout << temp -> key << endl;
	temp = temp-> left;
	cout << temp-> key << endl;
	temp = alpha -> right;
	cout << temp -> key << endl;
	
	return 0;
}