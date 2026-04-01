#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int i=3;i<max(brown, yellow);i++){
        if(sum%i==0){
            int big = max(i, sum/i), small = min(i, sum/i);
            if(2*big + 2*small - 4 == brown){
                answer.push_back(big);
                answer.push_back(small);
                break;  
            }
        }
    }
    return answer;
}