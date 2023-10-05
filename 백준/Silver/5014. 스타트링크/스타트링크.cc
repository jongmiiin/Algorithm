#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;

bool flag[1000004];

void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	bfs();
	return 0;
}

void bfs(){
	int cnt = 0;
	queue<int> q;
	q.push(s);
	flag[s] = true;
	vector<int> dx = {u, -d};
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x = q.front();
			if(x == g){
				cout << cnt;
				return;
			}
			q.pop();
			for(int i=0;i<2;i++){
				int nx = x+dx[i];
				if(nx<1 || nx>f || flag[nx]) continue;
				q.push(nx);
				flag[nx] = true;
			}
		}
		cnt++;
	}
	cout << "use the stairs";
	return;
}