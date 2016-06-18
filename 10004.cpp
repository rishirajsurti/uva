#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;
vi bfs_col;
map<int, bool> vis;

bool bfs(int u, int color){
	bfs_col[u] = color;
	bool ans=true;
	int i,v;
	queue<int> q;
	q.push(u);

	while(!q.empty() && ans){
		v = q.front(); q.pop();
//		printf("%d-> ",v );
		for(i=0; i<adj[v].size(); i++){
			if(bfs_col[adj[v][i]] == bfs_col[v]){
				ans = false;
				break;
			}
			else if(!vis[adj[v][i]]){				
				bfs_col[adj[v][i]] = 1 - bfs_col[v];
				vis[adj[v][i]] = true;
				q.push(adj[v][i]);
			}
		}
	}
	return ans;
}

int main(){
	int n;
	while(scanf("%d",&n), n){
		adj.clear();
		adj.assign(n, vi());
		bfs_col.clear();
		bfs_col.assign(n, -1);
		vis.clear();
		int l; scanf("%d", &l);
		int i,j,x,y;
		
		for(i=0; i<l; i++){
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		
		if(bfs(0, 0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}