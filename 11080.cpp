#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define INF 1e6
typedef vector<int> vi;
vector<vi> adj;

vi color;
bool isBipartite;
queue<int> q;
	
int checkBipartite(int s){
	q.push(s); color[s] = 1;
	int ans = 0;
	isBipartite = true;
	int i;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		if(color[u] == 1) ans++;
		for(i=0; i<adj[u].size(); i++){
			int w = adj[u][i];
			if(color[w]==-1){
				color[w] = 1 - color[u];
				q.push(w);
			}
			else if(color[w] == color[u]){
				isBipartite = false;
				break;
			}
		}
	}
	return ans;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int v, e;
		scanf("%d %d", &v, &e);
		adj.assign(v, vi());
		int i,j, a,b;
		for(i=0; i<e; i++){
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		color.assign(v, -1);
		int sum=0;
		bool ok = true;

		for(i=0; i<v; i++){
			if(color[i] == -1){
				sum += checkBipartite(i);
				ok = ok & isBipartite;
			}
		
		}
		
		if(ok)
			printf("%d\n", sum);
		else
			printf("-1\n");
	}
}
/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int v, e;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> adj;
vector<bool> ptd;
//priority_queue< pair<int, int> > pq;
map<int, int> m;

vector< pair<int, int> > vpii;



void protect(int u){
	int i;
	ptd[u] = true;
	for(i=0; i<adj[u].size(); i++)
		ptd[adj[u][i]] = true;
}

bool isValid(int u){

	if(ptd[u] == true)
		return false;

	int i;
	for(i=0; i<adj[u].size(); i++){
		if(ptd[adj[u][i]] == true)
			return false;
	}
	return true;
}

int bfs(){
	int u,i;
	int ans = 0;

	for(i = 0; i < vpii.size(); i++){
		ii v = vpii[i];
		u = v.second;
		if(isValid(u)){
			printf("protect %d\n", u); 
			protect(u);
			ans++;
		}
	}
	return ans;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		
		scanf("%d %d", &v, &e);
	
		adj.assign(v, vi());
	
		ptd.assign(v, false);
		

		int f,t,i,j;
		for(i = 0; i < v; i++)
			m[i] = 0;

		for(i=0; i<e; i++){
			scanf("%d %d", &f, &t);
			adj[f].push_back(t);
			adj[t].push_back(f);
			m[f]++;
			m[t]++;
//			printf("%d %d\n", m[f], m[t]);
		}

		map<int, int>::iterator it;
		for(it = m.begin(); it != m.end(); it++){
			vpii.push_back(make_pair(it->second, it->first));
		}

		sort(vpii.begin(), vpii.end());
		reverse(vpii.begin(), vpii.end());
		bool ok = true;

		int sum = bfs();
		for(i=0; i<v; i++){
			if(!ptd[i])
				ok = false;
		}

		if(e == 0)
			printf("%d\n", v);
		else if(ok)
			printf("%d\n", sum);
		else
			printf("-1\n");

		adj.clear();
		ptd.clear();
		m.clear();
		vpii.clear();
	}
	return 0;
}*/