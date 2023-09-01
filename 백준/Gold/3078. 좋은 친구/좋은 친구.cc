#include <bits/stdc++.h>

using namespace std;

int name[24];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int size = s.size();
		v.push_back(size);
	}
	for(int i=1;i<=k;i++)
		name[v[i]]++;
	long long cnt = 0;
	for(int i=0;i<n;i++){
		cnt += name[v[i]];
		if(i+1<n) name[v[i+1]]--;
		if(i+1+k<n) name[v[i+1+k]]++;
	}
	cout << cnt;
	return 0;
}