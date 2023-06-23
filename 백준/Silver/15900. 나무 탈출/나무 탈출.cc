#include <bits/stdc++.h>

using namespace std;

int sum;
void dfs(vector<vector<int>>& tree, vector<bool>& visit, int n, int cnt);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> tree(n+1, vector<int>());
	vector<bool> visit(n+1, false);
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	visit[1] = true;
	for(int i=0;i<tree[1].size();i++){
		int t = tree[1][i];
		visit[t] = true;
		dfs(tree, visit, t, 0);
	}
	cout << ((sum%2 == 1)?"Yes":"No");
	return 0;
}

void dfs(vector<vector<int>>& tree, vector<bool>& visit, int n, int cnt){
	bool flag = true;
	cnt++;
	for(int i=0;i<tree[n].size();i++){
		int t = tree[n][i];
		if(visit[t]) continue;
		flag = false;
		visit[t] = true;
		dfs(tree, visit, t, cnt);
	}
	if(flag) sum += cnt;
}