#include <bits/stdc++.h>

using namespace std;

int n, m, ex, now;
int city[204][204];
void floyd();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> city[i][j];
			if(city[i][j] == 0 && i != j) city[i][j] = 1e9;
			if(i==j) city[i][j] = 1;
		}
	floyd();
	bool flag = false;
	for(int i=0;i<m;i++){
		if(i==0) cin >> ex;
		else{
			cin >> now;
			if(city[ex][now] == 1e9) flag = true;
			ex = now;
		}
	}
	cout << (flag?"NO":"YES");
	return 0;
}

void floyd(){
	for(int mid=1;mid<=n;mid++)
		for(int start=1;start<=n;start++)
			for(int end=1;end<=n;end++){
				if(city[start][mid] == 1e9 || city[mid][end] == 1e9) continue;
				city[start][end] = min(city[start][end], city[start][mid]+city[mid][end]);
			}
}