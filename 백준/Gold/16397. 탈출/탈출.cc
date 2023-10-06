#include <bits/stdc++.h>

using namespace std;

int n, t, g;
bool flag[100004];

void bfs();
int A(int now);
int B(int now);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> t >> g;
	bfs();
	return 0;
}

void bfs(){
	int cnt = 0;
	queue<int> q;
	q.push(n);
	flag[n] = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int now = q.front();
			q.pop();
			if(now == g){
				cout << cnt;
				return;
			}
			int a = A(now);
			int b = B(now);
			if(a != -1 && !flag[a]){
				q.push(a);
				flag[a] = true;
			}
			if(b != -1 && !flag[b]){
				q.push(b);
				flag[b] = true;
			}
		}
		cnt++;
		if(cnt>t) break;
	}
	cout << "ANG";
	return;
}

int A(int now){
	if(now==99999) return -1;
	return now+1;
}

int B(int now){
	now*=2;
	if(now>99999) return -1;
	for(int i=10000;i>0;i/=10){
		if(i==0) break;
		if(now/i) return now-i;
	}
	return -1;
}