#include <bits/stdc++.h>

using namespace std;

int cnt;
void bin_search(vector<int>& v, int l,int r, int sum, int inx);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	cin >> m;
	sort(v.begin(), v.end());
	for(int i=0;i<n-1;i++)
		bin_search(v, i+1, n, m, i);
	cout << cnt;
	return 0;
}

void bin_search(vector<int>& v, int l,int r, int sum, int inx) {
	if (l > r) return;
	int mid = (l + r) / 2;
	int t = sum-v[inx];
	if(t<1) return;
	if (v[mid] == t) {
		cnt++;
		return;
	}
	if (v[mid] > t) bin_search(v, l, mid-1, sum, inx);
	else if (v[mid] < t) bin_search(v, mid+1, r, sum, inx);
}