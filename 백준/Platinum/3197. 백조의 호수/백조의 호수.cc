#include <bits/stdc++.h>

using namespace std;

int n, m, num = 1, ans = 0;
char lake[1504][1504];
int lake_num[1504][1504];

int parent[2250001];
int p_rank[2250001];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

queue<pair<int, int>> q;
queue<pair<int, int>> x_change;

void merge_bfs();
void change();

void make_set(int u);
void union_set(int u, int v);
int find_set(int u);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int, int>> L;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin >> lake[i][j];
			if(lake[i][j]=='L') L.push_back({i,j});
			lake_num[i][j] = num;
			make_set(num++);
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(lake[i][j] == '.' || lake[i][j] == 'L'){
				q.push({i, j});
				merge_bfs();
			}
	while(1){
		change();
		ans++;
		if(find_set(lake_num[L[0].first][L[0].second]) == find_set(lake_num[L[1].first][L[1].second])){
			cout << ans;
			return 0;
		}
		merge_bfs();
	}
	return 0;
}

void merge_bfs(){
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();
		int t = find_set(lake_num[y][x]);
		for(int i=0;i<4;i++){
			int ny = y+dy[i], nx = x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
			if(find_set(lake_num[ny][nx]) == t) continue;
			if(lake[ny][nx] == '.' || lake[ny][nx] == 'L') q.push({ny, nx});
			if(lake[ny][nx] == 'X') x_change.push({ny, nx});
			union_set(lake_num[ny][nx], lake_num[y][x]);
		}
	}
	
}

void change(){
	while(!x_change.empty()){
		int y = x_change.front().first, x = x_change.front().second;
		lake[y][x] = '.';
		x_change.pop();
		int t = find_set(lake_num[y][x]);
		for(int i=0;i<4;i++){
			int ny = y+dy[i], nx = x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m || lake[ny][nx] == 'X') continue;
			if(find_set(lake_num[ny][nx]) == t) continue;
			if(lake[ny][nx] == '.') union_set(lake_num[ny][nx], lake_num[y][x]);
		}
		q.push({y, x});
	}
}

void make_set(int u){
	parent[u] = u;
	p_rank[u] = 0;
}

void union_set(int u, int v){
	int u_root = find_set(u);
	int v_root = find_set(v);
	if(p_rank[u_root]>p_rank[v_root]) parent[v_root] = u_root;
	else{
		parent[u_root] = v_root;
		if(p_rank[u_root] == p_rank[v_root]) p_rank[v_root]++;
	}
}

int find_set(int u){
	if(u!=parent[u]) return parent[u]=find_set(parent[u]);
	return parent[u];
}