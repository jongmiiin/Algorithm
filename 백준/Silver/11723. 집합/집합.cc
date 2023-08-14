#include <bits/stdc++.h>

using namespace std;

bool flag[24];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		int t;
		cin >> s;
		if(s == "add"){
			cin >> t;
			flag[t] = true;
		}
		else if(s == "remove"){
			cin >> t;
			flag[t] = false;
		}
		else if(s == "check"){
			cin >> t;
			cout << (flag[t]?1:0) << '\n';
		}
		else if(s == "toggle"){
			cin >> t;
			if(flag[t]) flag[t] = false;
			else flag[t] = true;
		}
		else if(s == "all") memset(flag, true, sizeof(flag));
		else if(s == "empty") memset(flag, false, sizeof(flag));
	}
	return 0;
}