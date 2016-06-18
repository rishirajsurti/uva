#include <cstdio>
using namespace std;

int main(){
	int r,n, tc=1;
	while(scanf("%d %d",&r, &n), (r||n)){
		//roads, numbers
		// n + 26*n
		int ans;
		if(n >= r) ans = 0;
		else if(n*27 >= r){
			ans = (r-n)/n;
			if((r-n)%n > 0) ans++;
		}
		else ans = -1;

		if(ans == -1)
			printf("Case %d: impossible\n", tc++);
		else
			printf("Case %d: %d\n", tc++, ans);
	}
	return 0;
}