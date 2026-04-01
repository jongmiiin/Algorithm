#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(1); answer.push_back(0); // [0] : 이진변환 횟수, [1], 변환과정에서 제거된 0의 개수
    int s_len = s.size(), cnt = 0, n = 0;;
    for(int i=0;i<s_len;i++){
        if(s[i] == '0') answer[1]++;
        else n++;
    }
    
    while(n>1){
        answer[0]++;
        int temp = 0;
        while(n>0){
            if(n%2 == 1) temp++;
            else answer[1]++;
            n = n>>1;
        }
        n = temp;
    }
    return answer;
}