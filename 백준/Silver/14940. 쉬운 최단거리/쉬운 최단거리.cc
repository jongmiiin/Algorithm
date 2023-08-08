#include <bits/stdc++.h>

using namespace std;

int n, m;
int table[1004][1004];
bool vis[1004][1004];
int dist[1004][1004];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input();
void search();
void bfs(int i, int j);
void check();
void output();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	search();
	check();
	output();
	return 0;
}

void input(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> table[i][j];
}

void search(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(table[i][j] == 2){
				vis[i][j] = true;
				bfs(i, j);	
			}
}

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	int cnt = 1;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int y = q.front().first, x = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y + dy[i], nx = x + dx[i];
				if(ny>=n || ny<0 || nx>=m || nx<0 || vis[ny][nx] || !table[ny][nx]) continue;
				vis[ny][nx] = true;
				dist[ny][nx] = cnt;
				q.push({ny, nx});
			}
		}
		cnt++;
	}
}

void check(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(table[i][j] == 1 && !dist[i][j]) dist[i][j] = -1;
		}
}

void output(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout << dist[i][j] << " ";
		cout << endl;
	}
}