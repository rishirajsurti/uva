#include <cstdio>
#include <algorithm>
using namespace std;

int a[2048],n, lis[2048], lds[2048];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		int i,j;
		for(i=0; i<n; i++) 
			scanf("%d", &a[i]), lis[i]=lds[i] = 1;

		for(i=n-1; i >=0; i--)
		for(j=i-1; j>=0; j--){
			if(a[i] > a[j]) lis[j] = max(lis[j], lis[i]+1);
			else if(a[j] > a[i]) lds[j] = max(lds[j], lds[i]+1);
		}
		
		
		int ans=0;
		for(i=0; i<n; i++)
			ans = max(ans, lis[i]+lds[i] -1);
		printf("%d\n", ans);
	}
	return 0;

}