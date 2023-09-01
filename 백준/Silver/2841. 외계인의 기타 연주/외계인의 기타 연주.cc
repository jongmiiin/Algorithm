#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, cnt = 0;
	cin >> n >> p;
	stack<int> s[8];
	for(int i=0;i<n;i++){
		int t, f;
		cin >> t >> f;
		if(s[t].empty() || s[t].top()<f){
			s[t].push(f);
			cnt++;
		}
		else{
			while(!s[t].empty() && s[t].top()>f){
				s[t].pop();
				cnt++;
			}
			if(s[t].empty() || s[t].top()<f){
				s[t].push(f);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}