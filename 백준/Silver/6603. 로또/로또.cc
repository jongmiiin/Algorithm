#include <bits/stdc++.h>

using namespace std;

int n;
int arr[14], ans[14];
void rec(int inx, int lev);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin >> n;
		if(n==0) break;
		for(int i=0;i<n;i++)
			cin >> arr[i];
		rec(0, 0);
		cout << endl;
	}
	return 0;
}

void rec(int inx, int lev){
	if(lev==6){
		for(int i=0;i<6;i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=inx;i<n;i++){
		ans[lev] = arr[i];
		rec(i+1, lev+1);
	}
}