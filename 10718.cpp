#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,l,u;
	while(scanf("%d %d %d", &n, &l, &u) != EOF){
		int maxn=-1, cur, index;
		for(int i = l; i <= u; i++){
			cur = i | n;
			if(cur > maxn){
				maxn = cur;
				index = i;
			}
//			maxn = max(maxn, cur); 
		}
		printf("%d\n", index);
	}
	return 0;
}