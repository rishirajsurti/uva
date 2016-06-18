#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef vector<int> vi;

int main(){
	vi a;
	int n,i,j;
	while(scanf("%d", &n)!=EOF)
		a.push_back(n);

	vi lis(a.size(),1);
	int maxlis = -1;
	for(i=1; i<a.size(); i++){
		for(j=0; j<=i-1; j++){
			if(a[j] < a[i])
				lis[i] = max(lis[i], lis[j]+1);
				maxlis = max(lis[i], maxlis);
		}
	}
	printf("%d\n-\n", maxlis);
	stack<int> liss;
	for(i=a.size()-1; i>=0; i--){
		if(liss.empty()){
			if(lis[i] == maxlis){
				liss.push(a[i]);
				maxlis--;
			}
		}
		else{
			if(lis[i] == maxlis && a[i] < liss.top()){
				liss.push(a[i]);
				maxlis--;
			}
		}
	}
	
	while(!liss.empty()){
		printf("%d\n",liss.top() );
		liss.pop();
	}
	return 0;
}