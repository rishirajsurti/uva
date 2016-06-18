#include <cstdio>
#include <algorithm>
using namespace std;

int h[1048576], w[1048576], lis[1048576], lds[1048576];
int n;

int main(){
	int t; scanf("%d",&t);
	int tc;
	for(tc=1; tc<=t; tc++){
		int i,j; scanf("%d", &n);

		for(i=0; i<n; i++) scanf("%d", &h[i]);
		
		for(i=0; i<n; i++) scanf("%d", &w[i]);

		 //increasing
		for(i=0; i<n; i++){
		lis[i] = w[i];
		for(j=0; j<i; j++){
		 	if(h[j] < h[i]){
		 		lis[i] = max(lis[i], lis[j]+w[i]);
		 	}
		 }
		}
		
		//decreasing
		reverse(h, h+n);
		reverse(w, w+n);
		
		for(i=0; i<n; i++){
		lds[i] = w[i];
		for(j=0; j<i; j++){
			if(h[j] < h[i]){
				lds[i] = max(lds[i], lds[j]+w[i]);
			}
		}
		}	

		int inc = *max_element(lis, lis+n);
		int dec = *max_element(lds, lds+n);
		if(inc >= dec){
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc, inc, dec );
		}
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc,dec, inc );	
	}
}