#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
	int n,d,r;
	while(scanf("%d %d %d", &n, &d, &r), (n||d||r)){
		vi m(n,0), e(n,0);
		int i;
		for(i=0; i<n; i++)
			scanf("%d",&m[i]);
		for(i=0; i<n; i++)
			scanf("%d", &e[i]);

		sort(m.begin(), m.end());
		sort(e.begin(), e.end());
		reverse(e.begin(), e.end());
		int extra = 0;

		for(i=0; i<n; i++){
			if(m[i] + e[i] > d)
				extra += (m[i]+e[i]-d)*r;
		}
		printf("%d\n", extra);
	}
}