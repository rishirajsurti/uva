#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

#define INF 0xffff

typedef vector<int> vi;
typedef pair<string, string> ss;
vector<vi> adj;
vector<string> e; //elements;

vector< ss > data;
map<string, int> mapper;
vi visited;
int a[50][50];
int p,r;
void initialize(){
	int i,j;
	for(i=0; i<50; i++){
		for(j=0; j<50; j++)
			a[i][j] = INF;
		a[i][i] = 1;
	}
}

int dfs(int u){
	visited[u] = 1;
	int i,j;
	for(i=0; i<adj[u].size(); i++){
		if(!visited[adj[u][i]])
			dfs(adj[u][i]);
	}
}

bool ok(){
	dfs(0);
	int i;
	for(i=0; i<p; i++)
		if(!visited[i])
			return false;
	return true;
}

int main(){
	int tc=1;
	while(scanf("%d %d", &p, &r), (r||p)){
		adj.assign(p, vi());
		visited.assign(p,0);
		e.clear();
		data.clear();
		mapper.clear();
		string from, to;
		int i,j,k,idx1, idx2;
		int x, y;
		initialize();
		for(i=0; i<r; i++){
			cin>>from>>to;
			if(find(e.begin(), e.end(), from)==e.end()){
				e.push_back(from);
				mapper[from] = e.size()-1;
			}

			if(find(e.begin(), e.end(), to)==e.end()){
				e.push_back(to);
				mapper[to] = e.size()-1;
			}

			data.push_back(ss(from, to));
			x = mapper[from];
			y = mapper[to];
			a[x][y] = a[y][x] = 1;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

/*		for(i=0; i<data.size(); i++){
			ss key = data[i];
			idx1 = mapper[key.first];
			idx2 = mapper[key.second];
			a[idx1][idx2] = a[idx2][idx1] = 1;
			adj[idx1].push_back(idx2);
			adj[idx2].push_back(idx1);
		}*/

		bool isConnected = ok();
		int maxd = -1;

		for(k=0; k<p; k++){
			for(i=0; i<p; i++){
				for(j=0; j<p; j++){

					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
/*					if(a[i][j]!=INF)
						maxd = max(maxd, a[i][j]);
*/					}
				}
			}
		
		for(i=0; i<p; i++)
			for(j=0; j<p; j++)
				maxd = max(maxd, a[i][j]);

		if(maxd == INF)
			printf("Network %d: DISCONNECTED\n",tc++ );
		else
			printf("Network %d: %d\n",tc++, maxd);
		printf("\n");
	}
	//printf("Network %d: DISCONNECTED\n",tc++ );
	return 0;
}