#include <bits/stdc++.h>

using namespace std;

int build[54];

struct Point{
	int x, y;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> build[i];
	for(int i=1;i<=n;i++){
		int lcnt = 0, rcnt = 0;
		double ex_gradient = (double)1e9;
		Point center;
		center.x = i; center.y = build[i];
		for(int j=i-1;j>=1;j--){
			Point comp;
			comp.x = j; comp.y = build[j];
			double gradient = (double)(center.y - comp.y)/(center.x - comp.x);
			if(gradient<ex_gradient){
				ex_gradient = gradient;
				lcnt++;
			}
			else continue;
		}
		ex_gradient = 1e9;
		for(int j=i+1;j<=n;j++){
			Point comp;
			comp.x = j; comp.y = build[j];
			double gradient = (double)(comp.y - center.y)/(comp.x - center.x);
			if(gradient<=ex_gradient && ex_gradient != 1e9) continue;
			else{
				ex_gradient = gradient;
				rcnt++;
			}
		}
		ans = max(ans, lcnt+rcnt);
	}
	cout << ans;
	return 0;
}