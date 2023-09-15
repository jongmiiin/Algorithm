#include <bits/stdc++.h>

using namespace std;

int parent[54];
int p_rank[54];

void make_set(int u);
void union_set(int u, int v);
int find_set(int u);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, known, ex, now, true_person, ans = 0;
	cin >> n >> m >> known;
	for(int i=1;i<=50;i++)
		make_set(i);
	for(int i=0;i<known;i++){
		if(i==0){
			cin >> ex;
			true_person = ex;
		}
		else{
			cin >> now;
			union_set(ex, now);
			ex = now;
		}
	}
	vector<vector<int>> v;
	for(int i=0;i<m;i++){
		int t;
		cin >> t;
		vector<int> vv;
		for(int j=0;j<t;j++){
			if(j==0){
				cin >> ex;
				vv.push_back(ex);
			}
			else{
				cin >> now;
				vv.push_back(now);
				union_set(ex, now);
				ex = now;
			}
		}
		v.push_back(vv);
	}
	if(known) true_person = find_set(true_person);
	for(int i=0;i<v.size();i++){
		if(!v[i].empty() && find_set(v[i][0]) != true_person) ans++;
	}
	cout << ans;
	return 0;
}

void make_set(int u){
	parent[u] = u;
	p_rank[u] = 0;
}

void union_set(int u, int v){
	int u_root = find_set(u);
	int v_root = find_set(v);
	if(p_rank[u_root]<p_rank[v_root]) parent[u_root] = v_root;
	else{
		parent[v_root] = u_root;
		if(p_rank[u_root] == p_rank[v_root]) p_rank[u_root]++;
	}
}

int find_set(int u){
	if(u != parent[u]) return find_set(parent[u]);
	return parent[u];
}