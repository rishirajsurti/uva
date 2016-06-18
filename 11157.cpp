#include <cstdio>

using namespace std;
int v[256];
char type[8];
int max(int a, int b){
	return (a > b ? a : b);
}
int main(){
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		int ans = 0, d, i, j, n, z;
		scanf("%d %d", &n, &d);
		v[0] = v[1] = 0;
		j = 2; //v[2] onwards
		for(i = 0; i < n; i++){
			scanf("%1s-%d", type, &z);
			v[j++] = z; // can jump at z;
			// can jump from v[j-1] to v[j]
			//e.g. from v[1]=0 to v[2]=5
			if(type[0] == 'B') v[j++] = z;
		}
		v[j++] = d;
		v[j++] = d;
		// 1... 3(B).....7(S)...10
   //v[]:0 1    1 2       3      10 11  12
	   //1 1    3 3       7      10 10  -
 		//can jump on big any times, small only once
		// hence add big twice (to and fro)
		//
		for(i = 2; i < j; i++) ans = max(ans, v[i] - v[i-2]);
		printf("Case %d: %d\n", c, ans);
	}
	return 0;
}