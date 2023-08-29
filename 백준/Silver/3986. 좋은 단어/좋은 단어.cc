#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, cnt = 0;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> stk;
		stk.push(s[0]);
		for(int i=1;i<s.size();i++){
			if(!stk.empty() && s[i] == stk.top()) stk.pop();
			else stk.push(s[i]);
		}
		if(stk.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}