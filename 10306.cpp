#include <bits/stdc++.h>
using namespace std;

#define FOR(a,b)	for(int a = 0; a < b; a++)
#define FORI(a, b, c) for(int a = b; a < c; a++)
#define INF 1e6

int dp[328][328];
int x[64], y[64];
int sqr(int x){ return (x*x); }

int main(){
	int n; scanf("%d", &n);
	for(int m,s; n-- && scanf("%d %d", &m, &s) == 2; ){
		int minc = INF;

		FOR(i, m) scanf("%d %d", &x[i], &y[i]);
		FOR(i, s+1) FOR(j, s+1) dp[i][j] = INF;
		dp[0][0] = 0;

		FOR(i, m) FORI(j, x[i], s+1) FORI(k, y[i], s+1)
			dp[j][k] = min(dp[j-x[i]][k-y[i]]+1, dp[j][k]);

		FOR(i, s+1) FOR(j, s+1)
			if(sqr(i) + sqr(j) == sqr(s))
				minc = min(minc, dp[i][j]);

		if(minc == INF) printf("not possible\n");
		else printf("%d\n", minc);
	}
	return 0;
}