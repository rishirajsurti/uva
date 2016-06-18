#include <cstdio>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		int i,k;
		bool showed = false;
		for(i=0; i<n; i++){
			scanf("%d", &k);
			if(k > 0){
				if(showed) printf(" ");
				printf("%d",k);
				showed = true;
			}
		}
		if(!showed)
			printf("0");
		printf("\n");
	}
	return 0;
}