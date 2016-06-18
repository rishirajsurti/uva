#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	while(scanf("%d %d",&n, &m), (n||m)){
		int i,j,k;
		set<int> set1, set2;
		for(i=0; i<n; i++){
			scanf("%d", &k);
			set1.insert(k);
		}
		int count =0;

		for(j = 0; j < m; j++){
			scanf("%d", &k);
			if(set1.find(k) != set1.end())
				count++;
			set2.insert(k);
		}
		printf("%d\n", count);
	}
}