#include <bits/stdc++.h>

using namespace std;

int m, n, h, cnt = -1;
int box[104][104][104];
bool check[104][104][104];

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};

struct Point{
	int x, y, z;
};

void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> h;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				cin >> box[i][j][k];
	bfs();
	bool flag = false;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(box[i][j][k] == 0) flag = true;
	if(flag) cout << -1;
	else cout << cnt;
	return 0;
}

void bfs(){
	queue<Point> q;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(box[i][j][k] == 1){
					q.push({k, j, i});
					check[i][j][k] = true;
				}
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x = q.front().x, y = q.front().y, z = q.front().z;
			q.pop();
			for(int i=0;i<6;i++){
				int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
				if(nx<1 || nx>m || ny<1 || ny>n || nz<1 || nz>h || check[nz][ny][nx] || box[nz][ny][nx] != 0)
					continue;
				check[nz][ny][nx] = true;
				box[nz][ny][nx] = 1;
				q.push({nx, ny, nz});
			}
		}
		cnt++;
	}
}