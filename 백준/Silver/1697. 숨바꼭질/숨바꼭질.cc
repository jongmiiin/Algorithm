#include <bits/stdc++.h>

using namespace std;

#define MAXNUM 100000

int cnt = 1, ans = 987654321;
int flag[100004];
int dx[] = {1, -1, 0};
void bfs(int n, int k);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	if(n == k){
		cout << 0;
		return 0;
	}
	bfs(n, k);
	cout << ans;
	return 0;
}

void bfs(int n, int k){
	queue<int> q;
	q.push(n);
	flag[n] = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x = q.front();
			dx[2] = x;
			q.pop();
			for(int i=0;i<3;i++){
				int nx = x + dx[i];
				if(nx<0 || nx>MAXNUM || flag[nx]) continue;
				if(nx == k && cnt<ans){
					ans = cnt;
					return;
				}
				flag[nx] = true;
				q.push(nx);
			}
		}
		cnt++;
	}
}