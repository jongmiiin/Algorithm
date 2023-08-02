#include <bits/stdc++.h>

using namespace std;

int student[1004][10];
bool flag[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0, mx = 0, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			cin >> student[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<n;k++){
				if(k == i) continue;
				if(student[i][j] == student[k][j]) flag[k] = true;
			}
		}
		for(int j=0;j<n;j++){
			if(flag[j]) cnt++;
		}
		if(cnt>mx){
			mx = cnt;
			ans = i;
		}
		cnt = 0;
		memset(flag, false, sizeof(bool)*1004);
	}
	cout << ans+1;
	return 0;
}