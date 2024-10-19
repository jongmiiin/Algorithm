#include <bits/stdc++.h>

using namespace std;

int miro[1004][1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> miro[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0) miro[i][j] += miro[i][j-1];
			else if(j==0) miro[i][j] += miro[i-1][j];
			else miro[i][j] += max(miro[i-1][j-1], max(miro[i-1][j], miro[i][j-1]));
		}
	}
	cout << miro[n-1][m-1];
	return 0;
}