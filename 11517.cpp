#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m, i , j;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m , &n);
		int dp[20000] = {}, mx, x;
		dp[0] = 1, mx = 0;
		for(i=0; i<n; i++){
			scanf("%d", &x);
			mx+= x;
			if(mx > 20000) mx = 19999;
			for(j = mx; j>=x; j--){
				if(dp[j] == 0 || dp[j] > dp[j-x] + 1){
					if(dp[j-x]){
						dp[j] = dp[j-x]+1;
					}
				}
			}
		}
		while(dp[m] == 0) m++;
		printf("%d %d\n", m, dp[m] - 1);
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

#define FOR(a,b)	for(int a = 0; a < b; a++)
#define FORI(a,b,c)	for(int a = b; a < c; a++)

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int amt; scanf("%d", &amt);
		int n; scanf("%d", &n);
		vector<int> a(n);
		FOR(i,n) scanf("%d", &a[i]);
		int dp[10001][101];
		memset(dp, 0, sizeof dp);
		
		int i,j;
		for(i=0; i<n; i++){
			for(j=a[i]; j<=amt; j++){
				dp[j][i] = min()
			}
		}
	}
}*/