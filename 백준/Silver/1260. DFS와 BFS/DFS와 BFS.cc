#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &arr, vector<bool> &check, int v);
void bfs(vector<vector<int>> &arr, vector<bool> &check, int v);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> arr(n+1);
	vector<bool> check(n+1, false);
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!arr[i].empty()) sort(arr[i].begin(), arr[i].end());
	}
	check[v] = true;
	dfs(arr, check, v);
	cout << "\n";
	fill(check.begin(), check.end(), false);
	bfs(arr, check, v);
	return 0;
}

void dfs(vector<vector<int>> &arr, vector<bool> &check, int v){
	cout << v << " ";
	for(int i=0;i<arr[v].size();i++){
		if(!check[arr[v][i]]){
			check[arr[v][i]] = true;
			dfs(arr, check, arr[v][i]);
		}
	}
	return;
}

void bfs(vector<vector<int>> &arr, vector<bool> &check, int v){
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		cout << now << " ";
		check[now] = true;
		for(int i=0;i<arr[now].size();i++){
			if(!check[arr[now][i]]){
				q.push(arr[now][i]);
				check[arr[now][i]] = true;
			}
		}
	}
	return;
}