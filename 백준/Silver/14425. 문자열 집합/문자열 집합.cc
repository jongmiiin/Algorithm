#include <bits/stdc++.h>

using namespace std;

int bin_search(string s, vector<string>& in, int l, int r);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<string> s(n);
	vector<string> in(m);
	for(int i=0;i<n;i++)
		cin >> s[i];
	for(int i=0;i<m;i++)
		cin >> in[i];
	sort(s.begin(), s.end());
	for(int i=0;i<m;i++)
		cnt += bin_search(in[i], s, 0, n-1);
	cout << cnt;
	return 0;
}

int bin_search(string s, vector<string>& in, int l, int r){
	while(l<=r){
		int mid = (l+r)/2;
		if(in[mid] == s) return 1;
		else if(in[mid]<s) l = mid+1;
		else r = mid-1;
	}
	return 0;
}