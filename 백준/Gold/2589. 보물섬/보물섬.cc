#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
string bomul[54];
bool flag[54][54];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs(int i, int j);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> bomul[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(bomul[i][j]=='L'){
				ans = max(bfs(i, j), ans);
				memset(flag, false, sizeof(flag));
			}
		}
	}
	cout << ans;
	return 0;
}

int bfs(int i, int j){
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({i, j});
	flag[i][j] = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx] || bomul[ny][nx]=='W') continue;
				q.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
		cnt++;
	}
	return cnt-1;
}