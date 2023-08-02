#include <bits/stdc++.h>

using namespace std;

bool row[104], col[104];
int x, y, n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> x >> y >> n;
	row[0] = true; row[y] = true;
	col[0] = true; col[x] = true;
	for(int i=0;i<n;i++){
		int flag, num;
		cin >> flag >> num;
		switch(flag){
			case 0: row[num] = true; break;
			case 1: col[num] = true; break;
		}
	}
	vector<int> row_dif;
	vector<int> col_dif;
	int st = 0, en = 0;
	for(int i=1;i<=y;i++){
		if(row[i]){
			en = i;
			col_dif.push_back(en-st);
			st = i;
		}
	}
	st = 0;
	for(int i=0;i<=x;i++){
		if(col[i]){
			en = i;
			row_dif.push_back(en-st);
			st = i;
		}
	}
	int mx = 0;
	for(int i=0;i<row_dif.size();i++)
		for(int j=0;j<col_dif.size();j++)
			if(mx<row_dif[i]*col_dif[j]) mx = row_dif[i]*col_dif[j];
	cout << mx;
	return 0;
}