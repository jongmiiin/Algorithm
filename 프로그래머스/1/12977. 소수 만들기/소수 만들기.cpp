#include <bits/stdc++.h>

using namespace std;

bool flag[3004];

void prime_search(int n){
    for(int i=2;i*i<=n;i++){
        if(flag[i]) continue;
        for(int j=i+i;j<=n;j+=i)
            flag[j] = true;
    }
}

bool bin_search(vector<int>& prime, int n){
    int l = 0, r = prime.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(n == prime[mid]) return true;
        else if(n>prime[mid]) l = mid+1;
        else r = mid-1;
    }
    return false;
}

int solution(vector<int> nums) {
    int answer = 0, len = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> prime;
    int mx = nums[len-1]*3;
    prime_search(mx);
    for(int i=2;i<=mx;i++)
        if(!flag[i]) prime.push_back(i);
    for(int i=0;i<prime.size();i++) cout << prime[i] << endl;
    for(int i=0;i<len-2;i++){
        for(int j=i+1;j<len-1;j++){
            for(int k=j+1;k<len;k++){
                if(bin_search(prime, nums[i]+nums[j]+nums[k])) answer++;
            }
        }
    }
    return answer;
}