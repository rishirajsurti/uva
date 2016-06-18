#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
int grid[10][10];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int i,j;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d", &grid[i][j]);

		int *permutation;
		permutation = new int[n];
		for(i=0; i<n; i++)
			permutation[i] = i;

		int min = INT_MAX;

		do{
			int temp=0;
			for(i=0; i<n; i++)
				temp += grid[i][permutation[i]];

			if(temp < min)
				min = temp;
		} while(next_permutation(permutation, permutation+n));
		
		printf("%d\n", min);
	}
}