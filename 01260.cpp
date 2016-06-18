#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> a(n,0);
		int sum = 0, i,j;

		for(i=0; i<n; i++){
			scanf("%d",&a[i]);
			if(i!=0){
				for(j=0; j<i; j++)
					if(a[j]<= a[i])
						sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}