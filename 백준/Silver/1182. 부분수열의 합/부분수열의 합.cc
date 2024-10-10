#include <bits/stdc++.h>

using namespace std;

int n, s, sum, cnt, ans;
int arr[24];
void f(int idx, int lev, int mx_lev);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=1;i<=n;i++){
		f(0, 0, i);
		sum = 0;
	}
	cout << ans;
	return 0;
}

void f(int idx, int lev, int mx_lev){
	if(lev == mx_lev){
		if(cnt && sum == s) ans++;
		return;
		}
	for(int i=idx;i<n;i++){
		sum += arr[i];
		cnt++;
		f(i+1, lev+1, mx_lev);
		sum -= arr[i];
		cnt--;
	} 
}