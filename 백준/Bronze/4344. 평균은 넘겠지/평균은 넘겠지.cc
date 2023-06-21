#include <bits/stdc++.h>

using namespace std;

int main(){
	int c;
	cin >> c;
	for(int i=0;i<c;i++){
		int n;
		double sum = 0;
		cin >> n;
		vector<int> v(n);
		for(int j=0;j<n;j++){
			cin >> v[j];
			sum += (double)v[j];
		}
		int cnt = 0;
		double p = sum/(double)n;
		for(int j=0;j<n;j++)
			if(v[j]>p) cnt++;
		printf("%.3lf%\n", 100*(cnt/(double)n)+0.000005);
	}
	return 0;
}