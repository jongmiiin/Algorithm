#include <bits/stdc++.h>

using namespace std;

int f(int n);
int g(int n);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}

int f(int n){
	if(n==0) return 1;
	else if(n==1) return 0;
	return f(n-2)+2*g(n-1);
}

int g(int n){
	if(n==0) return 0;
	else if(n==1) return 1;
	return f(n-1) + g(n-2);
}