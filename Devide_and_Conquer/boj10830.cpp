#include <iostream>

using namespace std;

long long N,B;

long long inp[5][5];
long long ans[5][5];
long long tmp[5][5];

void square_inp_matrix(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			tmp[i][j] = inp[i][0] * inp[0][j] %1000 ;
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			for(int k = 1 ; k < N ; k++){
				tmp[i][j] += inp[i][k] * inp[k][j];
				tmp[i][j] %= 1000;
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			inp[i][j] = tmp[i][j];
		}
	}
}

void times_inp_to_ans(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			tmp[i][j] = inp[i][0] * ans[0][j];
			tmp[i][j] %= 1000;
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			for(int k = 1 ; k < N ; k++){
				tmp[i][j] += inp[i][k] * ans[k][j];
				tmp[i][j] %= 1000;
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			ans[i][j] = tmp[i][j];
		}
	}
}

void print_ans(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print_tmp(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << tmp[i][j] << ' ';
		}
		cout << '\n';
	}
}

void print_inp(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout << inp[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> B;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> inp[i][j];
			ans[i][j] = inp[i][j];
		}
	}
	print_ans();
	cout << "inp\n";
	print_inp();
	B--;
	while(B > 0){
		if(B%2 == 1){
			times_inp_to_ans();
		}
		
		B >>= 1;
		square_inp_matrix();
		
		cout << "\ninp\n";
		print_inp();
		cout << "\ntmp\n";
		print_tmp();
		cout << "\nans\n";
		print_ans();
		cout << '\n';
	}
	
	return 0;
}