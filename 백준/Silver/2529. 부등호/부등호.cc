#include <bits/stdc++.h>

using namespace std;

bool is_correct(vector<int>& permu, vector<char>& v);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<char> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	vector<int> big(n+1);
	vector<int> small(n+1);
	for(int i=0;i<=n;i++){
		big[i] = 9-i;
		small[i] = i;
	}
	do{
		if(is_correct(small, v)) break;
	}while(next_permutation(small.begin(), small.end()));
	do{
		if(is_correct(big, v)) break;
	}while(prev_permutation(big.begin(), big.end()));
	for(int i=0;i<big.size();i++)
		cout << big[i];
	cout << '\n';
	for(int i=0;i<small.size();i++)
		cout << small[i];
	return 0;
}

bool is_correct(vector<int>& permu, vector<char>& v){
	for(int i=0;i<v.size();i++){
		if(v[i]=='<' && permu[i]>permu[i+1]) return false;
		if(v[i]=='>' && permu[i]<permu[i+1]) return false;
	}
	return true;
}