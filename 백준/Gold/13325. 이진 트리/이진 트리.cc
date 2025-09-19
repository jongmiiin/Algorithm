#include <bits/stdc++.h>

using namespace std;

long long k, tree_size, ans;
vector<long long> trees;

long long dfs(int node){
	int left = node*2, right = node*2+1;
	if(left>tree_size-1) return trees[node];
	long long l = dfs(left), r = dfs(right);
	ans += abs(l-r);
	return trees[node]+max(l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	tree_size = 1<<(k+1);
	trees.assign(tree_size, 0);
	for(int i=2;i<tree_size;i++){
		cin >> trees[i];
		ans += trees[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}