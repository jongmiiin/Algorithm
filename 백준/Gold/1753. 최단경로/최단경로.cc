#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, K;
	cin >> V >> E >> K;
	vector<pair<int, int>> edge[V+1];
	for(int i=0;i<E;i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
	}
	vector<int> dist(V+1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, K});
	dist[K] = 0;
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(cost>dist[now]) continue;
		for(int i=0;i<edge[now].size();i++){
			int next = edge[now][i].first;
			int next_cost = edge[now][i].second;
			if(dist[next] == -1 || dist[next]>dist[now]+next_cost){
				dist[next] = dist[now]+next_cost;
				pq.push({dist[next], next});
			}
		}
	}
	for(int i=1;i<=V;i++){
		if(dist[i]==-1) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}