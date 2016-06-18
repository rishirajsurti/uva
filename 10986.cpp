#include <bits/stdc++.h>
using namespace std;

#define INF 1e6
typedef unsigned long long llu;
typedef vector<llu> vi;
typedef pair<llu, llu> ii;
typedef vector<ii> vii;

vector<vii> adj;

int main(){
	llu t, tc = 1; scanf("%llu", &t);
	while(t--){
		llu v,e,s,t;
		scanf("%llu %llu %llu %llu", &v, &e, &s, &t);
		adj.assign(v, vii());
		llu i,j, a, b, wt;

		for(i=0; i<e; i++){
			scanf("%llu %llu %llu", &a, &b, &wt);
			adj[a].push_back(ii(b,wt));
			adj[b].push_back(ii(a,wt));
		}

		vi dist(v, INF);
		vi visited(v, 0);
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		
		dist[s] = 0;
		pq.push(ii(dist[s], s));

		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			llu d = front.first, u = front.second;
			if(d > dist[u]) continue;
//			if(u==t) break;
			for(i=0; i<adj[u].size(); i++){
				ii vtx = adj[u][i];

				if(dist[vtx.first] > dist[u]+vtx.second){
					dist[vtx.first] = dist[u]+vtx.second;
					//visited[vtx.first] = 1;
					pq.push(ii(dist[vtx.first], vtx.first));
				}
			}
			
		}
		if(dist[t] == INF)
			printf("Case #%llu: unreachable\n",tc++ );
		else
			printf("Case #%llu: %llu\n",tc++, dist[t]);

	}
	return 0;

}