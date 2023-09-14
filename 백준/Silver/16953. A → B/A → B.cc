#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b, cnt = 0;
	cin >> a >> b;
	queue<long long> q;
	q.push(a);
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			long long n = q.front();
			q.pop();
			long long plus_n = n*10+1, multi_n = n*2;
			if(plus_n == b || multi_n == b){
				cout << cnt+1;
				return 0;
			}
			if(plus_n<=b) q.push(plus_n);
			if(multi_n<=b) q.push(multi_n);
		}
	}
	cout << -1;
	return 0;
}