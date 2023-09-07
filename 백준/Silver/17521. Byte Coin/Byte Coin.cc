#include <bits/stdc++.h>

using namespace std;

int price[24];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, w;
	cin >> n >> w;
	for(int i=0;i<n;i++)
		cin >> price[i];
	long long now = price[0], mx = 0, mn = 0, bet = 0;
	bool increase = false, decrease = false;
	for(int i=1;i<n;i++){
		if(!increase && !decrease){
			if(now<price[i]){
				increase = true;
				mx = price[i];
				mn = now;
			}
			else if(now>price[i]){
				decrease = true;
				mn = price[i];
			}
		}
		else if(increase){
			if(price[i]>mx) mx = price[i];
			else if(price[i]<mx){
				bet = w/mn;
				w %= mn;
				w += bet*mx;
				increase = false;
				decrease = true;
				mn = price[i];
			}
		}
		else if(decrease){
			if(price[i]<mn) mn = price[i];
			else if(price[i]>mn){
				mx = price[i];
				decrease = false;
				increase = true;
			}
		}
		if(i==n-1){
			if(increase){
				bet = w/mn;
				w %= mn;
				w += bet*mx;
			}
		}
	}
	cout << w;
	return 0;
}