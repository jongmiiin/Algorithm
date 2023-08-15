#include <bits/stdc++.h>

using namespace std;

int arr[24][24];
bool flag[24][24];
bool check = false;

int dx[] = {0, 1};
int dy[] = {1, 0};

int n, m, k, cnt, t = 1;
void dfs(int y, int x);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	if(k == 0) check = true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			arr[i][j] = t++;
	dfs(1, 1);
	cout << cnt;
	return 0;
}

void dfs(int y, int x){
	if(y == n && x == m && check) cnt++;
	else{
		for(int i=0;i<2;i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(ny<1 || ny>n || nx<1 || nx>m || flag[ny][nx]) continue;
			flag[ny][nx] = true;
			if(k != 0 && arr[ny][nx] == k) check = true;
			dfs(ny, nx);
			if(k != 0 && arr[ny][nx] == k) check = false;
			flag[ny][nx] = false;
		}
	}
}