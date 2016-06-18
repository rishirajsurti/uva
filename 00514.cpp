#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){ //for each case
		
		int i;
		
		int *req = new int[n+1];
		int c;

		while(scanf("%d",&c),c){
			stack<int> s;
			queue<int> q;
			for(i = 1; i <= n; i++)
				q.push(i);

			req[1] = c;
			for(i=2; i<=n; i++)
				scanf("%d", &req[i]);	
			
			c = 1;

			while(!s.empty() || !q.empty()){

				if(!q.empty() && req[c] == q.front()){
					q.pop();
					c++;
				}else{ 
					if(!s.empty() && req[c] == s.top()){
						s.pop();
						c++;
					}
					else{
						if(!q.empty()){
						s.push(q.front());
						q.pop();
						}
						else
							break;
					}

				}

			}

			if(s.empty() && q.empty())
				printf("Yes\n");
			else
				printf("No\n");		
		}
		printf("\n");

	}
}