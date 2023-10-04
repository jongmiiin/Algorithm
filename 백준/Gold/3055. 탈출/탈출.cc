#include <bits/stdc++.h>

using namespace std;

int n, m;

string forest[54];
bool flag[54][54];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> forest[i];
	bfs();
	return 0;
}

void bfs(){
	int cnt = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> water;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(forest[i][j]=='S'){
				q.push({i,j});
				flag[i][j] = true;
			}
			if(forest[i][j]=='*'){
				water.push({i,j});
				flag[i][j] = true;
			}
		}
	}
	while(!q.empty()){
		int qsize = q.size(), wsize = water.size();
		cnt++;
		while(wsize--){
			int y = water.front().first, x = water.front().second;
			water.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx= x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx] || forest[ny][nx] != '.') continue;
				water.push({ny,nx});
				flag[ny][nx] = true;
			}
		}
		while(qsize--){
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx= x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx] || forest[ny][nx] == 'X') continue;
				if(forest[ny][nx] == 'D'){
					cout << cnt;
					return;
				}
				q.push({ny,nx});
				flag[ny][nx] = true;
			}
		}
	}
	cout << "KAKTUS";
	return;
}