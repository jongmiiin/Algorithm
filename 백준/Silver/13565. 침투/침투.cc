#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[1004][1004];
bool flag[1004][1004];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x);

int main(){
	cin >> m >> n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%1d", &a[i][j]);
	for(int i=0;i<n;i++)
		if(a[0][i] == 0 && !flag[0][i]) dfs(0, i);
	bool is_trans = false;
	for(int i=0;i<n;i++)
		if(flag[m-1][i]) is_trans = true;
	cout << (is_trans?"YES":"NO");
	return 0;
}

void dfs(int y, int x){
	flag[y][x] = true;
	for(int i=0;i<4;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m || flag[ny][nx] || a[ny][nx]) continue;
		dfs(ny, nx);
	}
}