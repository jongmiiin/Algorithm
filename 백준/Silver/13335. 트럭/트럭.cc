#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, w, l;
	int arr[1001];
	queue <int> q;
	int total_wight = 0, time = 0;

	cin >> n >> w >> l;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}

	for (int i=0; i<n; i++) {
		while (true) {
			if (q.size() == w) {
				total_wight -= q.front();
				q.pop();
			}
			if (arr[i] + total_wight <= l) break;
			q.push(0); //아무 변동 없음
			time++;
		}
		q.push(arr[i]);
		total_wight += arr[i];
		time++;
	}

	cout << time + w << "\n";

	return 0;
}