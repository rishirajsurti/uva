#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[30001];
ull coin[5] = {1, 5, 10, 25, 50};
void ncount(){
	memset(dp, 0, sizeof dp);
	ull i,j;
	dp[0] = 1;

	for(i=0; i<5; i++){
		for(j=coin[i]; j<30001; j++)
			dp[j] += dp[j-coin[i]];
	}
}	
	
int main(){
	ull n; 
	ncount();
	while(scanf("%llu", &n) != EOF){
		if(dp[n] == 1)
			printf("There is only 1 way to produce %llu cents change.\n",n);	
		else
			printf("There are %llu ways to produce %llu cents change.\n", dp[n],n);
	}
	return 0;
}