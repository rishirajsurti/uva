#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
#include <climits>
using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int n2 = 2*n;
		int a[n2][n2], s[n2][n2];
		int i,j,i1,j1;

		for(i=0; i< n; i++)
		for(j=0; j< n; j++){
			scanf("%d", &a[i][j]);
			a[i+n][j] = a[i][j+n] = a[i+n][j+n] = a[i][j];
		}
		int sum;

		for(i=0; i<n2; i++)
		for(j=0; j<n2; j++){
			sum = a[i][j];
			if(i > 0) sum += s[i-1][j];
			if(j > 0) sum += s[i][j-1];
			if(i > 0 && j > 0) sum -= s[i-1][j-1];
			s[i][j] = sum;
		}
		int max_sum = INT_MIN;

		for(i=0; i<n2; i++)
		for(j=0; j<n2; j++)
		for(i1=i; i1<n2; i1++)
		for(j1=j; j1<n2; j1++){

			sum = s[i1][j1];
			if(i > 0) sum -= s[i-1][j1];
			if(j > 0) sum -= s[i1][j-1];
			if(i > 0 && j > 0) sum += s[i-1][j-1];

			if(sum > max_sum) max_sum = sum;
		}

		printf("%d\n", max_sum);

	}
}