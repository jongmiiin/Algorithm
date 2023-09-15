#include <bits/stdc++.h>

using namespace std;

bool flag[100004];
int dnow[4] = {1, -1, 2};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, cnt = 0;
	cin >> n >> k;
	if(n==k){
		cout << 0 << '\n' << 1;
		return 0;
	}
	queue<int> q;
	q.push(n);
	flag[n] = true;
	vector<int> ans;
	while(!q.empty()){
		int size = q.size();
		cnt++;
		while(size--){
			int now = q.front();
			flag[now] = true;
			q.pop();
			dnow[2] = now;
			for(int i=0;i<3;i++){
				int next = now+dnow[i];
				if(next<0 || next>100000 || flag[next]) continue;
				if(next == k) ans.push_back(next);
				else q.push(next);
			}
		}
		if(!ans.empty()){
			cout << cnt << '\n' << ans.size();
			return 0;
		}
	}
	return 0;
}