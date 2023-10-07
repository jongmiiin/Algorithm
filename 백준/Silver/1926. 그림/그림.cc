#include <bits/stdc++.h>

using namespace std;

int n, m, t, cnt, area;
int pic[504][504];
bool flag[504][504];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int dfs(int y, int x);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> pic[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(pic[i][j] && !flag[i][j]){
				t = 1;
				area = max(area, dfs(i, j));
				cnt++;
			}
	cout << cnt << '\n' << area;
	return 0;
}

int dfs(int y, int x){
	flag[y][x] = true;
	for(int i=0;i<4;i++){
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx] || pic[ny][nx] == 0) continue;
		t++;
		dfs(ny, nx);
	}
	return t;
}