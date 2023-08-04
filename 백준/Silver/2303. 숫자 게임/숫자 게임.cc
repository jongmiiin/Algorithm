#include <bits/stdc++.h>

using namespace std;

int person[1004][14];
int mx_num[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans, mx = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			cin >> person[i][j];
	for(int i=0;i<n;i++){
		mx = 0;
		for(int j=0;j<3;j++){
			for(int k=j+1;k<4;k++){
				for(int l=k+1;l<5;l++){
					int t = person[i][j] + person[i][k] + person[i][l];
					t%=10;
					if(t>mx) mx = t;
				}
			}
		}
		mx_num[i] = mx;
	}
	mx = 0;
	for(int i=0;i<n;i++)
		if(mx_num[i]>=mx){
			mx = mx_num[i];
			ans = i+1;
		}
	cout << ans;
	return 0;
}