#include <bits/stdc++.h>

using namespace std;

int arr[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, row_mn = 1004, row_mx = 0, col_mx = 0, col_mx_inx = 0, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		int l, h;
		cin >> l >> h;
		if(l<row_mn) row_mn = l;
		if(l>row_mx) row_mx = l;
		if(h>col_mx){
			col_mx = h;
			col_mx_inx = l;
		}
		arr[l] = h;
	}
	int inx = 0, now_mx = 0;
	while(inx<=col_mx_inx){
		if(now_mx<arr[inx]) now_mx = arr[inx];
		ans += now_mx;
		inx++;
	}
	inx = row_mx; now_mx = 0;
	while(col_mx_inx<inx){
		if(now_mx<arr[inx]) now_mx = arr[inx];
		ans += now_mx;
		inx--;
	}
	cout << ans;
	return 0;
}