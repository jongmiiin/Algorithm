#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> judge(n);
	for(int i=0;i<n;i++)
		cin >> judge[i];
	reverse(judge.begin(), judge.end());
	vector<stack<int>> v(k);
	for(int i=0;i<n;i++){
		bool flag = false;
		for(int j=0;j<k;j++){
			if(v[j].empty() || judge[i] < v[j].top()){
				v[j].push(judge[i]);
				flag = true;
				break;
			}
		}
		if(!flag){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}