#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, answer = 0;
	cin >> n;
	vector<vector<int>> sample(n+1);
	vector<pair<int, int>> log;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			int t;
			scanf("%1d", &t);
			sample[i].push_back(t);
		}
		int s, b;
		cin >> s >> b;
		log.push_back({s, b});
	}
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(j==i) continue;
			for(int k=1;k<=9;k++){
				if(k==i || k==j) continue;
				bool flag = true;
				for(int t=0;t<n;t++){
					int s = 0, b = 0;
					// strike
					if(i == sample[t][0]) s++;
					if(j == sample[t][1]) s++;
					if(k == sample[t][2]) s++;
					
					// ball
					if(j == sample[t][0]) b++;
					if(k == sample[t][0]) b++;

					if(i == sample[t][1]) b++;
					if(k == sample[t][1]) b++;

					if(i == sample[t][2]) b++;
					if(j == sample[t][2]) b++;

					if(log[t].first != s || log[t].second != b) flag = false;
				}
				if(flag) answer++;
			}
		}
	}
	cout << answer;
	return 0;
}