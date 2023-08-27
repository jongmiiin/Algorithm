#include <bits/stdc++.h>

using namespace std;

int n;
int a[104][104];

void floyd();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(a[i][j] == 0) a[i][j] = 1e9;
		}
	floyd();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] == 1e9) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << '\n';
	}
	return 0;
}

void floyd(){
	for(int mid=0;mid<n;mid++){
		for(int start=0;start<n;start++){
			for(int end=0;end<=n;end++){
				if(a[start][mid] == 1e9 || a[mid][end] == 1e9) continue;
				a[start][end] = min(a[start][end], a[start][mid]+a[mid][end]);
			}
		}
	}
}