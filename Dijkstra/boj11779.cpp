/*
최소 비용에 대한 배열을 스트링,인트 페어로 만들어서 경로를 저장하고, 이후 도착 경로의 스트링의 사이즈가 지나는 도시의 개수, 순서대로 출력을 하면 된다.
내 코드 결과
6292kb	36ms
참조한 코드 결과
4752kb	36ms

알고리즘 상으로 완전히 동일해서 왜 틀렸나 고민했더니, 단순한 착각(아래 메모되어있음) 때문이었다.
하지만 메모리 사용량이 1.5메가 이상 차이가 난 이유는 구조체 + long long을 사용했기 때문일 것이다.
c++ 구조체는 내부 변수 중에 가장 큰 타입을 기준으로 만들어지기 때문. 즉, int node_num 또한 실제로 사용하는 메모리 크기와 상관없이 long long인 변수와 동일한
크기로 봐야되는 상황인 것이다.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 987654321

using namespace std;

long long d[1001];
int visit[1001];
vector<pair<int,int>> edge[1001];
vector <int> path;
int n,m,start_node,end_node;

struct Info {
    int node_num;
    long long dis;
    Info(int n, long long d) : node_num(n), dis(d) {}    // 생성자 정의

    bool operator<(const Info i) const {
        if(this->dis != i.dis){
			return this->dis > i.dis;
		}
		return this->node_num > i.node_num;
    }
};

void Dijkstra();

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	int ts,te,tv;
	for(int i = 0 ; i < m ; i++){
		cin >> ts >> te >> tv;
		edge[ts].push_back(make_pair(te,tv));
	}
	
	cin >> start_node >> end_node;
	
	Dijkstra();
	
	int t = end_node;
	while(t){
		path.push_back(t);
		t = visit[t];
	}
	
	cout << d[end_node] << '\n' << path.size() << '\n';
	for(int i = path.size() - 1 ; i >= 0 ; i--){
		cout << path[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}

void Dijkstra(){
	fill(&d[0],&d[1001],INF);//이걸 1000까지로 해서 틀렸던걸 몇시간 동안 못봤던 걸까...
	
	priority_queue<Info>pq;
    pq.push(Info(start_node,0));
    d[start_node] = 0;
	visit[start_node] = 0;
	 
	while(!pq.empty()){
        long long dist = pq.top().dis;
        int now = pq.top().node_num;
        pq.pop();
        
        if(d[now] < dist)	continue;

        for(int i = 0 ; i < edge[now].size() ; i++){
			int next = edge[now][i].first;
            long long cost = dist + (long long)edge[now][i].second;
            if(cost < d[next]){
				d[next] = cost;
                visit[next] = now;
                pq.push(Info(next,cost));
            }
        }
    }
}

/*참조한 코드 https://yabmoons.tistory.com/392
#include<iostream>
#include<vector>
#include<queue>
 
#define endl "\n"
#define MAX 1010
#define INF 987654321
using namespace std;
 
int N, M, Start, End;
int Dist[MAX];
int Route[MAX];
vector<pair<int, int>> V[MAX];
vector<int> Route_V;
 
void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) Dist[i] = INF;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
    }
    cin >> Start >> End;
}
 
void Solution()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Route[Next] = Cur;
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
 
    cout << Dist[End] << endl;
    int Temp = End;
    while (Temp)
    {
        Route_V.push_back(Temp);
        Temp = Route[Temp];
    }
    cout << Route_V.size() << endl;
    for (int i = Route_V.size() - 1; i >= 0; i--) cout << Route_V[i] << " ";
    cout << endl;
 
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

*/