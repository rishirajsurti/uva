#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int x,y,k;
	vector<int> X,Y;
	/*x = ky/ y-k
	y = K+1 to 2*k
	*/
	while(scanf("%d",&k) != EOF){
		X.clear();	Y.clear();
		for(y = k+1; y <= 2*k ; y++){

			double x = ((double)k*double(y)) / (double(y)-double(k));
			if (x == (int)x){
				X.push_back(x);
				Y.push_back(y);
			}
		}
		/*for(x = 20000; x>=1; x--){
			for(y = 1; y <= x; y++){
				if((x*y) == (k*(x+y))){
					X.push_back(x);	Y.push_back(y);
				} } }*/

		int i;
		printf("%lu\n", X.size());
		for(i=0; i < X.size(); i++){
			printf("1/%d = 1/%d + 1/%d\n",k, X[i], Y[i]);
		}
	}
}