#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main(){
	int N,i;
	while(scanf("%d", &N), N){
		for(i=0; i<N; i++)
			scanf("%d", &a[i]);
		
		int curSum = 0, maxSum = 0;

		for(i=0; i<N; i++){
			curSum += a[i];
			if(curSum > maxSum)
				maxSum = curSum;
			if(curSum < 0)
				curSum = 0;
			}
		if(maxSum <= 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n",maxSum );
	}
	return 0;
}