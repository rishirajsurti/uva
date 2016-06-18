#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e6
int a[110][110], b[110];

int main(){
	int n; 
	while(scanf("%d", &n) && (n!=-1)){
		int i,j,k;
		for(i=0; i<n; i++){
			for(j=0; j<n; j++)
				a[i][j] = INF;
			a[i][i] = 0;
		}
		int e, neighbors, start=-1, finish=-1, x;
		
		for(i=0; i<n; i++){
			scanf("%d %d", &e, &neighbors);
			if(e==0){
				if(start == -1) start = i;
				else finish = i;
			}

			b[i] = e;
			for(j=0; j<neighbors; j++){
				scanf("%d", &x); --x;
				a[i][x] = 1; //update later
			}
		}

		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(a[i][j] == 1)
					a[i][j] = b[j];
			}
		}
		
//		vi dist(n, INF); dist[start] = 0;

		for(k=0; k<n-1; k++)
			for(i=0; i<n; i++)
				for(j=0; j<n; j++)
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

		bool hasNegativeCycle = false;
		if(a[start][finish] >= 0)
			printf("hopeless\n");
		else
			printf("winnable\n");

	}
	return 0;
}