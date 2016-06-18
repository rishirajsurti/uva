#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

using ll = long long;

int values[200];
ll memo[20][200][11][21];

ll count(int r, int k, int m, int d){
	if(m==0){
		if(r==0) return 1;
		return 0;
	}

	if(k+1 < m) return 0;
	ll &t = memo[r][k][m][d];
	if(t==-1){
		t = count(((r+values[k]) % d + d) % d, k-1, m-1, d);
		t += count(r, k-1, m, d);
	}
	return t;
}

int main(){
	int n,q;
	int tc =0;

	while(scanf("%d %d", &n, &q), (n||q)){
	
		tc++;
		printf("SET %d\n",tc );
		for(int i = 0; i < n; i++) scanf("%d",&values[i]);
		memset(memo, -1, sizeof memo);

		for(int i =0; i < q; i++){
			int m,d;
			scanf("%d %d",&d,&m);
			printf("QUERY %d: %lld\n",i+1, count(0,n-1, m,d) );
		}
	}
}
/*#include <cstdio>
#include <cstring>
using namespace std;

int n,q,d,m, ans;
int a[205];
int memo[205][205];

int count(int item_id, int rem_numbers, int sum){

	if(sum % d == 0) return 1;
	if(item_id == n || rem_numbers == 0) return;
	
	count(item_id+1, rem_numbers-1, sum);
	count(item_id+1, rem_numbers-1, sum+a[item_id]);
}

int main(){
	while(scanf("%d %d", &n, &q), (n||q)){

		memset(memo, -1, sizeof memo);
		int i,j;
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		
		for(i=0; i<q; i++){
			scanf("%d %d", &d, &m);
			ans=0;
			count(0,m,0);
			printf("Ans = %d\n", ans);
		}
	}
}

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1005
#define MAXW 40

int N, i, j, G, MW;
int V[MAXN], W[MAXN];
int memo[MAXN][MAXN];

int count(int item_id, int rem_wt){

	if(item_id == N || rem_wt == 0) return 0;
	if(memo[item_id][rem_wt] != -1) return memo[item_id][rem_wt];

	if(W[item_id] > rem_wt) return count(item_id+1, rem_wt);

	return memo[item_id][rem_wt] = max(count(item_id+1, rem_wt),
									 V[item_id]+count(item_id+1,rem_wt-W[item_id]));
}

int main(){

	memset(memo, -1, sizeof memo);
	scanf("%d",&N);
	for(i=0; i<N; i++)
		scanf("%d %d", &V[i], &W[i]);

	scanf("%d", &MW);
	ans = count(0, MW);
}*/