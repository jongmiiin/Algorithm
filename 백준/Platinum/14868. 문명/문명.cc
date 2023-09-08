#include <bits/stdc++.h>

using namespace std;


int n, k, cnt;
int arr[2004][2004];
int parent[100004];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int>> m_check;
queue<pair<int, int>> m_spread;

void marge_set(int u, int v);
void union_set(int u, int v);
int find_set(int u);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i=1;i<=k;i++){
		int x, y;
		cin >> x >> y;
		parent[i] = i;
		arr[y][x] = i;
		m_check.push({y,x});
	}
	while(k>1){
		while(!m_check.empty()){
			int y = m_check.front().first, x = m_check.front().second;
			m_check.pop();
			m_spread.push({y, x});
			int find_set_num = find_set(arr[y][x]);
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<1 || ny>n || nx<1 || nx>n || arr[ny][nx]==0) continue;
				if(find_set(arr[ny][nx]) == find_set_num) continue;
				union_set(arr[y][x], arr[ny][nx]);
				k--;
				if(k==1){
					cout << cnt;
					return 0;
				}
			}
		}
		while(!m_spread.empty()){
			int y = m_spread.front().first, x = m_spread.front().second;
			m_spread.pop();
			int find_set_num = find_set(arr[y][x]);
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<1 || ny>n || nx<1 || nx>n || arr[ny][nx] != 0) continue;
				arr[ny][nx] = arr[y][x];
				marge_set(arr[ny][nx], find_set_num);
				m_check.push({ny,nx});
			}
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}

void marge_set(int u, int v){
	parent[u] = v;
}

void union_set(int u, int v){
	int u_root = find_set(u);
	int v_root = find_set(v);
	if(u_root!=v_root) parent[v_root] = u_root;

}

int find_set(int u){
	if(u!=parent[u]) return find_set(parent[u]);
	return parent[u];
}