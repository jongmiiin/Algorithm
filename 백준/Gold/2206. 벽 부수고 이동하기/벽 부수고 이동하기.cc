#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;
bool check;

int arr[1004][1004];
bool flag[3][1004][1004];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs();

struct Point{
	int y, x;
	int chance = 0;
	Point(int y, int x, int chance) : y(y), x(x), chance(chance) {}
};

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d", &arr[i][j]);
	bfs();
	if(!check) cout << -1;
	else cout << cnt;
	return 0;
}

void bfs(){
	queue<Point> q;
	q.push(Point(0, 0, 0));
	flag[0][0][0] = true;
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			int chance = q.front().chance;
			int y = q.front().y, x = q.front().x;
			if(y == n-1 && x == m-1){
				check = true;
				return;
			}
			q.pop();
			for(int i=0;i<4;i++){
				int ny = y+dy[i], nx = x+dx[i];
				if(ny<0 || ny>=n || nx<0 || nx>=m || flag[chance][ny][nx]) continue;
				if(arr[ny][nx] == 0){
					flag[chance][ny][nx] = true;
					q.push(Point(ny, nx, chance));
				}
				if(arr[ny][nx] == 1 && chance == 0){
					flag[chance+1][ny][nx] = true;
					q.push(Point(ny, nx, chance+1));
				}
			}
		}
	}
}