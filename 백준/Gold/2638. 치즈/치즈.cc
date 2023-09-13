#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, cheese_cnt;
int	cheese[104][104];
bool flag[104][104];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

queue<pair<int, int>> q;
queue<pair<int, int>> melt;
void bfs();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin >> cheese[i][j];
			if(cheese[i][j] == 1) cheese_cnt++;
		}
	q.push({0, 0});
	flag[0][0] = true;
	while(cheese_cnt){
		bfs();
		cnt++;
	}
	cout << cnt;
	return 0;
}

void bfs(){
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		flag[y][x] = true;
		q.pop();
		for(int i=0;i<4;i++){
			int ny = y+dy[i], nx = x+dx[i];
			if(ny<0 || ny>=n || nx<0 || nx>=m || flag[ny][nx]) continue;
			if(cheese[ny][nx] == 0){
				q.push({ny, nx});
				flag[ny][nx] = true;
			}
			else if(cheese[ny][nx] == 1){
				cheese[ny][nx]++;
			}
			else if(cheese[ny][nx] == 2){
				melt.push({ny, nx});
				flag[ny][nx] = true;
			}
		}
	}
	while(!melt.empty()){
		int y = melt.front().first, x = melt.front().second;
		melt.pop();
		cheese[y][x] = 0;
		cheese_cnt--;
		q.push({y, x});
	}
}