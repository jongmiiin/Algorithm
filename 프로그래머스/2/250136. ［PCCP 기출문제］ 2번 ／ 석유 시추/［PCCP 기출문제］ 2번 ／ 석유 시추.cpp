#include <bits/stdc++.h>

using namespace std;

int cnt;
bool check[504][504], row[504];
vector<int> row_list;

int dp[504];

int dy[] = {0, 0, 1, -1}; // 우 좌 하 상 순서 
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int ylen, int xlen, vector<vector<int>>& land);

int solution(vector<vector<int>> land) {
    int answer = 0;
    int ylen = land.size(), xlen = land[0].size();
    for(int i=0;i<xlen;i++){
        for(int j=0;j<ylen;j++){
            if(land[j][i] == 1 && !check[j][i]){
                check[j][i] = true;
                cnt++;
                row_list.push_back(i);
                row[i] = true;
                dfs(j, i, ylen, xlen, land);
                for(int k=0;k<row_list.size();k++){
                    dp[row_list[k]] += cnt;
                }
            }
            cnt = 0;
            row_list.clear();
            memset(row, 0, sizeof(row));
        }
    }
    sort(dp, dp+xlen);
    return answer=dp[xlen-1];
}

void dfs(int y, int x, int ylen, int xlen, vector<vector<int>>& land){    
    for(int i=0;i<4;i++){
        int ny = y+dy[i], nx = x+dx[i];
        if(ny<0 || ny>=ylen || nx<0 || nx>=xlen || check[ny][nx] || land[ny][nx] == 0) continue;
        check[ny][nx] = true;
        cnt++;
        if(!row[nx]){
            row_list.push_back(nx);
            row[nx] = true;
        }
        dfs(ny, nx, ylen, xlen, land);
    }
}