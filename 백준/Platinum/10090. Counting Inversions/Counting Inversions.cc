#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& a, int l, int m, int r);
void merge_sort(vector<int>& a, int l, int r);
long long cnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	merge_sort(a, 0, n-1);
	cout << cnt;
	return 0;
}

void merge(vector<int>& a, int l, int m, int r){
	int i = l, j = m+1, t = 0;
	vector<int> temp(r-l+1);
	while((i<=m) && (j<=r)){
		if(a[i]<=a[j]){
			temp[t++] = a[i++];
		}
		else{
			cnt += m-i+1;
			temp[t++] = a[j++];
		}
	}
	while(i<=m)
		temp[t++] = a[i++];
	while(j<=r)
		temp[t++] = a[j++];
	i = l; t = 0;
	while(i<=r) 
		a[i++] = temp[t++];
}

void merge_sort(vector<int>& a, int l, int r){
	if(l<r){
		int m = (l+r)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
}