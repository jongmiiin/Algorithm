#include <bits/stdc++.h>

using namespace std;

int road[104][104];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> c;
		if(road[a][b]==0) road[a][b] = c;
		else road[a][b] = min(road[a][b], c);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j && road[i][j]==0) road[i][j] = 1e9;
	for(int mid=1;mid<=n;mid++){
		for(int start=1;start<=n;start++){
			for(int end=1;end<=n;end++){
				if(road[start][mid] == 1e9 || road[mid][end] == 1e9) continue;
				road[start][end] = min(road[start][end], road[start][mid]+road[mid][end]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout << (road[i][j]!=1e9?road[i][j]:0) << " ";
		cout << '\n';
	}
	return 0;
}