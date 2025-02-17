#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int temp = n, cnt = 0, st = 1, mid = n/2;
    while(temp/=2) cnt++;
    if(a>b) swap(a,b);
    while(cnt){
        if(a<=mid && b>mid) return cnt;
        else if(a<=mid && b<=mid)  n = mid;
        else st = mid+1;
        mid = (n+st)/2;
        cnt--;
    }
}