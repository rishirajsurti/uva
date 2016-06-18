#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;

int main(){
	int v;
	while(scanf("%d", &v), v){
		adj.assign(v, vi());
//		int e; scanf("%d", &e);
		int i, a, b, u;

		while(scanf("%d %d", &a, &b), (a||b)){
			adj[--a].push_back(--b);
			adj[b].push_back(a);
		}

		bool isBipartite = true;
		vi color(v, -1);

		queue<int> q;
		q.push(0);
		color[0] = 0;

		while(!q.empty() && isBipartite){
			u = q.front(); q.pop();
			for(i=0; i<adj[u].size(); i++){
				if(color[adj[u][i]] == -1){
					color[adj[u][i]] = 1 - color[u];
					q.push(adj[u][i]);
				}
				else if(color[adj[u][i]] == color[u]){
					isBipartite = false;
					break;
				}
			}
		}

		if(isBipartite)
			printf("YES\n");
		else
			printf("NO\n");
	}
}