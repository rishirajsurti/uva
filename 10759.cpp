#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned long long llu;

llu gcd(llu a, llu b){
	return (b==0 ? a: gcd(b, a%b));
}

llu dp[26][151];

void initialize(){
	//dp: (dice left to throw, current sum)
	memset(dp, 0, sizeof dp);
	//start from (n, 0)
	dp[0][0] = 1;

	int n, i,t;
	for(n=1; n <=25; n++){
		for(i=0; i<=150; i++){
			for(t=1; t<=6 && i+t <= 150; t++){
				dp[n][i+t] += dp[n-1][i];
			}
		}
	}
	for(n=0; n<=25; n++){
		for(i=150; i>0; i--)
			dp[n][i-1] += dp[n][i];
	}
	/*int i,j,t;
	int cur=n, sum=0;
	dp[cur][sum] = 0;
	int ans =0;
	for(i=25; i>=0; i--){
		for(j=0; j<= 150; j++){
			for(t=1; t<=6 && j+t <=150; t++){
				dp[i-1][j+t] += dp[i][j]
			}
		}
	}*/

}

int main(){
	int n, x;
	while(scanf("%d %d", &n, &x), (n||x)){
		initialize();
		llu a = dp[n][x];
		llu b = dp[n][0];
		llu g = gcd(a,b);
		a = a / g; b = b / g;
		if(b==1)
			printf("%llu\n", a);
		else
			printf("%llu/%llu\n", a,b);
	}
}