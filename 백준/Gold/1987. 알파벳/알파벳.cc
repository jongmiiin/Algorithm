#include <bits/stdc++.h>

using namespace std;

int r, c, ans = 1;
char str[24][24];
bool alp[34];
int dp[24][24];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x){
	for(int i=0;i<4;i++){
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
		if(alp[str[ny][nx]-'A']) continue;
		dp[ny][nx] = dp[y][x]+1;
		ans = max(ans, dp[ny][nx]);
		alp[str[ny][nx]-'A'] = true;
		dfs(ny, nx);
		alp[str[ny][nx]-'A'] = false;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin >> str[i][j];
	alp[str[0][0]-'A'] = true;
	dp[0][0] = 1;
	dfs(0, 0);
	cout << ans;
	return 0;
}