#include <bits/stdc++.h>

using namespace std;

int  m, n, k, cnt;
int arr[104][104];
bool flag[104][104];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	for(int i=0;i<k;i++){
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		for(int y=ly;y<ry;y++)
			for(int x=lx;x<rx;x++)
				arr[y][x]=1;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 0 && !flag[i][j]){
				dfs(i, j);
				pq.push(cnt);
				cnt = 0;
			}
		}
	}
	cout << pq.size() << '\n';
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}

void dfs(int y, int x){
	cnt++;
	flag[y][x] = true;
	for(int i=0;i<4;i++){
		int ny = y+dy[i], nx = x+dx[i];
		if(ny<0 || ny>=m || nx<0 || nx>=n || flag[ny][nx] || arr[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}