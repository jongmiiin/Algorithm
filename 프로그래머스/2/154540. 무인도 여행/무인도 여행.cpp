#include <bits/stdc++.h>

using namespace std;

int cnt = 0, h, w;
bool check[104][104];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(vector<string>& maps, int y, int x){
    check[y][x] = true;
    for(int i=0;i<4;i++){
        int ny = y+dy[i], nx = x+dx[i];
        if(ny<0 || ny>=h || nx<0 || nx>=w || check[ny][nx] || maps[ny][nx]=='X') continue;
        cnt+=maps[ny][nx] - '0';
        dfs(maps, ny, nx);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    h = maps.size();
    w = maps[0].size();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(maps[i][j] != 'X' && check[i][j] == false){
                cnt+=maps[i][j]-'0';
                dfs(maps, i, j);
                answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}