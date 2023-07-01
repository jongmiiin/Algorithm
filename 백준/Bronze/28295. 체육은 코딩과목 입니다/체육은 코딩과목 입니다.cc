#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	for(int i=0;i<10;i++){
		int t;
		cin >> t;
		if(t != 3){
			cnt += t;
			cnt %= 4;
		}
		else{
			cnt--;
			if(cnt<0) cnt = 3;
		}
	}
	if(cnt == 0) cout << "N";
	else if(cnt == 1) cout << "E";
	else if(cnt == 2) cout << "S";
	else cout << "W";
	return 0;
}