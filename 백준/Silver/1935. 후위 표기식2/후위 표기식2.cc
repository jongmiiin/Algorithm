#include <bits/stdc++.h>

using namespace std;

int alpa[34];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0;i<n;i++)
		cin >> alpa[i];
	stack<double> stk;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A' && s[i]<='Z') stk.push(alpa[s[i]-65]);
		else{
			double b = stk.top();
			stk.pop();
			double a = stk.top();
			stk.pop();
			if(s[i] == '+') stk.push(a+b);
			if(s[i] == '-') stk.push(a-b);
			if(s[i] == '*') stk.push(a*b);
			if(s[i] == '/') stk.push(a/b);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stk.top() << endl;
	return 0;
}