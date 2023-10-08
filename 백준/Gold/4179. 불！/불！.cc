#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

string miro[1004];
bool flag[1004][1004];

queue<pair<int, int>> q;
queue<pair<int, int>> fire;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> miro[i];
	bfs();
	return 0;
}

void bfs(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(miro[i][j] == 'J'){
				q.push({i,j});
				flag[i][j] = true;
			}
			if(miro[i][j] == 'F'){
				fire.push({i,j});
				flag[i][j] = true;
			}
		}
	while(!q.empty()){
		int qsize = q.size(), fsize = fire.size();
		cnt++;
		while(fsize--){
			int y = fire.front().first, x = fire.front().second;
			fire.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx] || miro[ny][nx] == '#') continue;
				fire.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
		while(qsize--){
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m){
					cout << cnt;
					return;
				}
				if(flag[ny][nx] || miro[ny][nx] == '#') continue;
				q.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
	}
	cout << "IMPOSSIBLE";
}