#include <bits/stdc++.h>

using namespace std;

int arr[14], ans[14];
bool flag[14];

void f(int n, int m, int inx);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	sort(arr+1, arr+n+1);
	f(n, m, 1);
	return 0;
}

void f(int n, int m, int inx){
	if(inx == m+1){
		for(int i=1;i<=m;i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	else{
		int ex = 0;
		for(int i=1;i<=n;i++){
			if(!flag[i] && ex<arr[i] && ans[inx-1]<=arr[i]){
				ex = arr[i];
				flag[i] = true;
				ans[inx] = arr[i];
				f(n, m, inx+1);
				flag[i] = false;
				if(inx==1) ans[0] = arr[i];
			}
		}
	}
}