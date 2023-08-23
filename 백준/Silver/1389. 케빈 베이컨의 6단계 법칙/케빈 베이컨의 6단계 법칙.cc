#include <bits/stdc++.h>

using namespace std;

int n, m, ans, mn = 1e9;
int fri[104][104];

void init();
void floyd();
int sum(int y);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	init();
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		fri[a][b] = 1;
		fri[b][a] = 1;
	}
	floyd();
	for(int i=1;i<=n;i++){
		int t = sum(i);
		if(mn>t){
			mn = t;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}

void init(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(fri[i][j] == 0 && i != j) fri[i][j] = 1e9;
}

void floyd(){
	for (int mid = 1; mid <= n; mid++)
		for (int start = 1; start <= n; start++)
			for (int end = 1; end <= n; end++) {
				if (fri[start][mid] == 1e9 || fri[mid][end] == 1e9) continue;
				fri[start][end] = min(fri[start][end], fri[start][mid] + fri[mid][end]);
			}
}

int sum(int y){
	int num = 0;
	for(int i=1;i<=n;i++)
		if(fri[y][i] != 1e9) num += fri[y][i];
	return num;
}