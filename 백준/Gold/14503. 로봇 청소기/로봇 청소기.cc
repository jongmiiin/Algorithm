#include <bits/stdc++.h>

using namespace std;

int room[54][54];
bool is_clean[54][54];

int cnt;
int n, m, r, c, d;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int opposite_way(int way){
	if(way>=2) return way-2;
	else return way+2;
}

void dfs(int y, int x, int dir){
	if(room[y][x] == 0 && is_clean[y][x] == false){
		is_clean[y][x] = true;
		cnt++;
	}
	for(int i=dir-1, tmp_cnt = 0;tmp_cnt<4;i--, tmp_cnt++){
		i = (i+4)%4;
		int ny = y+dy[i], nx = x+dx[i];
		if(room[ny][nx]==1 || is_clean[ny][nx] == true) continue;
		dfs(ny, nx, i);
		return;
	}
	int tmp_way = opposite_way(dir);
	int ny = y+dy[tmp_way], nx = x+dx[tmp_way];
	if(room[ny][nx]==1) return;
	else{
		dfs(ny, nx, dir);
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r >> c >> d;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> room[i][j];
	dfs(r, c, d);
	cout << cnt;
	return 0;
}