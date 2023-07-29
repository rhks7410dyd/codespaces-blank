//seg_fault...^^
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h,w,r,c,best,blank_cell;
bool map[10][10];

vector<vector<pair<int,int>>> rotations;
vector<string> Block;

int blockSize;

vector<string> rotate(const vector<string>& arr);
void generateRotations(vector<string> block);
int Solve();
bool set(int y,int x,const vector<pair<int,int>>& block,int delta);
void search(int placed);

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int t;
	string temp;
	cin >> t;
	
	while(t--){
		cin >> h >> w >> r >> c;
		
		blank_cell = 0;
		
		for(int i = 0 ; i < h ; i++){
			cin >> temp;
			for(int j = 0 ; j < w ; j++){
				if(temp[j] == '#'){
					map[i][j] = false;
				}
				else{
					map[i][j] = true;
					blank_cell++;
				}
			}
		}
		
		Block.clear();
		for(int i = 0 ; i < r ; i++){
			cin >> temp;
			Block.push_back(temp);
		}
		
		generateRotations(Block);
		
		int ans = Solve();
		
		cout << ans << '\n';
	}

	return 0;
}

vector<string> rotate(const vector<string>& arr){
	vector<string> ret(arr[0].size(),string(arr.size(), ' '));
	for(int i = 0 ; i < arr.size() ; i++){
		for(int j = 0 ; j < arr[0].size() ; j++){
			ret[j][arr.size()-i-1] = arr[i][j];
		}
	}
	return ret;
}

void generateRotations(vector<string> block){
	rotations.clear();
	rotations.resize(4);
	for(int rot = 0 ; rot < 4 ; rot++){
		int originY = -1,originX = -1;
		for(int i = 0 ; i < block.size() ; i++){
			for(int j = 0 ; j < block[i].size(); j++){
				if(block[i][j] == '#'){
					if(originY == -1){
						originY = i;
						originX = j;
					}

					rotations[rot].push_back(make_pair(i-originY,j-originX));
				}
			}
		}
		block = rotate(block);
	}
	
	sort(rotations.begin(),rotations.end());
	rotations.erase(unique(rotations.begin(),rotations.end()),rotations.end());
	blockSize = rotations[0].size();
}

void search(int placed){
	if(blank_cell == 0 || blank_cell/blockSize <= best){
		best = max(best,placed);
		return;
	}
	
	int y = -1,x = -1;
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			if(!map[i][j]){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1)	break;
	}
	
	/*
	여기서 가지치기를 해줘야됨
	내 생각으로는 미리 빈칸 갯수를 확인하고, 그 갯수에서 set으로 놓을 때마다 blockSize만큼 빼주고 다시 안놓았을 때는 더해주고 이런 느낌으로 가야할듯
	*/
	
	for(int i = 0 ; i < rotations.size() ; i++){
		if(set(y,x,rotations[i],1)){
			blank_cell -= blockSize;
			search(placed+1);
		}
		blank_cell += blockSize;
		set(y,x,rotations[i],-1);
	}
	
	map[y][x] = true;
	blank_cell--;
	search(placed);
	map[y][x] = false;
	blank_cell++;
}

int Solve(){
	best = 0;
	search(0);
	return best;
}

bool set(int y,int x,const vector<pair<int,int>>& block,int delta){
	bool input_val;
	if(delta == 1){
		for(int i = 0 ; i < blockSize ; i++){
			auto now = block[i];
			now.first += y;
			now.second += x;
			
			if(now.first < 0 || now.second < 0 || now.first >= h || now.second >= w)	return false;
			
			if(map[now.first][now.second])	return false;
			map[now.first][now.second] = true;
		}
	}
	else{
		for(int i = 0 ; i < blockSize ; i++){
			auto now = block[i];
			now.first += y;
			now.second += x;
			
			map[now.first][now.second] = false;
		}
	}
	
	return true;
}