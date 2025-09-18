#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int ans = n*m;
	vector<string> s(n);
	for(int i=0;i<n;i++)
		cin >> s[i];
	vector<string> ans_s(k, string(k, 'A'));
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			vector<int> cnt(26, 0);
			for(int ii=i;ii<n;ii+=k)
				for(int jj=j;jj<m;jj+=k)
					cnt[s[ii][jj]-'A']++;
			int mx = 0, idx = 0;
			for(int kk=0;kk<26;kk++){
				if(cnt[kk]>mx){
					mx = cnt[kk];
					idx = kk;
				}
			}
			ans -= mx;
			ans_s[i][j] = char(idx+'A');
		}
	}
	cout << ans << '\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout << ans_s[i%k][j%k];
		cout << '\n';
	}
	return 0;
}