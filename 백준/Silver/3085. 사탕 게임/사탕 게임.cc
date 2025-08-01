#include <bits/stdc++.h>

using namespace std;

int n;
char board[54][54];

void swap(int ay, int ax, int by, int bx){
	int t = board[ay][ax];
	board[ay][ax] = board[by][bx];
	board[by][bx] = t;
}

int col_count(int y, int x){
	int cnt = 1;
	for(int i=y+1;i<n;i++){
		if(board[y][x] == board[i][x]) cnt++;
		else break;
	}
	for(int i=y-1;i>=0;i--){
		if(board[y][x] == board[i][x]) cnt++;
		else break;
	}
	return cnt;
}

int row_count(int y, int x){
	int cnt = 1;
	for(int i=x+1;i<n;i++){
		if(board[y][x] == board[y][i]) cnt++;
		else break;
	}
	for(int i=x-1;i>=0;i--){
		if(board[y][x] == board[y][i]) cnt++;
		else break;
	}
	return cnt;
}

int candy_count(int y, int x){
	int ret = 0;
	if(y+1<n){
		if(board[y][x]!=board[y+1][x]) swap(y, x, y+1, x);
		ret = max(ret, max(col_count(y, x), row_count(y, x)));
		ret = max(ret, max(col_count(y+1, x), row_count(y+1, x)));
		if(board[y][x]!=board[y+1][x]) swap(y, x, y+1, x);
	}
	if(x+1<n){
		if(board[y][x]!=board[y][x+1]) swap(y, x, y, x+1);
		ret = max(ret, max(col_count(y, x), row_count(y, x)));
		ret = max(ret, max(col_count(y, x+1), row_count(y, x+1)));
		if(board[y][x]!=board[y][x+1]) swap(y, x, y, x+1);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> board[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans = max(ans, candy_count(i, j));
	cout << ans;
	return 0;
}