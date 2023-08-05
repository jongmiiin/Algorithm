#include <bits/stdc++.h>

using namespace std;

int a[104][104];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<4;i++){
		int l_x, l_y, r_x, r_y;
		cin >> l_x >> l_y >> r_x >> r_y;
		for(int j=l_x;j<r_x;j++)
			for(int k=l_y;k<r_y;k++)
				a[j][k]++;
	}
	int cnt = 0;
	for(int i=1;i<101;i++)
		for(int j=1;j<101;j++)
			if(a[i][j]) cnt++;
	cout << cnt;
	return 0;
}