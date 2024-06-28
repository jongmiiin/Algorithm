#include <bits/stdc++.h>

using namespace std;

void f(int n);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while(cin >> n){
		f(n);
		cout << '\n';
	}
	return 0;
}

void f(int n){
	if(n==0){
		cout << "-";
		return;
	}
	f(n-1);
	for(int i=0;i<pow(3,n-1);i++) cout << " ";
	f(n-1);
}