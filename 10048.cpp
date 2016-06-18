#include <cstdio>
#include <algorithm>

#define INF 1e6
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

int main(){
	int n, m, q, cases = 0;
	while(scanf("%d %d %d", &n, &m, &q) == 3){
		if( n== 0) break;
		int f[101][101], i,j,k,x,y,b;

		for(i=1; i<=n; f[i][i]=0, i++){
			for(j=1; j<=n; j++)
				f[i][j] = INF;
		}

		while(m--){
			scanf("%d %d %d", &x, &y, &b);
			f[x][y] = min(f[x][y], b);
			f[y][x] = f[x][y];
		}

		for(k=1; k<=n; k++)
			for(i=1; i<=n; i++)
				for(j=1; j<=n; j++)
					f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));

		if(cases)
			printf("\n");
		printf("Case #%d\n", ++cases);

		while(q--){
			scanf("%d %d", &x, &y);
			if(f[x][y] != INF)
				printf("%d\n", f[x][y]);
			else
				printf("no path\n");
		}

	}
	return 0;
}
/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e6
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vi P, R;
vector<vii> adj;

int v, e, q;
int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}

bool isSameSet(int x, int y){
	x = findp(x), y = findp(y);
	return x == y;
}

void unionSet(int x, int y){
	x = findp(x), y = findp(y);
	if(x == y)
		return;
	if(R[x] > R[y]){
		P[y] = x; R[x] += R[y];
	}
	else{
		P[x] = y; R[y] += R[x];
	}
}

int dfs(int u, int v){
	int ans = INF;
	int i;
	vi visited(v, 0);
	visited[u] = 1;
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(ans, u));
	
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int wt = front.first; 
		int vtx = front.second;
		ans = min(ans, wt);
		visited[vtx] = 1;
		if(vtx == v)
			break;

		for(i=0; i<adj[vtx].size(); i++){
			ii vv = adj[vtx][i];
			if(!visited[vv.first]){
				pq.push(ii(vv.second, vv.first));
			}
		}
	}
	return ans;
}

int main(){

	int tc=1;
	while(scanf("%d %d %d", &v, &e, &q), (v||e||q)){
		adj.clear(); adj.assign(v, vii());
		R.clear(); R.assign(v, 1);
		P.clear();	P.assign(v, 0);
		int i,j;
		for(i=0; i<v; i++) P[i] = i;

		int u, v, wt;
		vector< pair<int, ii> > Edgelist;

		for(i=0; i<e; i++){
			scanf("%d %d %d", &u, &v, &wt);
			--u; --v;
			Edgelist.push_back(make_pair(wt, ii(u,v)));
		}

		sort(Edgelist.begin(), Edgelist.end());

		for(i=0; i<e; i++){
			pair<int, ii> front = Edgelist[i];
			wt = front.first;
			u = front.second.first;
			v = front.second.second;
			
			if(!isSameSet(u,v)){
				adj[u].push_back(ii(v,wt));
				adj[v].push_back(ii(u,wt));
				unionSet(u,v);
			}
		}
		printf("Case #%d\n", tc++);
		for(i = 0; i < q; i++){
			scanf("%d %d", &u, &v);
			int ans = dfs(--u,--v);
			if(ans == INF)
				printf("no path\n");
			else
				printf("%d\n", ans);
		}
		printf("\n");
	}
	return 0;
}*/