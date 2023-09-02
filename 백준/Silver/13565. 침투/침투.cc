#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[1004][1004];
bool flag[1004][1004];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int y, int x);

int main(){
	cin >> m >> n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%1d", &a[i][j]);
	for(int i=0;i<n;i++)
		if(a[0][i] == 0 && !flag[0][i]) bfs(0, i);
	bool is_trans = false;
	for(int i=0;i<n;i++)
		if(flag[m-1][i]) is_trans = true;
	cout << (is_trans?"YES":"NO");
	return 0;
}

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	flag[y][x] = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=m || nx<0 || nx>=n || flag[ny][nx] || a[ny][nx]) continue;
				flag[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
}