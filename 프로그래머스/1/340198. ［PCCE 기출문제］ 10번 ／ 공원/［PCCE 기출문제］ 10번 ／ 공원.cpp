#include <bits/stdc++.h>

using namespace std;

int search(vector<vector<string>>& park, int y, int x, int n){
    for(int i=y;i<y+n;i++){
        for(int j=x;j<x+n;j++){
            if(park[i][j] != "-1") return -1;
            else continue;
        }
    }
    return n;
}
int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int y = park.size(), x = park[0].size();
    sort(mats.begin(), mats.end());
    reverse(mats.begin(), mats.end());
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            for(int k=0;k<mats.size();k++){
                if(i+mats[k] > y || j+mats[k] > x) continue;
                if(search(park, i, j, mats[k]) == -1) continue;
                else answer = max(answer, mats[k]);
            }
        }
    }
    return answer;
}
