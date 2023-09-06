#include <bits/stdc++.h>

using namespace std;

int parent[1000004];
int p_rank[1000004];

void make_set(int u);
void union_set(int u, int v);
int find_set(int u);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<=n;i++)
		make_set(i);
	for(int i=0;i<m;i++){
		int k, a, b;
		cin >> k >> a >> b;
		switch(k){
			case 0: union_set(a, b); break;
			case 1:
				if(find_set(a) == find_set(b)) cout << "YES" << '\n';
				else cout << "NO" << '\n';
				break;
		}
	}
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