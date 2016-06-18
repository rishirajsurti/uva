#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		++n; 
		vi c(n);
		int i;
		for(i=0; i<n; scanf("%d", &c[i++]));
		int d,k; scanf("%d %d", &d, &k);

		long long sum = 0;

		for(int j = 1; j <= k; j++){
			sum+=j*d;

			if(sum>=k){
				long long an = 0;
				for(int x = 0; x < c.size(); x++){
					an += ((long long)c[x])*((long long)pow((float)j,float(x)));
				}
			printf("%lld\n",an);
			break;

			}
		}
	}
	return 0;
}