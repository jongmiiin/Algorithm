#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cnt = 0;
	cin >> n >> m;
	deque<int> dq(n);
	for(int i=1;i<=n;i++)
		dq[i-1] = i;
	vector<int> v(m);
	for(int i=0;i<m;i++)
		cin >> v[i];
	while(!v.empty()){
		int inx = 0, el = v.front(), len = dq.size();
		bool lflag = false;
		for(int i=0;i<len;i++){
			if(dq[i] == el){
				if(i>(len-i)){
					lflag = true;
					inx = len-i;
				}
				else inx = i;
			}
		}
		if(lflag){
			while(inx--){
				int t = dq.back();
				dq.pop_back();
				dq.push_front(t);
				cnt++;
			}
		}
		else{
			while(inx--){
				int t = dq.front();
				dq.pop_front();
				dq.push_back(t);
				cnt++;
			}
		}
		if(dq.front() == el){
			dq.pop_front();
			v.erase(v.begin());
		}
	}
	cout << cnt;
	return 0;
}