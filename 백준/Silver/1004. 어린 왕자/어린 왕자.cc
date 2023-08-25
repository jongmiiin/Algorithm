#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y;
};

struct circle{
	int cx, cy, r;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		Point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		int n, cnt = 0;
		cin >> n;
		while(n--){
			circle c;
			cin >> c.cx >> c.cy >> c.r;
			c.r *= c.r;
			int ca = pow(c.cx-a.x, 2)+pow(c.cy-a.y, 2);
			int cb = pow(c.cx-b.x, 2)+pow(c.cy-b.y, 2);
			if(ca<c.r && cb<c.r) continue;
			else if(ca<c.r || cb<c.r) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}