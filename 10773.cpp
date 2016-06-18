#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int t, tc; scanf("%d",&t);
	for(tc=1; tc<=t; tc++){
		int d,v,u; scanf("%d %d %d", &d, &v, &u);
		float t1, t2;
		
		if(v==0 || v >= u)
				printf("Case %d: can't determine\n",tc );
		else{
			t1 = 1.00*d/(u);
			t2 = 1.00*d/sqrt(u*u - v*v);
			printf("Case %d: %.3f\n",tc, t2-t1 );
		}
		
	}
	return 0;
}