#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define INF 1e6

int main(){
	int l,u,r, tc = 1;
	while(scanf("%d %d %d", &l, &u, &r), (l||r||u)){
		int i,j;
		vi rv(r,0);
		for(i=0; i<r; i++){
			scanf("%d",&rv[i]);
		}

		queue<int> q;
		vi dist(10000, INF);
		q.push(l); dist[l]=0;

		while(!q.empty()){
			int v = q.front(); q.pop();
			if(v==u) break;

			for(i=0; i<r; i++){
				int next = v+rv[i];
				if(next >= 10000) next = next % 10000;
				if((dist[v]+1 < dist[next])){
					dist[next] = dist[v]+1;
					q.push(next);
				}
			}
		}
		if(dist[u] == INF)
			printf("Case %d: Permanently Locked\n", tc++);
		else
			printf("Case %d: %d\n",tc++, dist[u]);
	}
	return 0;
}