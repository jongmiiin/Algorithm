#include <bits/stdc++.h>

using namespace std;

int sock[14];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=0;i<5;i++){
		int t;
		cin >> t;
		sock[t]++;
	}
	for(int i=0;i<10;i++)
		if(sock[i]) sock[i]%=2;
	for(int i=0;i<10;i++)
		if(sock[i]) cout << i;
	return 0;
}