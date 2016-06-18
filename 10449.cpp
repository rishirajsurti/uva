#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e6

int a[202][202], b[202], r;

int main(){
	int n, tc = 1; 

	while(scanf("%d", &n) != EOF){
	printf("Set #%d\n", tc++);
	int i,j,k, x, y;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			a[i][j] = INF;
		}
		a[i][i] = 0;
	}

	for(i=0; i<n; i++) scanf("%d", &b[i]);
	scanf("%d", &r);
	
	for(i=0; i < r; i++){
		scanf("%d %d", &x, &y);
		--x; --y;
		a[x][y] = b[y] - b[x];
	}

	for(k=0; k<n-1; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
	int q, ans;
	scanf("%d", &q);
	for(i=0; i<q; i++){
		scanf("%d", &x);
		ans = INF;
		for(j=0; j<n; j++)
			ans = min(ans, a[x][j]);
		printf("%d\n",ans );
		}
	}
	return 0;
}