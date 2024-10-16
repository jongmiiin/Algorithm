#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int ans = 0;
	do{
		char ex = s[0];
		bool flag = true;
		for (int i=1;i<s.size();i++){
			if(s[i] == ex) flag = false;
			ex = s[i];
		}
		if (flag) ans++;
	}while(next_permutation(s.begin(), s.end()));
	cout << ans;
	return 0;
}