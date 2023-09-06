#include <bits/stdc++.h>

using namespace std;

bool check[204][204];

int parent[204];
int p_rank[204];

void make_set(int u);
void union_set(int u, int v);
int find_set(int u);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, ex, now;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		make_set(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int t;
			cin >> t;
			if(t == 1 && !check[i][j]){
				check[i][j] = true;
				check[j][i] = true;
				union_set(i, j);
			}
		}
	bool flag = false;
	for(int i=0;i<m;i++){
		if(i==0) cin >> ex;
		else{
			cin >> now;
			if(find_set(ex) != find_set(now)) flag = true;
			ex = now;
		}
	}
	cout << (flag?"NO":"YES");
	return 0;
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
	if(u!=parent[u]) return find_set(parent[u]);
	return parent[u];
}