#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string comm, s, num = "";
		cin >> comm;
		int n;
		cin >> n >> s;
		vector<int> v;
		deque<int> dq;
		if(n){
			for(int i=1;i<s.size();i++){
				if(s[i] == ',' || s[i] == ']'){
					int t = 0;
					for(int j=0;j<v.size();j++)
						t+=v[j]*pow(10,v.size()-1-j);
					dq.push_back(t);
					v.clear();
				}
				else v.push_back(s[i]-'0');
			}
		}
		bool front_inx = true, error_flag = false;
		for(int i=0;i<comm.size();i++){
			if(comm[i] == 'R'){
				if(front_inx) front_inx = false;
				else front_inx = true;
			}
			else if(comm[i] == 'D'){
				if(dq.empty()){
					error_flag = true;
					break;
				}
				else if(front_inx) dq.pop_front();
				else dq.pop_back();
			}
		}
		if(error_flag) cout << "error" << '\n';
		else{
			cout <<"[";
			int cnt = 0, size = dq.size();
			while(!dq.empty()){
				if(front_inx){
					cout << dq.front();
					dq.pop_front();
				}
				else{
					cout << dq.back();
					dq.pop_back();
				}
				if(++cnt != size) cout << ",";
			}
			cout << "]" << '\n';
		}
	}
	return 0;
}