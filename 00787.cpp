#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int a[105];
int dp[105][105];
int maxP(int left, int right){

	/*//brute force;
	//(giving WA);
	int j,k, curP, maxProduct = -999999;
	for(j=left; j<right; j++){
		//sequence starting from j;
		curP = 1;
		for(k = j; k < right; k++){
			curP = curP * a[k];
			maxProduct =  max(maxProduct, curP);
		}
	}
	return maxProduct;*/

	if(left == right)	return dp[left][right] = a[105];
	if(dp[left][right] != -1)	return dp[left][right];

	


}

int main(){
	int n, i=1;
	while(scanf("%d", &n) != EOF){
		
		if(n == -999999){
			
			memset(dp, -1, sizeof dp);
			printf("%d\n", maxP(1, i));
			
			i = 1;
		}
		else{
			a[i++] = n;
		}
	}
}