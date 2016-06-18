#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int p[10005];
int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		int i,j, x, y, m;
		for(i=0; i<N; i++)
			scanf("%d", &p[i]);

		sort(p, p+N);
		scanf("%d", &m);
		i = 0; j = N-1;
		while(i<=j){
			if(p[i] + p[j] == m){
				x = i, y = j;
				i++; j--;
			}
			else{
				if(p[i]+p[j] > m)
					j--;
				else
					i++;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",p[x],p[y] );
		cin.ignore();
	}
	return 0;
}