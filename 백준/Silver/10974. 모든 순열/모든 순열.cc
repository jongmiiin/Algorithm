#include <bits/stdc++.h>

using namespace std;

int n;
int arr[14];
bool check[14];
void permu(int lev);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	permu(0);
	return 0;
}

void permu(int lev){
	if(lev == n){
		for(int i=0;i<n;i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(check[i]) continue;
		check[i] = true;
		arr[lev] = i;
		permu(lev+1);
		check[i] = false;
	}
}