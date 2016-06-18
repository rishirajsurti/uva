#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<int, int> vii;

vector<vi> adj;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;


void articulationPoint(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

	int i;
	for(i=0; i<(int)adj[u].size(); i++){
		int v = adj[u][i];

		if(dfs_num[v] == DFS_WHITE){

			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;

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

void dfs(int u){
	dfs_num[u] = DFS_BLACK;
	int i;
	for(i=0; i<adj[u].size(); i++)
		if(dfs_num[adj[u][i]] == DFS_WHITE)
			dfs(adj[u][i]);
}

int main(){
	int n,m;
	while(scanf("%d %d", &n, &m), (n||m)){
		adj.assign(n, vi());
		int i,j, a, b;

		while(scanf("%d %d", &a, &b) && (a!=-1 && b!=-1)){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		/*dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, -1);
		dfsNumberCounter = 0;
		articulation_vertex.assign(n, 0);

		for(i=0; i<n; i++){
			if(dfs_num[i] == DFS_WHITE){
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
*/
/*		for(i=0; i<n; i++)
			if(articulation_vertex[i])
				printf("%d\n", i);
*/		
		priority_queue< pair<int, int> > pq;

		for(i=0; i<n; i++){
			
				int numCC = 0;

				dfs_num.assign(n, DFS_WHITE);
				dfs_num[i] = DFS_BLACK;

				for(j=0; j < n; j++){
					if(dfs_num[j] == DFS_WHITE){
						dfs(j);
						numCC++;
					}
				}
				pq.push(ii(numCC, -i));
			
		}

		for(i=0; i <m; i++){
			ii result = pq.top(); pq.pop();
			printf("%d %d\n", -result.second, result.first);
		}
	}
	return 0;
}