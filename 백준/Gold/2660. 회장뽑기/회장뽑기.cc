#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>>& v, int st, int n);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> v;
	v.assign(n+1, vector<int>());
	while(1){
		int a, b;
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(v[i].begin(), v[i].end());
	vector<int> ans;
	int score_mn = n+1;
	for(int i=1;i<n+1;i++){
		int score = bfs(v, i, n);
		if(score == score_mn) ans.push_back(i);
		else if(score<score_mn){
			score_mn = score;
			ans.clear();
			ans.push_back(i);
		}
	}
	cout << score_mn << " " << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	return 0;
}

int bfs(vector<vector<int>>& v, int st, int n){
	int cnt = 0;
	queue<int> q;
	q.push(st);
	vector<bool> visited(n+1, false);
	visited[st] = true;
	while(!q.empty()){
		int size = q.size();
		bool flag = false;
		while(size--){
			int now = q.front();
			q.pop();
			for(int i=0;i<v[now].size();i++){
				if(!visited[v[now][i]]){
					q.push(v[now][i]);
					flag = true;
					visited[v[now][i]] = true;
				}
			}
		}
		if(flag) cnt++;
	}
	return cnt;
}