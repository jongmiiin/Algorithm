#include <bits/stdc++.h>

using namespace std;

int stan[104], restan[104];
int moya[104][54];
int ans[104];

void convert(int n);
void check(int ith);
void comp(int ith, int i, bool isstan);

int n, m, cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> stan[i];
	convert(n);
	cin >> m;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> moya[i][j];
	for(int i=0;i<m;i++)
		check(i);
	cout << cnt << '\n';
	for(int i=0;i<cnt;i++){
		for(int j=0;j<n;j++)
			cout << moya[ans[i]][j] << " ";
		cout << '\n';
	}
	return 0;
}

void convert(int n){
	int inx = 0;
	for(int i=n-1;i>=0;i--){
		switch(stan[i]){
			case 1: restan[inx] = 3; break;
			case 2: restan[inx] = 4; break;
			case 3: restan[inx] = 1; break;
			case 4: restan[inx] = 2; break;
		}
		inx++;
	}
}

void check(int ith){
	for(int i=0;i<n;i++){
		if(moya[ith][0] == stan[i]) comp(ith, i, true);
		if(moya[ith][0] == restan[i]) comp(ith, i, false);
	}
}

void comp(int ith, int i, bool isstan){
	int inx = i, corr = 0; 
	if(isstan){
		for(int j=0;j<n;j++){
			if(stan[inx] != moya[ith][j]) return;
			corr++;
			inx++;
			if(inx==n) inx = 0;
			if(corr == n) ans[cnt++] = ith;
		}
	}
	else{
		for(int j=0;j<n;j++){
			if(restan[inx] != moya[ith][j]) return;
			corr++;
			inx++;
			if(inx==n) inx = 0;
			if(corr == n) ans[cnt++] = ith;
		}
	}
}