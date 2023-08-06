#include <bits/stdc++.h>

using namespace std;

int n, m;
int ice[304][304];
bool flag[304][304];
int change[304][304];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int time_cnt;
bool istwo, isice;

void change_cnt();
void icebreak();
void judge();
void dfs(int y, int x);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> ice[i][j];
	while(1){
		change_cnt();
		icebreak();
		judge();
		memset(flag, false, sizeof(flag));
		time_cnt++;
		if(!isice){
			cout << 0;
			return 0;
		}
		if(istwo){
			cout << time_cnt;
			return 0;
		}
		isice = false;
	}
	return 0;
}

void change_cnt(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ice[i][j]){
				int cnt = 0;
				for(int k=0;k<4;k++){
					int nx = j + dx[k], ny = i + dy[k];
					if(nx>=0 && nx<m && ny>=0 && ny<n && ice[ny][nx] == 0) cnt++;
				}
				change[i][j] += cnt;
			}
		}
	}
}

void icebreak(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(change[i][j] != 0){
				ice[i][j] -= change[i][j];
				if(ice[i][j] < 0) ice[i][j] = 0;
				change[i][j] = 0;
			}
		}
	}
}

void judge(){
	int con_cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ice[i][j] && !flag[i][j]){
				flag[i][j] = true;
				isice = true;
				dfs(i, j);
				con_cnt++;
			}
		}
	}
	if(con_cnt>=2) istwo = true;
}

void dfs(int y, int x){
	for(int i=0;i<4;i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx>=0 && nx<m && ny>=0 && ny<n && !flag[ny][nx] && ice[ny][nx] != 0){
			flag[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}