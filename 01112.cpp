#include <bits/stdc++.h>
using namespace std;

int adj[105][105];

int main(){
	int tc;
	int n, e, t,m, u, v, w;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d\n%d\n%d\n%d\n", &n, &e, &t, &m);
		memset(adj, 63, sizeof adj);

		n++;
		int i,j,k;
		for(i=0; i<m; i++){
			scanf("%d %d %d", &u, &v, &w);
			adj[u][v] = w;
		}

		for(k=0; k < n; k++){
		for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		}}}

		int ans = 0;
		for(i=0; i<n; i++){
			if(adj[i][e] <=t || i==e)
				ans++;
		}
		printf("%d\n", ans);
		if(tc)
			printf("\n");
	}
}


/*
	#include <bits/stdc++.h>
	using namespace std;

	#define INF 1e6
	typedef vector<int> vi;
	typedef pair<int, int> ii;
	typedef vector<ii> vii;

	vector<vii> adj;
	vi dist;

	int main(){
		int t, tc; scanf("%d", &t);
		for(tc = 1; tc <= t; tc++){
			adj.clear(); dist.clear();
			int n,e,t,m;
			scanf("%d\n%d\n%d\n%d\n", &n, &e, &t, &m);
			--e; n++;
			adj.assign(n, vii());
			dist.assign(n, INF);
	//		int m; scanf("%d", &m);
			int a, b, wt, i,j,k;
			for(i=0; i<m; i++){
				scanf("%d %d %d", &a, &b, &wt);
				--a; --b;
				adj[a].push_back(ii(b,wt));
			}
			vi ans;

			priority_queue<ii, vector<ii>, greater<ii> > pq;

			for(k=0; k<n; k++){
				dist.assign(n, INF);
				dist[k] = 0;
				pq.push(ii(dist[k],k));

				while(!pq.empty()){
					ii front = pq.top(); pq.pop();
					int wt = front.first, v = front.second;
					if(v == e) break;
					
					for(i=0; i<adj[v].size(); i++){	
						if(dist[adj[v][i].first] > dist[v]+adj[v][i].second){
							dist[adj[v][i].first] = dist[v] + adj[v][i].second;
							pq.push(ii(dist[adj[v][i].first], adj[v][i].first));
						}
					}
					
				}
				ans.push_back(dist[e]);

				while(!pq.empty()){
					ii front = pq.top(); pq.pop();
				}
			}

			sort(ans.begin(), ans.end());
			/*for(i=0; i<ans.size(); i++){
				printf("%d->", ans[i]);
			}
			printf("\n");
			
			int nmice = upper_bound(ans.begin(), ans.end(), t)-ans.begin();
			printf("%d\n", nmice);
			
			if(t!=tc)
				printf("\n");
		}	
	}*/