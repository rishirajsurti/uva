#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef vector<int> vi;
vector<vi> adj;

vi dfs_num, dfs_low, visited, S;
int dfsNumberCounter, numSCC;

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	visited[u] = 1;
	S.push_back(u);
	int i;
	for(i=0; i < adj[u].size(); i++){

		int v = adj[u][i];

		if(dfs_num[v] == DFS_WHITE)
			tarjanSCC(v);

		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_num[u] == dfs_low[u]){
		numSCC++;
		while(1){
			int vv = S.back(); S.pop_back();
			visited[vv] = 0;
			if(u == vv)
				break;
		}
	}
}

int main(){
	int n,m;
	while(scanf("%d %d", &n, &m), (n||m)){
		adj.assign(n, vi());
		int i,j, v, w, p;

		for(i=0; i<m; i++){
			scanf("%d %d %d", &v, &w, &p);
			--v; --w;
			adj[v].push_back(w);
			if(p==2)
				adj[w].push_back(v);
		}

		dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumberCounter = 0;
		numSCC = 0;
		S.clear();
		
		for(i=0; i<n; i++){
			if(dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		}

		printf("%d\n", (numSCC == 1) ? 1 : 0);
	}
	return 0;
}