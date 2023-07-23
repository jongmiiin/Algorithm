#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> a(10);
	vector<int> b(10);
	for(int i=0;i<10;i++)
		cin >> a[i];
	for(int i=0;i<10;i++)
		cin >> b[i];
	int acnt = 0, bcnt = 0, flag = 0;
	for(int i=0;i<10;i++){
		if(a[i]>b[i]){
			acnt += 3;
			flag = 1;
		}
		else if(b[i]>a[i]){
			bcnt += 3;
			flag = 2;
		}
		else{
			acnt++;
			bcnt++;
		}
	}
	cout << acnt << " " << bcnt << endl;
	if(acnt == bcnt){
		if(flag == 1) cout << "A";
		else if(flag == 2) cout << "B";
		else cout << "D";
	}
	else cout << (acnt>bcnt?"A":"B");
	return 0;
}