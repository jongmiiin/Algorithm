#include <bits/stdc++.h>

using namespace std;

int place[24][24];
bool flag[24][24];
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int win_rock, win_x, win_y;

void dfs(int x, int y, int rock, int cnt, int way, int start_x, int start_y);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<20;i++)
		for(int j=1;j<20;j++)
			cin >> place[i][j];
	for(int y=1;y<20;y++)
		for(int x=1;x<20;x++)
			if((place[y][x] == 1 || place[y][x] == 2) && !flag[y][x]){
				flag[y][x] = true;
				dfs(x, y, place[y][x], 1, 0, x, y);	
			}
	if(win_rock == 0) cout << win_rock;
	else cout << win_rock << '\n' << win_y << " " << win_x;
	return 0;
}

void dfs(int x, int y, int rock, int cnt, int way, int start_x, int start_y){
	if(cnt>1 && cnt<5){
		int nx = x + dx[way], ny = y + dy[way];
		if(nx>0 && nx<20 && ny>0 && ny<20 && !flag[ny][nx] && place[ny][nx] == rock)
			dfs(nx, ny, rock, cnt+1, way, start_x, start_y);
	}
	else if(cnt == 5){
		int nx = x + dx[way], ny = y + dy[way];
		if(!flag[ny][nx]){
			if(place[ny][nx] != rock){
				if(x<start_x){
					win_x = x; win_y = y;
				}
				else{
					win_x = start_x; win_y = start_y;
				}
				win_rock = rock; 
			}
			else return;
		}
	}
	else{
		for(int i=0;i<8;i++){
			int nx = x + dx[i], ny = y + dy[i];
			int ex = x - dx[i], ey = y - dy[i];
			if(nx>0 && nx<20 && ny>0 && ny<20 && !flag[ny][nx] && place[ny][nx] == rock){
				if(flag[ey][ex] && place[ey][ex] == rock) return;
				dfs(nx, ny, rock, cnt+1, i, start_x, start_y);
			}
		}
	}
}