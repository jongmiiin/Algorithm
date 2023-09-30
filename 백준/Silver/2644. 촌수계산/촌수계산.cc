#include <bits/stdc++.h>

using namespace std;

int family[104][104];
bool flag[104][104];

int bfs(int a, int b, int n);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b, t;
	cin >> n >> a >> b >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		family[x][y]++;
		family[y][x]++;
	}
	cout << bfs(a, b, n);
	return 0;
}

int bfs(int a, int b, int n){
	int cnt = 0;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(family[a][i]){
			q.push(i);
			flag[a][i] = true;
		}
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			int now = q.front();
			if(now == b) return cnt;
			q.pop();
			for(int i=1;i<=n;i++)
				if(family[now][i] && !flag[now][i]){
					q.push(i);
					flag[now][i] = true;
				}
		}
	}
	return -1;
}