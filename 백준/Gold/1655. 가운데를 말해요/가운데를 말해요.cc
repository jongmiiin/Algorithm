#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, mid;
	cin >> n;
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		if(i==1){
			mid = t;
		}
		else{
			if(t<mid) left.push(t);
			else right.push(t);
		}
        if(left.size() < right.size()){
			if(i%2){
				while(left.size() != right.size()){
					left.push(mid);
					mid = right.top();
					right.pop();
				}
			}
			else{
				while(left.size()+1 != right.size()){
					left.push(mid);
					mid = right.top();
					right.pop();
				}
			}
		}
		else if(left.size() > right.size()){
			if(i%2){
				while(left.size() != right.size()){
					right.push(mid);
					mid = left.top();
					left.pop();
				}
			}
			else{
				while(left.size()+1 != right.size()){
					right.push(mid);
					mid = left.top();
					left.pop();
				}
			}
		}
		cout << mid << '\n';
	}
	return 0;
}	