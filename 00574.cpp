#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,n; 
	while(scanf("%d %d", &t, &n), (t||n)){
		printf("Sums of %d:\n", t);
		int i,j;
		vector<int> a(n), b;
		vector< vector<int> > ll;
		for(i=0; i<n; i++) scanf("%d", &a[i]);

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		
		bool found = false;

		for(i=0; i<(1<<n); i++){
			int length = 0;
			b.clear();
			for(j=0; j<n; j++){
				if(i & (1<<j)){
					length+=a[j];
					b.push_back(a[j]);
				}
			}
			if(length == t){
				found = true;
		//		int k;
				if(find(ll.begin(), ll.end(), b) == ll.end()){
					ll.push_back(b);
					/*for(k=0; k<b.size(); k++){
						if(k>0) printf("+");
						printf("%d", b[k]);
					}
					printf("\n");*/
				}
			}
			
		}
		if(!found) printf("NONE\n");
		else{
		sort(ll.begin(), ll.end());
			reverse(ll.begin(), ll.end());
			for(i=0; i<ll.size(); i++){
				b = ll[i];
				int k;
				for(k=0; k<b.size(); k++){
						if(k>0) printf("+");
						printf("%d", b[k]);
					}
					printf("\n");
			}
		}

		
	}
	return 0;
}
/*#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

int a[16];
int t,n;
vi ai;

void backtrack(int sum, int index){

	if(sum > t)
		return;

	if(sum == t){
		for(int i = 0; i < ai.size(); i++)
			printf("%d ",ai[i]);
	}

	int r;
	for(r = index ; r < n; r++){
		backtrack(sum+a[r], r);
	}
}
	

int main(){
	
	while(scanf("%d %d", &t, &n), (t||n)){
		int i;
		for(i = 0; i < n; scanf("%d", &a[i++]));
		sort(a, a+n); reverse(a, a+n);
		backtrack(0,0);
	}	

}*/