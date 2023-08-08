#include <bits/stdc++.h>

using namespace std;

int paper[130][130];
int white = 0, blue = 0;

void count(int ystart, int yend, int xstart, int xend);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> paper[i][j];
	count(0, n-1, 0, n-1);
	cout << white << "\n" << blue;
	return 0;
}

void count(int ystart, int yend, int xstart, int xend){
	int def = paper[ystart][xstart], ymid = (ystart+yend)/2, xmid = (xstart+xend)/2;
	if(ystart == yend){
		if(def) blue++;
		else white++;
		return;
	}
	bool flag = false;
	for(int i=ystart;i<=yend;i++){
		for(int j=xstart;j<=xend;j++){
			if(paper[i][j] != def){
				flag = true;
				break;
			}
		}
	}
	if(flag){
		count(ystart, ymid, xstart, xmid);
		count(ystart, ymid, xmid+1, xend);
		count(ymid+1, yend, xstart, xmid);
		count(ymid+1, yend, xmid+1, xend);
	}
	else{
		if(def) blue++;
		else white++;
		return;
	}
}