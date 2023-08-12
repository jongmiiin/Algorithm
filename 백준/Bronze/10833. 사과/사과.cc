#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, sum = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		int stud, app;
		cin >> stud >> app;
		sum += app%stud;
	}
	cout << sum;
	return 0;
}