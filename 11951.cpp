#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

unsigned long int k, max_cost=-1, sum, a[105][105];

int main(){
	int t,j=1;	scanf("%d\n", &t);
	while(t--){
		unsigned long int n,m,i,j,i1,j1, area;
		scanf("%lu %lu %lu", &n, &m, &k);
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				scanf("%lu", &a[i][j]);

				if(i > 0) a[i][j] += a[i-1][j];
				if(j > 0) a[i][j] += a[i][j-1];
				if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
			}
		}

		for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		for(i1=i; i1<n; i1++)
		for(j1=j; j1<m; j1++){
			sum = a[i1][j1];
			if(i > 0) sum -= a[i-1][j1];
			if(j > 0) sum -= a[i1][j-1];
			if(i > 0 && j > 0) sum += a[i-1][j-1];

			if(sum >= max_cost && sum <= k){
				max_cost = sum;
				area = abs((int)(i1-i))*abs((int)(j1-j));
			}
		}
		printf("Case #%lu: %lu %lu\n",j++, area, max_cost );
	}
	return 0;
}