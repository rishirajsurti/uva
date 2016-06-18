#include <cstdio>
#include <algorithm>
using namespace std;
unsigned int a,b,c,d,e,f,k,n;

unsigned int z[13];


int main(){

	for(k=0; scanf("%u", &n) && n; k++){
		if(k) printf("\n");

		for(a=0; a<n; scanf("%u", &z[a++]));
		sort(z, z+a);

		for(a = 0; a < n-5; a++)
		for(b = a+1; b < n-4; b++)
		for(c = b+1; c < n-3; c++)
		for(d = c+1; d < n-2; d++)
		for(e = d+1; e < n-1; e++)
		for(f = e+1; f < n; f++)
			printf("%u %u %u %u %u %u\n",z[a],z[b],z[c],z[d],z[e],z[f]);
	}
	return 0;
}
/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int main(){
	int k;
	while(scanf("%d", &k),k){
		int i,j;
		vector<int> a(k,0);
		for(i=0; i<k; i++)
			scanf("%d", &a[i]);

		queue<int> s;

		for(i=0; (i<(1<<k)); i++){
			if(__builtin_popcount(i)==6){
	//			printf("%d %d\n", i, __builtin_popcount(i));
				for(j=0; j<k; j++){
					if(i&(1<<j))
						s.push(a[j]);
				}
				while(!s.empty()){

					printf("%d",s.front() );
					if(s.size() > 1)
						printf(" ");
					s.pop();
				}
				printf("\n");
			}
		}
	printf("\n");
	}
	return 0;
}*/