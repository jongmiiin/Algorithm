 #include <bits/stdc++.h>
 
 using namespace std;

 int parent[500004];
 int p_rank[500004];
 
void make_set(int u);
void union_set(int u, int v);
int find_set(int u);

 int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);
 	int n, m, cnt = 0;;
 	cin >> n >> m;
 	for(int i=0;i<n;i++)
 		make_set(i);
 	for(int i=0;i<m;i++){
 		int a, b;
 		cin >> a >> b;
 		cnt++;
 		if(find_set(a) == find_set(b)){
 			cout << cnt;
 			return 0;
 		}
 		union_set(a, b);
 	}
 	cout << 0;
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