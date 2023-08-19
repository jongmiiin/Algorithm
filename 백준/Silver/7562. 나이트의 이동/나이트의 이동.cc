#include <bits/stdc++.h>

using namespace std;

bool flag[304][304];

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void bfs(int l, int st_x, int st_y, int en_x, int en_y);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int l, st_x, st_y, en_x, en_y;
		cin >> l >> st_y >> st_x >> en_y >> en_x;
		memset(flag, false, sizeof(flag));
		bfs(l, st_y, st_x, en_y, en_x);
	}
	return 0;
}

 void bfs(int l, int st_x, int st_y, int en_x, int en_y){
 	int cnt = 0;
 	queue<pair<int, int>> q;
 	q.push({st_y, st_x});
 	flag[st_y][st_x] = true;
 	while(!q.empty()){
 		int size = q.size();
 		while(size--){
 			int y = q.front().first, x = q.front().second;
 			if(x == en_x && y == en_y){
 				cout << cnt << '\n';
 				return;
 			}
 			q.pop();
 			for(int i=0;i<8;i++){
 				int ny = y+dy[i], nx = x+dx[i];
 				if(ny<0 || ny>=l || nx<0 || nx>=l || flag[ny][nx]) continue;
 				flag[ny][nx] = true;
 				q.push({ny, nx});
 			}
 		}
 		cnt++;
 	}
 }