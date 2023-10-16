#include <bits/stdc++.h>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, num, a, b, c;
	vector <pair<int, pair<int, int>>> arr;

	cin >> n;
	for (int i=0; i<n; i++) {

		cin >> num >> a >> b >> c;
		arr.push_back({a*b*c, {a+b+c, num}});
	}

	sort (arr.begin(), arr.end());
	
	for (int i=0; i<3; i++) {
		cout << arr[i].second.second << " ";
	}


	return 0;
}