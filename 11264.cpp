#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std; 

typedef vector<int> vi;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i;
		scanf("%d", &n);
		vi a(n,0),b(n,0);
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);

		b[0] = 1;
		int count = 1, value = a[0];
		for(i=1; i<n-1; i++){
			if(value + a[i] < a[i+1]){
				count++;
				value += a[i];
				
			}
		}
		printf("%d\n", 1+count);
	}	
}