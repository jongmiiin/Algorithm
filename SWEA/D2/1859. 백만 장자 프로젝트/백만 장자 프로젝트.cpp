#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin >> t;
   for(int q=1;q<=t;q++){
   	int d;
   	cin >> d;
   	vector<long long> v(d);
   	for(int i=0;i<d;i++)
   		cin >> v[i];
   	long long mx = v[d-1], sum = 0;
   	for(int i=d-2;i>=0;i--){
   		if(v[i]<mx) sum+=mx-v[i];
   		else mx = max(v[i], mx);
   	}
   	cout << '#' << q << ' ' << sum << '\n';
   }
   return 0;
}