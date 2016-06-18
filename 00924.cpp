#include <bits/stdc++.h>
using namespace std;

#define INF 1e6
typedef vector<int> vi;
vector<vi> adj;

int main(){
	int E;
	scanf("%d", &E);
	adj.assign(E, vi());
	int i,j,x, neighbors;
	for(i=0; i<E; i++){
		scanf("%d", &neighbors);
		for(j=0; j<neighbors; j++){
			scanf("%d", &x);
			adj[i].push_back(x);
		}
	}

	int t; scanf("%d", &t);
	while(t--){
		int s; scanf("%d", &s);
		vi layer(E,0);
		vi dist(E, INF);
		queue<int> q;
		q.push(s); dist[s] = 0;
		layer[dist[s]] = 0;
		int max_boom = 0, day;

		while(!q.empty()){
			int u = q.front(); q.pop();
/*			if(layer[dist[u]] > max_boom){
				max_boom = layer[dist[u]];
				day = dist[u];
			}
*/
			for(i=0; i<adj[u].size(); i++){
				int v = adj[u][i];
				if(dist[v] == INF){
					dist[v] = dist[u] + 1;
					q.push(v);
					layer[dist[u]+1]++;
				}
			}
		}	

		for(i=0; i<E; i++){
			if(layer[i] > max_boom){
				max_boom = layer[i];
				day = i;
			}
		}
		if(max_boom)
			printf("%d %d\n", max_boom, day);
		else
			printf("0\n");
	}
	return 0;
}