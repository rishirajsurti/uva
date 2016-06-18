#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

int a[1000][1000];
int dist[1000][1000];

int d[4][2] = {
	{0, -1}, {1,0}, {0,1}, {-1, 0}
};

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n,m; scanf("%d %d", &n, &m);
		int i,j;
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				scanf("%d", &a[i][j]);
				dist[i][j] = INF;
			}
		}

		i=j=0; dist[i][j] = 0;
		priority_queue<iii, vector<iii>, greater<iii> > pq;

		pq.push(make_pair(0, ii(0,0)));
		dist[0][0] = a[0][0];

		while(!pq.empty()){
			iii front = pq.top(); pq.pop();
			int wt = front.first;
			int x,y;
			x = front.second.first; y = front.second.second;

			for(i=0; i<4; i++){
				int ni = x+d[i][0], nj = y+d[i][1];
				if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

				if(dist[x][y]+a[ni][nj] < dist[ni][nj]){
					dist[ni][nj] = dist[x][y] + a[ni][nj];
					pq.push(make_pair(dist[ni][nj], ii(ni,nj)));
				}
			}
		}

		printf("%d\n", dist[n-1][m-1]);
				
	}
}