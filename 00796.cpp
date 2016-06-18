#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> adj;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
vii bridges;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPoint(int u){
	//printf("visit %d\n", u);
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

	int i;
	for(i=0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(dfs_num[v] == DFS_WHITE){

			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;

			articulationPoint(v);

			if(dfs_low[v] > dfs_num[u]){
				if(u > v)
					bridges.push_back(ii(v,u));
				else
					bridges.push_back(ii(u,v));
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){

		if(n==0){
			printf("0 critical links\n");
		}
		else{
		adj.assign(n, vi());
		int i,j, s, id, connections;

		for(i=0; i <n && n; i++){
			scanf("%d (%d)", &s, &connections);
			//printf("source %d, conn %d\n", s, connections);
			if(connections!=0){
			
			for(j = 0; j < connections && connections; j++){
				scanf("%d", &id);
			//	printf("id %d\n", id);
				adj[s].push_back(id);
				adj[id].push_back(s);
				}
			}
		}

/*		for(int i = 0; i < n; i++){
			printf("%d: ",i );
			for(j=0; j < adj[i].size(); j++)
				printf("%d ",adj[i][j] );
			printf("\n");
		}*/
		dfs_num.assign(n, DFS_WHITE);
		dfs_parent.assign(n, -1);
		articulation_vertex.assign(n, 0);
		dfs_low.assign(n, 0);
		dfsNumberCounter = 0;
		bridges.clear();
		for(i=0; i<n && n; i++){
			if(dfs_num[i] == DFS_WHITE){
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
			//	articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		if(bridges.size())	
			sort(bridges.begin(), bridges.end());
		int sz = bridges.size();
		printf("%d critical links\n", sz);
		for(i = 0 ; i < sz; i++){
			printf("%d - %d\n", bridges[i].first, bridges[i].second);
		}
		printf("\n");
		}
	}
	return 0;
}
/*#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> adj;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
vii bridges;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPoint(int u){
	//printf("visit %d\n", u);
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

	int i;
	for(i=0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(dfs_num[v] == DFS_WHITE){

			dfs_parent[v] = u;
			if(u == dfsRoot) rootChildren++;

			articulationPoint(v);

			if(dfs_low[v] > dfs_num[u]){
				if(u > v)
					bridges.push_back(ii(v,u));
				else
					bridges.push_back(ii(u,v));
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){

		if(n==0){
			printf("0 critical links\n");
		}
		else{
		adj.assign(n, vi());
		int i,j, s, id, connections;

		for(i=0; i <n && n; i++){
			scanf("%d (%d)", &s, &connections);
			//printf("source %d, conn %d\n", s, connections);
			if(connections!=0){
			
			for(j = 0; j < connections && connections; j++){
				scanf("%d", &id);
			//	printf("id %d\n", id);
				adj[s].push_back(id);
				adj[id].push_back(s);
				}
			}
		}

/*		for(int i = 0; i < n; i++){
			printf("%d: ",i );
			for(j=0; j < adj[i].size(); j++)
				printf("%d ",adj[i][j] );
			printf("\n");
		}*/
		dfs_num.assign(n, DFS_WHITE);
		dfs_parent.assign(n, -1);
		articulation_vertex.assign(n, 0);
		dfs_low.assign(n, 0);
		dfsNumberCounter = 0;
		bridges.clear();
		for(i=0; i<n && n; i++){
			if(dfs_num[i] == DFS_WHITE){
				dfsRoot = i; rootChildren = 0;
				articulationPoint(i);
			//	articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		if(bridges.size())	
			sort(bridges.begin(), bridges.end());
		int sz = bridges.size();
		printf("%d critical links\n", sz);
		for(i = 0 ; i < sz; i++){
			printf("%d - %d\n", bridges[i].first, bridges[i].second);
		}
		printf("\n");
		}
	}
	return 0;
}*/