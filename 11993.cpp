#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define lastOnBit(S) (S & (-S))
#define turnOffLastBit(S) (S & (S-1))
#define isBitOn(S,i) (S & (1<<i))
#define setAll(S,n) (S = ((1<<n)-1))
#define turnBitOn(S,i) (S = S | (1<<i))

int main(){
	int n;
	vector<int> ones;
	while(scanf("%d", &n),n){
		//printf("%d %d\n",turnOffLastBit(n), n );
		ones.clear();
		int i;
		while(n){
			//printf("lastOnBit %d\n", lastOnBit(n));
			ones.push_back(lastOnBit(n));
			n = turnOffLastBit(n);
		}
		
		int a=0;
		int b=0;
		for(i=0; i<ones.size(); i=i+2)
			a = a|ones[i];
		for(i=1; i<ones.size(); i=i+2)
			b = b|ones[i];

		printf("%d %d\n", a,b);
	}
	return 0;
}