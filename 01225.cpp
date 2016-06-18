#include <cstdio>
#include <cstring>
using namespace std;

int a[10];

void calc(int n){
	int i,j;
	for(i=1; i<=n; i++){
		j = i;
		while(j>0){
			int mod = j%10;
			a[mod]++;
			j /= 10;
		}
	}
	return;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; 
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		calc(n);
		int i; 
		for(i=0; i<10; i++){
			if(i > 0 ) printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
}