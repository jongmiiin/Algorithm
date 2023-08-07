#include <bits/stdc++.h>

using namespace std;

vector<string> v;
string ans;
bool flag = false, isans = true, only_st = false, only_en = false;

void search(string s);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	char st, en;
	cin >> n;
	if(n == 1){
		string s;
		cin >> s;
		cin >> m >> s;
		cout << s;
		return 0;
	}
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(s == "?"){
			flag = true;
			if(i == 0) only_en = true;
			else{
				st = v[i-1][v[i-1].size()-1];
				if(i == n-1) only_st = true;
			}
		}
		else{
			v.push_back(s);
			if(flag){
				flag = false;
				en = s[0];
			}
		}
	}
	cin >> m;
	for(int i=0;i<m;i++){
		string s;
		cin >> s;
		if(only_st && s[0] == st) search(s);
		else if(only_en && s[s.size()-1] == en) search(s);
		else if(s[0] == st && s[s.size()-1] == en) search(s);
	}
	cout << ans;
	return 0;
}

void search(string s){
	for(int j=0;j<v.size();j++)
		if(s == v[j]) isans = false;
	if(isans) ans = s;
	isans = true;
}