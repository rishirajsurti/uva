#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, p; scanf("%d %d", &n, &p);
		int i,j;
		vector<int> a(p);
		for(i=0; i<p; i++) scanf("%d", &a[i]);
		bool ok = false;

		for(i=0; i<= ((1<<p)-1) && !ok; i++){
			int length = 0;
			for(j=0; j<p; j++){
				if(i & (1<<j))
					length+=a[j];
			}
			if(length == n)
				ok = true;
		}
		if(ok) printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}