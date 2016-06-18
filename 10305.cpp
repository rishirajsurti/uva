#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int n,m;

typedef vector<int> vi;


vector<vi> adj;
map<int, bool> vis;
vector<int> toposort;

bool validTask(int t){
	for(int i = 0 ; i < adj[t].size(); i++ ){
		if(vis[adj[t][i]])
			return false;
	}
	return true;
}

void dfs(int t){
	
	for(int i = 0; i < adj[t].size(); i++){
		if(!vis[adj[t][i]])
				dfs(adj[t][i]);
		}
	//printf("%d->",t );
	vis[t] = true;
	toposort.push_back(t);
}

int main(){

	while(scanf("%d %d", &n, &m), (n||m)){
		adj.clear();
		adj.assign(n+1, vi());
		int i,j, x, y;
		for(i=0; i<m; i++){
			scanf("%d %d", &x, &y);
			
			adj[x].push_back(y);
		}
		toposort.clear();
		vis.clear();
		for(i = 1; i<=n; i++){
			if(!vis[i])
				dfs(i);
		}

		reverse(toposort.begin(), toposort.end());
		
		for(i=0; i< toposort.size(); i++){
			if(i > 0)
				printf(" ");
			printf("%d", toposort[i]);
		}
		printf("\n");
	}
}