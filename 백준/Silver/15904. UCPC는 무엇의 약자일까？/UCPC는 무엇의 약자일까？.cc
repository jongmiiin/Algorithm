#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	int slen = s.length();
	if(s.find('U') != string::npos){
		int t1 = s.find('U');
		if(s.find('C', t1) != string::npos){
			int t2 = s.find('C', t1);
			if(s.find('P', t2) != string::npos){
				int t3 = s.find('P', t2);
				if(s.find('C', t3) != string::npos){
					cout << "I love UCPC";
					return 0;
				}
			}
		}
	}
	cout << "I hate UCPC";
	return 0;
}