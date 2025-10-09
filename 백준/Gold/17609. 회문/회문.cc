#include <bits/stdc++.h>

using namespace std;

int is_palind(string s){
	int l=0, r=s.size()-1;
	bool pseudo = false;
	while(l<=r){
		if(s[l]==s[r]){
			l++; r--;
		}
		else{
			bool l_flag = false, r_flag = false;
			if(s[l+1]==s[r] || s[l]==s[r-1]){
				int st=l+1, en=r;
				while(st<=en){
					if(s[st]==s[en]){
						st++; en--;
					}
					else{
						l_flag = true;
						break;
					}
				}
				st=l; en=r-1;
				while(st<=en){
					if(s[st]==s[en]){
						st++; en--;
					}
					else{
						r_flag = true;
						break;
					}
				}
				if(l_flag && r_flag) return 2;
				else return 1;
			}
			else return 2;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << is_palind(s) << '\n';
	}
	return 0;
}