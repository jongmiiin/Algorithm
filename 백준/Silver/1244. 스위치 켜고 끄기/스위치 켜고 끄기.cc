#include <bits/stdc++.h>

using namespace std;

int button[104];
int n, m;

void boy(int num);
void girl(int num);
void status(int s_num);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> button[i];
	cin >> m;
	for(int i=0;i<m;i++){
		int s, num;
		cin >> s >> num;
		if(s == 1) boy(num);
		else girl(num);
	}
	for(int i=1;i<=n;i++){
		cout << button[i] << " ";
		if(i%20 == 0) cout << '\n';
	}
	return 0;
}

void status(int s_num){
	if(button[s_num]) button[s_num] = 0;
	else button[s_num] = 1;
}

void boy(int num){
	int cnt = 1;
	while(num*cnt <= n){
		status(num*cnt);
		cnt++;
	}
}

void girl(int num){
	int cnt = 1;
	status(num);
	while(num+cnt <= n && num-cnt > 0){
		if(button[num+cnt] != button[num-cnt]) break;
		status(num+cnt);
		status(num-cnt);
		cnt++;
	}
}