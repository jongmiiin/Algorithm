#include <bits/stdc++.h>

using namespace std;

int l, n, m;

string build[34][34];
bool flag[34][34][34];

struct Point{
	int z, y, x;
};

int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};

void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin >> l >> n >> m;
		if(l == 0 && n == 0 && m == 0) break;
		for(int i=0;i<l;i++)
			for(int j=0;j<n;j++)
				cin >> build[i][j];
		bfs();
		memset(flag, false, sizeof(flag));
	}
	return 0;
}

void bfs(){
	int cnt = 0;
	Point end;
	queue<Point> q;
	for(int i=0;i<l;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				if(build[i][j][k] == 'S'){
					q.push({i, j, k});
					flag[i][j][k] = true;
				}
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int z = q.front().z, y = q.front().y, x = q.front().x;
			if(build[z][y][x] == 'E'){
				cout << "Escaped in " << cnt << " minute(s).\n";
				return;
			}
			q.pop();
			for(int i=0;i<6;i++){
				int nz = z+dz[i], ny = y+dy[i], nx = x+dx[i];
				if(nz<0 || nz>=l || ny<0 || ny>=n || nx<0 || nx>=m || flag[nz][ny][nx] || build[nz][ny][nx] == '#')
					continue;
				q.push({nz, ny, nx});
				flag[nz][ny][nx] = true;
			}
		}
		cnt++;
	}
	cout << "Trapped!\n";
    return;
}