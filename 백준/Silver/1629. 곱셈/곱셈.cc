#include <bits/stdc++.h>

using namespace std;

long long multiple(long long a,  long long b, long long c);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << multiple(a, b, c);
	return 0;
}

long long multiple(long long a,  long long b, long long c){
	if(b==1) return a%c;
	long long t = multiple(a, b/2, c);
	if(b%2==1) return a*t%c*t%c;
	else return t*t%c;
}