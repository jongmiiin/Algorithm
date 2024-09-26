#include <bits/stdc++.h>

using namespace std;

int n, k;
char arr[24], ans[24];
void rec(int lev, int idx);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i=0;i<k;i++)
		cin >> arr[i];
	sort(arr, arr+k);
	rec(0, 0);
	return 0;
}

void rec(int lev, int idx){
	if(lev==n){
		bool vowel = false;
		int consonant = 0;
		for(int i=0;i<n;i++){
			switch(ans[i]){
				case 97:
				case 101:
				case 105:
				case 111:
				case 117:
					vowel = true;
					break;
				default:
					consonant++;
					break;
			}
		}
		if(vowel && consonant>=2){
			for(int i=0;i<n;i++)
				cout << ans[i];
			cout << '\n';
		}
		return;
	}
	for(int i=idx;i<k;i++){
		ans[lev] = arr[i];
		rec(lev+1, i+1);
	}
}