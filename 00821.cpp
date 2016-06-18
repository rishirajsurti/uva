#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 1000000000

int adj[101][101];
int inc[101];

int main(){
	int a, b, x, y, tc = 1;
	while(scanf("%d %d", &a, &b), (a||b)){
		//memset(adj, 0, sizeof adj);
		int i,j,k;
		for(i=0; i<=100; i++){
			for(j=0; j<=100; j++)
				adj[i][j] = INF;
			adj[i][i] = 0;
			inc[i] = 0;
		}

		adj[a][b] = 1;
		inc[a] = inc[b] = 1;

		while(scanf("%d %d", &x, &y), (x||y)){
			adj[x][y] = 1;
			inc[x] = inc[y] = 1;
		}
		
/*		for(i=1; i<=100; i++){
			if(inc[i]){
				for(j=1; j<=100; j++)
					if(inc[j])
						printf("%d ", adj[i][j]);
				printf("\n");
			}
		}
*/		int path_length=0, pairs=0;

		for(k=1; k<=100; k++){
			for(i=1; i<=100; i++){
				for(j=1; j<=100; j++){
					if(inc[i] && inc[j] && inc[k])
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

/*		for(i=1; i<=100; i++){
			if(inc[i]){
				for(j=1; j<=100; j++)
					if(inc[j])
						printf("%d ", adj[i][j]);
				printf("\n");
			}
		}*/
		for(i=1; i<=100; i++){
			for(j=1; j<=100; j++){
				if(i!=j && inc[i] && inc[j]){
					path_length += adj[i][j];
					pairs++;
				}
			}
		}

		float ans;
		ans = (1.0 * (float)path_length) / (1.0 * (float)pairs);
		printf("Case %d: average length between pages = %.3f clicks\n",tc++, ans);
	}
}