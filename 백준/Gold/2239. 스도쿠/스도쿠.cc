#include <bits/stdc++.h>

using namespace std;

struct point{
    int y, x;
};

int arr[10][10];
vector<point> v;

void row_check(int y, int x, vector<bool>& check){
    for(int i=0;i<9;i++){
        if(arr[y][i] == 0) continue;
        check[arr[y][i]] = true;
    }
    return;
}

void col_check(int y, int x, vector<bool>& check){
    for(int i=0;i<9;i++){
        if(arr[i][x] == 0) continue;
        check[arr[i][x]] = true;
    }
    return;
}

void squ_check(int y, int x, vector<bool>& check){
    int tmp_y = y - (y%3), tmp_x = x - (x%3);
    for(int i=tmp_y;i<tmp_y+3;i++){
        for(int j=tmp_x;j<tmp_x+3;j++){
            if(arr[i][j] == 0) continue;
            check[arr[i][j]] = true;
        }
    }
}

void print_sudoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout << arr[i][j];
        cout << '\n';
    }
}

void sudoku(int y, int x, int idx, int len){
    if(idx == len){
        print_sudoku();
        exit(0);
    }
    vector<bool> check(10, false);
    row_check(y, x, check);
    col_check(y, x, check);
    squ_check(y, x, check);
    for(int i=1;i<10;i++){
        if(check[i]) continue;
        arr[y][x] = i;
        sudoku(v[idx+1].y, v[idx+1].x, idx+1, len);
        arr[y][x] = 0;
    }
}

int main(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            scanf("%1d", &arr[i][j]);
            if(arr[i][j] == 0) v.push_back({i, j});
        }
    sudoku(v[0].y, v[0].x, 0, v.size());
    return 0;
}