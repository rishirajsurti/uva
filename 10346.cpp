#include <cstdio>
using namespace std;

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int sum = n;
		int butts = n;
		while(butts >= k){
			sum += 1;
			butts -= k;
			butts++;
		}
		printf("%d\n", sum);
	}
}