#include <cstdio>
using namespace std;

int calc(int n){
 	int i,sum=0;
 	for(i=1; i<(n/2+1); i++){
 		if(n%i == 0)
 			sum += i;
 	}
 	if(sum == n)
 		return 0;
 	else if(n > sum)
 		return -1;
 	else if(n < sum)
 		return +1;
 }
int main(){
	int n;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&n), n){
		int ans = calc(n);
		if(ans == 0)
			printf("%5d  PERFECT\n",n );
		else if(ans > 0)
			printf("%5d  ABUNDANT\n", n);
		else
			printf("%5d  DEFICIENT\n",n);
	}

	printf("END OF OUTPUT\n");
	return 0;
}