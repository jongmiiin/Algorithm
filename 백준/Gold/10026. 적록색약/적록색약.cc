#include <bits/stdc++.h>

using namespace std;

char c[104][104];
bool flag[104][104];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(char color, int y, int x, int n);
void rgdfs(char color, int y, int x, int n, bool rgflag);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0, rgcnt = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> c[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!flag[i][j]){
				dfs(c[i][j], i, j, n);
				cnt++;
			}
		}
	}
	memset(flag, false, sizeof(flag));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!flag[i][j]){
				if(c[i][j] == 'R' || c[i][j] == 'G') rgdfs(c[i][j], i, j, n, true);
				else rgdfs(c[i][j], i, j, n, false);
				rgcnt++;
			}
		}
	}
	cout << cnt << " " << rgcnt;
	return 0;
}

void dfs(char color, int y, int x, int n){
	flag[y][x] = true;
	for(int i=0;i<4;i++){
		int ny = y + dy[i], nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || flag[ny][nx] || c[ny][nx] != color) continue;
		dfs(color, ny, nx, n);
	}
}

void rgdfs(char color, int y, int x, int n, bool rgflag){
	flag[y][x] = true;
	for(int i=0;i<4;i++){
		int ny = y + dy[i], nx = x + dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n || flag[ny][nx] 
			|| (rgflag && c[ny][nx] == 'B') || (!rgflag && (c[ny][nx] == 'R' || c[ny][nx] == 'G'))) continue;
		rgdfs(color, ny, nx, n, rgflag);
	}
}