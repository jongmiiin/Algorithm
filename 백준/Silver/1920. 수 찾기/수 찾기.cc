#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int bin_search(int a[], int left, int right, int num) 
{
	while(left<=right)
	{
		int mid=(left+right)/2;	
		if(a[mid] < num) left = mid+1;
		else if(a[mid] > num) right = mid-1;
		else return 1;
	}
	return 0;
}
int main()
{
	int n,m;
	scanf(" %d", &n);
	for(int i=0;i<n;i++)
		scanf(" %d", &a[i]);
	sort(a, a+n);
	scanf(" %d", &m);
	for(int i=0;i<m;i++)
	{
		int b;
		scanf(" %d", &b);
		printf("%d\n", bin_search(a, 0, n-1, b));
		
	}
	
	
	
	return 0;
}