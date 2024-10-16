#include <bits/stdc++.h>

using namespace std;

string s;
int slen, ans;
bool check[14];
char str[14];
void rec(int lev);
int fac(int n);
int alp[34];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	slen = s.size();
	if(slen <= 2){
		if(slen == 2 && s[0] == s[1]) cout << 0;
		else cout << slen;
		return 0;
	}
	for(int i=0;i<slen;i++)
		alp[s[i]-'a']++;
	rec(0);
	for(int i=0;i<26;i++)
		if(alp[i]>1) ans/=fac(alp[i]);
	cout << ans;
	return 0;
}

void rec(int lev){
	if(lev == slen){
		bool flag = true;
		for(int i=0;i<slen;i++){
			if(i==0 || i==slen-1) continue;
			if(str[i] == str[i-1] || str[i] == str[i+1]) flag = false;
		}
		if(flag) ans++;
		return;
	}
	for(int i=0;i<slen;i++){
		if(check[i]) continue;
		check[i] = true;
		str[lev] = s[i];
		rec(lev+1);
		check[i] = false;
	}
}

int fac(int n){
	int num = n;
	for(int i=n-1;i>=1;i--)
		num*=i;
	return num;
}