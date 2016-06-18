#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1e7

int a[100][100];
int visited[100];
void initialize(){
	int i,j;
	for(i=0;i<100; i++){
		for(j=0; j<100; j++)
			a[i][j] = INF;
		a[i][i] = 0;
		visited[i] = 0;
	}
}
int main(){
	int t, tc = 1; scanf("%d", &t);
	while(t--){
		initialize();
		int n; scanf("%d", &n);
		int r; scanf("%d", &r);
		int i,j,k, u,v;
		for(i=0; i<r; i++){
			scanf("%d %d", &u, &v);
			a[u][v] = a[v][u] = 1;
		}
		
		for(k=0; k<n; k++){
			for(i=0; i<n; i++){
				for(j=0; j<n; j++)
					a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
			}
		}
/*		int dist = 0, min_dist;

		for(j=0; j<n; j++){
			min_dist = INF;

			for(i=0; i<n; i++){
				if(!visited[i] && a[s][i] <= min_dist){
					v = i; min_dist = a[s][i];
				}
			}
			s = v;
			visited[v] = 1;
			dist += min_dist;
		}*/

		int s,d;
		scanf("%d %d",&s, &d);
		int ans=-1;

		for(i=0; i<n; i++)
			ans = max(ans, a[s][i] + a[i][d]);

		printf("Case %d: %d\n", tc++, ans);
	}
	return 0;
}