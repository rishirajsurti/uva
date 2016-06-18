/*1<<N
a[1<<N] = ..
n dimension n neighbors
x y z nb: x-1 y z, x y-1 z , x y z-1
n dimension: 
a b c d e. ..
a -1 b c d e ..
..
here it is unit cube easy

*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define turnOnBit(S,i) (S | (1<<i))
#define turnOffBit(S,i) (S & ~(1<<i))
#define checkIfBitOn(S,i) (S & (1<<i))  
int wt[1<<15];
int potency[1<<15];
//max dim 14 

int main(){
	int N, i, j;
	while(scanf("%d",&N) != EOF){
		for(i=0; i< (1<<N); i++){
			scanf("%d", &wt[i]);
			potency[i] = 0;
		}
		//eg. N = 3 , 000 to 111
		
		//calculate potency of each of the points
		for(i=0; i< (1<<N)-1; i++)
			for(j=0; j< N; j++){	//for its N neighbours
				if(checkIfBitOn(i,j))
					potency[i] += wt[turnOffBit(i,j)];
				else
					potency[i] += wt[turnOnBit(i,j)];
			}
		int maxP = -1, curP = 0;

		for(i=0; i< (1<<N)-1; i++)
			for(j=0; j<N; j++){
				if(checkIfBitOn(i,j))
					curP = potency[i] + potency[turnOffBit(i,j)];
				else
					curP = potency[i] + potency[turnOnBit(i,j)];
				
				maxP = max(maxP, curP);
			}
		printf("%d\n",maxP );
	}
}
