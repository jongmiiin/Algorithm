#include <bits/stdc++.h>

using namespace std;

bool visited[1004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v[n+1];
	for(int i=0;i<m;i++){
		int st, en, cost;
		cin >> st >> en >> cost;
		v[st].push_back({en, cost});
	}
	vector<int> dist(n+1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	int st, en;
	cin >> st >> en;
	pq.push({0, st});
	dist[st] = 0;
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(visited[now] == false || now == en){
			visited[now] = true;
			for(int i=0;i<v[now].size();i++){
				int next = v[now][i].first;
				int next_cost = v[now][i].second;
				if(dist[next] == -1 || dist[next] > dist[now] + next_cost){
					dist[next] = dist[now] + next_cost;
					pq.push({dist[next], next});
				}
			}
		}
	}
	cout << dist[en];
	return 0;
}