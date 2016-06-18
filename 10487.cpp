	#include <iostream>
	#include <cstdio>
	#include <vector>
	#include <algorithm>
	using namespace std;

	int main(){
		int n, cases = 1;
		while(scanf("%d",&n),n){
			
			printf("Case %d:\n", cases++);

			int i,j,k,l;
				
			vector<int> a(n,0);
			for(i=0; i<n; i++)
				scanf("%d",&a[i]);

			sort(a.begin(), a.end());

			int m,query;
			scanf("%d",&m);

			for(i=0; i<m; i++){
				scanf("%d",&query);

				int sum=0;
				int min_diff = 9999999;
				int closest_sum;

				j=0; k=n-1;
				while(j<=k && a[j]!=a[k]){
					sum = a[j]+a[k];
					if(abs(sum-query) < min_diff){
						closest_sum = sum;
						min_diff = abs(sum-query);
					}

					if(sum > query)
						k--;
					else
						j++;

				}
				printf("Closest sum to %d is %d.\n",query, closest_sum );
			}
		}
		return 0;
	}