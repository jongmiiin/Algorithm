#include <bits/stdc++.h>

using namespace std;

string build[1004];
bool flag[1004][1004];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs(int w, int h);

int main(){
	int t;
	cin >> t;
	while(t--){
		int w, h;
		cin >> w >> h;
		for(int i=0;i<h;i++)
			cin >> build[i];
		bfs(w, h);
		memset(flag, false, sizeof(flag));
	}
	return 0;
}

void bfs(int w, int h){
	int cnt = 0;
	queue<pair<int, int>> man;
	queue<pair<int, int>> fire;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(build[i][j] == '@'){
				man.push({i,j});
				flag[i][j] = true;
			}
			if(build[i][j] == '*'){
				fire.push({i, j});
				flag[i][j] = true;
			}
		}
	}
	while(!man.empty()){
		int msize = man.size(), fsize = fire.size();
		cnt++;
		while(fsize--){
			int y = fire.front().first, x = fire.front().second;
			fire.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=h || nx<0 || nx>=w || flag[ny][nx] || build[ny][nx] != '.') continue;
				fire.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
		while(msize--){
			int y = man.front().first, x = man.front().second;
			man.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=h || nx<0 || nx>=w){
					cout << cnt << '\n';
					return;
				}
				if(flag[ny][nx] || build[ny][nx] != '.') continue;
				man.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return;
}