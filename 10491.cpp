#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	double ncows, ncars, nshow;
	double p;
	while(scanf("%lf %lf %lf", &ncows, &ncars, &nshow) != EOF){

		double p1 = ( ncows / (double)(ncows+ncars) ) * ( ncars / (double)(ncows+ncars-nshow-1) );
		double p2 = ( ncars / (double)(ncars+ncows) ) * ( (ncars-1) / (double)(ncars+ncows-nshow-1) );

		printf("%.5lf\n", p1+p2);
	}
	return 0;
}