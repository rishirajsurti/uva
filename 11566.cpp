#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int memo[1101][200][23];
int price[100], favour[100];

int find(int sum, int dk, int count){
	if(sum <= 0 || dk < 0 || count <= 0 ) return 0;
	int &v = memo[sum][dk][count];
	if(v == -1){
		if(price[dk/2] <= sum)
			v = find(sum - price[dk/2], dk-1, count-1) + favour[dk/2];
		v = max(v, find(sum, dk-1, count));
	}
	return v;
}
int main(){
	int n,x,t,k;

	while(scanf("%d %d %d %d", &n, &x ,&t, &k), n){
		n++;
		int max_total = floor(double(x*n)/1.1 + 1e-6) -n*t;

		for(int i =0; i< k; i++){
			scanf("%d", &price[i]);
			favour[i]=0;
			for(int j = 0; j < n; j++){
				int v; scanf("%d", &v);
				favour[i] += v;
			}
		}
	
	memset(memo, -1, sizeof memo);
	int max_favour = find(max_total, k*2-1, 2*n);
	printf("%.2f\n",1.0 * max_favour / n );
	}
}