#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n),n){
		vector<int> a(n,0);
		int i,j;
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());

		int prev = a[0];
		int count=1, result=0;
		for(i=1; i<n; i++){
			if(a[i] == prev)
				count++;
			else{
				prev = a[i];
				if(count > result)
					result = count;
				count = 1;
			}
		}
		if(count > result) result = count;
		
		printf("%d\n", result);
		for(i=0; i<result; i++){
			for(j = i; j < n; j += result){
				if(j>i)
					printf(" ");
				printf("%d",a[j] );
			}
			printf("\n");
		}
	printf("\n");
	}
	return 0;
}