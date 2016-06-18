#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n; 
	while(scanf("%d", &n) != EOF){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool stk, que, prque;
		
		stk = que = prque = true;
		int i,j, x;

		for(i=0; i<n; i++){
			scanf("%d %d", &j, &x);
			if(j==1){
				s.push(x);
				q.push(x);
				pq.push(x);
			} else if(j==2){
				int e;
				if(!s.empty()){
				e = s.top(); s.pop();
				if(e != x) stk = false;
				} else stk = false;

				if(!q.empty()){
				e = q.front(); q.pop();
				if(e != x) que = false;
				} else que = false;

				if(!pq.empty()){
				e = pq.top(); pq.pop();
				if(e != x) prque = false;
				} else prque = false;
			}
		}
		if(!stk && !que && !prque){
			printf("impossible\n");
		} else if(stk && !que && !prque){
			printf("stack\n");
		} else if(!stk && que && !prque){
			printf("queue\n");
		} else if(!stk && !que && prque){
			printf("priority queue\n");
		} else{
			printf("not sure\n");
		}
	}
	return 0;
}