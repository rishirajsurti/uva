#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int t,tc; scanf("%d", &t);
	for(tc = 1; tc <= t; tc++){
		int n; scanf("%d", &n);
		int age,i,ans;
		for(i=0; i<n; i++){
			scanf("%d", &age);
			if(i==n/2) ans = age;
		}
		printf("Case %d: %d\n", tc, ans);
	}
}