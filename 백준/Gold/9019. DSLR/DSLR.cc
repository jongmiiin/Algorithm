#include <bits/stdc++.h>

using namespace std;

string bfs(int a, int b);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
	return 0;
}

string bfs(int a, int b){
	vector<bool> flag(10004);
	queue<pair<int, string>> q;
	q.push({a,""});
	flag[a] = true;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int t_num = q.front().first;
			string t_command = q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
				int num = t_num;
				string command = t_command;
				switch(i){
					case 0:
						num = (2*num)%10000;
						command += "D";
						break;
					case 1:
						num--;
						if(num==-1) num=9999;
						command += "S";
						break;
					case 2:
						if(num>=1000){
							int t_front = num/1000, t_tail = num%1000;
							num = t_tail*10 + t_front;
						}
						else num *= 10;
						command += "L";
						break;
					case 3:
						if(num>=10){
							int t_front = num/10, t_tail = num%10;
							num = t_tail*1000 + t_front;
						}
						else num *= 1000;
						command += "R";
						break;
				}
				if(flag[num]) continue;
				if(num==b) return command;
				else{
					q.push({num, command});
					flag[num] = true;
				}
			}
		}
	}
}