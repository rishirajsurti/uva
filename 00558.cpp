#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define INF 1e6
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adj;
int a[1000][1000];
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int v,e; scanf("%d %d", &v, &e);
		adj.assign(v, vii());
		memset(a, 0, sizeof a);
		int i,j,k, x, y, wt;
		for(i=0; i<e; i++){
			scanf("%d %d %d", &x, &y, &wt);
			adj[x].push_back(ii(y,wt));
			a[x][y] = wt;
		}

		vi dist(v, INF);
		dist[0] = 0;

		for(k=0; k < v-1; k++)
			for(i=0; i<v; i++)
				for(j=0; j < adj[i].size(); j++){
					ii vtx = adj[i][j];
					dist[vtx.first] = min(dist[vtx.first], dist[i]+vtx.second);
				}

		bool hasNegativeCycle = false;

		for(i=0; i<v; i++){
			for(j=0; j< adj[i].size(); j++){
				ii vtx = adj[i][j];
				if(dist[vtx.first] > dist[i]+vtx.second)
					hasNegativeCycle = true;
			}
		}
		if(hasNegativeCycle)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}