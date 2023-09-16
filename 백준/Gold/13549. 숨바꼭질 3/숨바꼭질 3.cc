#include <bits/stdc++.h>

using namespace std;

bool flag[200004];
int dnow[] = {1, -1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, cnt = 0;
	cin >> n >> k;
	if(n==k){
		cout << 0;
		return 0;
	}
	queue<int> q;
	q.push(n);
	flag[n] = true;
	while(n){
		n*=2;
		if(n==k){
			cout << 0;
			return 0;
		}
		if(n>2*k) break;
 		q.push(n);
		flag[n] = true;
	}
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			int now = q.front();
			q.pop();
			for(int i=0;i<2;i++){
				int next = now+dnow[i];
				if(next<0 || next>100000 || flag[next]) continue;
				q.push(next);
				flag[next] = true;
				if(next==k){
					cout << cnt;
					return 0;
				}
				while(next && next<=2*k){
					next*=2;
					if(next==k){
						cout << cnt;
						return 0;
					}
					if(next>2*k || flag[next]) break;
					q.push(next);
					flag[next] = true;
				}
			}
		}
	}
	return 0;
}