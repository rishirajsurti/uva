#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1
typedef vector<int> vi;
vector<vi> adj;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;


void articulationPoint(int u){
	//printf("Visiting %d\n", u);
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

	int i;
	for(i=0; i<(int)adj[u].size(); i++){
		int v = adj[u][i];

		if(dfs_num[v] == DFS_WHITE){

			dfs_parent[v] = u;
			if( u == dfsRoot) rootChildren++;
			
			articulationPoint(v);

			if(dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int n;
	char c;
	while(scanf("%d", &n), n){
		int s,id=1;
		int i,j;
		adj.assign(n, vi());

		while(scanf("%d%c", &s, &c) && s!=0 && c!='\n'){
			--s;
			while(scanf("%d%c", &id, &c) && c != '\n'){
				adj[s].push_back(--id);
				adj[id].push_back(s);
			}
			adj[s].push_back(--id);
			adj[id].push_back(s);
		}

		/*for(i =0; i < n; i++){
			printf("%d: ",i );
			for(j = 0; j < adj[i].size(); j++)
				printf("%d ",adj[i][j] );
			printf("\n");
		}*/
		dfsNumberCounter = 0;
		dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, -1);
		articulation_vertex.assign(n, 0);

		for(i=0; i<n; i++){
			if(dfs_num[i] == DFS_WHITE){
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1) ; 
			}
		}

		int ans =0;
		for(i = 0; i < n; i++)
			if(articulation_vertex[i])
				ans++;

		printf("%d\n", ans);
	}
}