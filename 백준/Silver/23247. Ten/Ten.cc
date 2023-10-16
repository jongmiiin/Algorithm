#include <bits/stdc++.h>

using namespace std;

int a[333][333];
int n, m;

int a_sum(int sy, int sx, int size_y, int size_x) {
	int result = 0;
	for (int i = 0; i <= size_y; i++) {
		for (int j = 0; j <= size_x; j++) {
			if (sy + i >= n) return 0;
			if (sx + j >= m) return 0;
			result += a[sy+i][sx+j];
		}
	}
	
	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if ((k+1) * (l+1) > 10) break;
					if(a_sum(i, j, k, l) == 10) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}