#include <bits/stdc++.h>

using namespace std;

int arr[704][704];
int n, m, time_one = 0, time_two = 0;
int dx[] = {0, -1, -1};
int dy[] = {-1, 0, -1};

struct Cnt{
	int zero_inx = -1, one_inx = -1, two_inx = -1;
};

void add_cnt(vector<Cnt>& v);
void grow();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j] = 1;
	vector<Cnt> v(2*n+1);
	for(int i=0;i<m;i++){
		int zero_cnt, one_cnt, two_cnt;
		cin >> zero_cnt >> one_cnt >> two_cnt;
		if(one_cnt) time_one++;
		if(two_cnt) time_two++;
		one_cnt += zero_cnt;
		two_cnt += one_cnt;
		if(zero_cnt == 0){
			if(one_cnt == 0) v[1].two_inx = 2;
			else{
				v[1].one_inx = 1;
				if(two_cnt != 0) v[one_cnt+1].two_inx = 2;
			}
		}
		else{
			v[1].zero_inx = 0;
			v[zero_cnt+1].one_inx = 1;
			v[one_cnt+1].two_inx = 2;
		}
	}
	add_cnt(v);
	grow();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	return 0;
}

void add_cnt(vector<Cnt>& v){
	int inx = 1, plus_num = 0;
	for(int i=n-1;i>=0;i--){
		if(v[inx].two_inx == 2){
			if(time_one != 0) plus_num+=2;
			else plus_num++;
			time_two--;
		}
		if(v[inx].one_inx == 1){
			plus_num++;
			time_one--;
		}
		arr[i][0] += plus_num;
		inx++;
	}
	for(int i=1;i<n;i++){
		if(v[inx].two_inx == 2){
			if(time_one != 0) plus_num+=2;
			else plus_num++;
			time_two--;
		}
		if(v[inx].one_inx == 1){
			plus_num++;
			time_one--;
		}
		arr[0][i] += plus_num;
		inx++;
	}
}

void grow(){
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			arr[j][i] = arr[0][i];
}