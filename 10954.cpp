#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		int i,k;
		priority_queue<int, vector<int>, greater<int> > pq;
		for(i=0; i<n; i++){
			scanf("%d", &k);
			pq.push(k);
		}

		long long cost = 0, cost1, cost2;
		
		while(pq.size() > 1){
			cost1 = pq.top(); pq.pop();
			cost2 = pq.top(); pq.pop();
			cost += cost1+cost2;
			//printf("cost: %lld+%lld =%lld\n", cost1, cost2, cost);
			cost1 = cost1+cost2;
			//printf("pq.empty() %d\n",pq.empty() );
			if(pq.empty()) break;
			pq.push(cost1);
		}
		printf("%lld\n", cost);		
//		cout<<cost<<endl;
/*		while(!pq.empty()){
			printf("%d ",pq.top() );
			pq.pop();
		}*/
	}
	return 0;
}