#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int graph[50004];
bool vis[50004];

int dfs(int i){
	
	vis[i] = true;
	int tot = 0;
	if(graph[i]!= -1 && !vis[graph[i]])
		tot += 1 + dfs(graph[i]);

	vis[i] = false;
	return tot;
}

int main(){
	int t, tc;
	scanf("%d", &tc);
	for(t = 1; t <= tc; t++){
		int n; scanf("%d", &n);
		memset(graph, -1, sizeof graph);
		memset(vis, false, sizeof vis);

		int i,j,u,v;
		
		for(i=0; i<n; i++){
			scanf("%d %d", &u, &v);
			graph[--u] = --v;
		}
		int len, maxlen=-1, ans;
		for(i=0; i<n; i++){
			len = dfs(i);
			if(len > maxlen){
				maxlen = len;
				ans = i;
			}
		}
		printf("Case %d: %d\n", t, ++ans);
	}
	return 0;
}