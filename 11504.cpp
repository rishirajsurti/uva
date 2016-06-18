#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;

vi visited, toposort;

void dfs(int u){
	visited[u] = 1;
	 int i;
	 for(i=0; i<adj[u].size(); i++){
	 	if(!visited[adj[u][i]])
	 		dfs(adj[u][i]);
	 }
	 toposort.push_back(u);
}

int main(){
	int tc; scanf("%d", &tc);
	while(tc--){
		int n,m;
		scanf("%d %d", &n, &m);
		//adj.clear();
		adj.assign(n, vi());
		int i,j, a, b;
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			--a; --b;
			adj[a].push_back(b);
		}
		visited.clear();
		toposort.clear();
		visited.assign(n, 0);
		for(i=0; i<n; i++){
			if(!visited[i])
				dfs(i);
		}
		reverse(toposort.begin(), toposort.end());

		visited.assign(n, 0);
		int ans =0;
		for(i=0; i<toposort.size(); i++){
			if(!visited[toposort[i]]){
				dfs(toposort[i]);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}

/*#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef vector<int> vi;
vector<vi> adj;

vi dfs_num, dfs_low, visited, S;
int dfsNumberCounter, numSCC;
vi dfs_visited, pushed;
int ans;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	visited[u] = 1;
	S.push_back(u);
	int j;
	for(j=0; j<adj[u].size(); j++){

		int v = adj[u][j];

		if(dfs_num[v] == DFS_WHITE)
			tarjanSCC(v);

		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_num[u] == dfs_low[u]){
		pushed[u] = 1;
		numSCC++;
		while(1){
			int v = S.back(); S.pop_back();
			visited[v] = 0;
			if(u == v)	
				break;
		}
	}
}

void dfs(int u){
	visited[u] = 1;
	int i;
	for(i=0; i<adj[u].size(); i++){
		if(!visited[adj[u][i]])
			dfs(adj[u][i]);
	}
}

int main(){

	int tc; scanf("%d", &tc);
	while(tc--){
		int n,m;
		scanf("%d %d", &n, &m);
		//adj.clear();
		adj.assign(n, vi());
		int i,j, a, b;
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			--a; --b;
			adj[a].push_back(b);
		}

/*		for(i=0; i<n; i++){
			printf("%d: ",i );
			for(j = 0; j <adj[i].size(); j++)
				printf("%d ",adj[i][j] );
			printf("\n");
		}
*/
/*		dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		pushed.assign(n, 0);
		dfsNumberCounter = 0;
		numSCC = 0;
		S.clear();

		// run tarjan
		for(i=0; i<n; i++){
			if(dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		}
		
		visited.assign(n, 0);
		//for each root of scc push it
		ans = 0;
		for(i=0; i<n; i++){
			if(!visited[i] && pushed[i]){
				ans++;
				dfs(i);
			}
		}
		
		printf("%d\n", ans++);
	}
}*/