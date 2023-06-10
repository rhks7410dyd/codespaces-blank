#include <iostream>
#include <stack>
#include <random>

using namespace std;

int n,b;
string ans = "";
string output = "";
void My_solve(){
	int N = n;
	int B = b;
	int tmp;
	stack <int> s;
	while(B<=N){
		tmp=N%B;
		N/=B;
		s.push(tmp);
	}
	s.push(N);
	char alpha;
	int digit = s.size();
	for(int i = 0 ; i < digit ; i ++){
		tmp=s.top();
		s.pop();
		if(tmp>9){
			alpha=tmp-10+'A';
			ans += alpha;
		}
		else{
			ans += temp;
		}
	}
}



int main(){
	
	cin >> N >> B;
	
	
	return 0;
}

int main(void)
{
	char n[1001] = {0};
	int a, b, x, count = 0;
	
	scanf("%d %d", &a, &b);
	
	if (b >= 10)
	{
		for (int i = 0; a != 0; i++)       // i번 만큼 count
		{
			if (a/b >= 0)
			{
				n[i] = a%b;
				a = a/b;
				count+=1;
			}
		}
		for (int j = 0; j < count/2; j++)  // 배열을 순서대로 정렬
		{
			int temp = n[j];
			n[j] = n[(count-1)-j];
			n[(count-1)-j] = temp;
		}
		
		for (int k = 0; k < count; k++)
		{
			if(n[k] >= 10)	n[k] = n[k] + 'A' - 10;
			else n[k] = n[k] + '0';
		}
	}

	else if (b <= 9)
	{
		for (int i = 0; a != 0; i++)
		{
			if (a/b >= 0)                  // 실행된 i번 만큼 count +1
			{
				n[i] = a%b;
				a = a/b;
				count+=1;
			}
		}
		for (int j = 0; j < count/2; j++)  // 배열을 순서대로 정렬
		{
			int temp = n[j];
			n[j] = n[(count-1)-j];
			n[(count-1)-j] = temp;
		}
		
		for(int i = 0 ; i < count ; i++){
			n[i] = n[i] + '0';
		}
	}
	
    printf("%s", n);	// 10진수 이상 출력  
	
    return 0;
}