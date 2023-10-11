#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, cnt = 0;
		cin >> n;
		vector<int> v;
		vector<int> mid;
		for(int i=1;i<=n;i++){
			int k;
			cin >> k;
			v.push_back(k);
			if(i%2){
				sort(v.begin(), v.end());
				mid.push_back(v[(v.size())/2]);
			}
		}
		cout << mid.size() << '\n';
		for(int i=0;i<mid.size();i++){
			cout << mid[i];
			cnt++;
			if(cnt==10){
				cnt = 0;
				cout << '\n';
			}
			else cout << " ";
		}
		cout << '\n';
	}
	return 0;
}