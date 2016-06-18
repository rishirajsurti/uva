//this is 3d version of 2d max subarray
// visualize 3d cube
// row row row row
// -> -> -> -> -> ->
//in row major fashion
// find the max 2d subarray for a given depth; say z(c)
// now iterate over all c
// for each c store the (coordinates)
// end select minimum of the coordinates and sum ;

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	int t;	scanf("%d\n",&t);
	while(t--){

		int a,b,c;	scanf("%d %d %d", &a, &b, &c);
		long long m[a][b][c];
		int i,j,k;
		for(i=0; i<a; i++)
		for(j=0; j<b; j++)
		for(k=0; k<c; k++){
			long long g;
			scanf("%lld",&g);

			if(i > 0) g += m[i-1][j][k];
			if(j > 0) g += m[i][j-1][k];
			if(k > 0) g += m[i][j][k-1];

			if(i > 0 && j > 0) g -= m[i-1][j-1][k];
			if(i > 0 && k > 0) g -= m[i-1][j][k-1];
			if(j > 0 && k > 0) g -= m[i][j-1][k-1];

			if(i > 0 && j > 0 && k > 0) g += m[i-1][j-1][k-1];

			m[i][j][k] = g;
		}

		long long max_sum = INT_MIN;
		int i1, j1, k1;

		for(i=0; i<a; i++)
		for(j=0; j<b; j++)
		for(k=0; k<c; k++)
		for(i1=i; i1<a; i1++)
		for(j1=j; j1<b; j1++)
		for(k1=k; k1<c; k1++){
			long long s = m[i1][j1][k1];
			if(i > 0) s -= m[i-1][j1][k1];
			if(j > 0) s -= m[i1][j-1][k1];
			if(k > 0) s -= m[i1][j1][k-1];

			if(i > 0 && j > 0) s += m[i-1][j-1][k1];
			if(i > 0 && k > 0) s += m[i-1][j1][k-1];
			if(j > 0 && k > 0) s += m[i1][j-1][k-1];

			if(i > 0 && j > 0 && k > 0) s -= m[i-1][j-1][k-1];

			if(s > max_sum) max_sum = s;
		}
	printf("%lld\n", max_sum);
	if(t) printf("\n");
	}
	return 0;
}


/*#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;


int a,b,c,i,j,k, l,m,n, small_b, small_c, big_b, big_c;
int value[25][25][25];
int gridValue;


void calcMaxValue(){


}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		cin.ignore();
		scanf("%d %d %d", &a, &b, &c);

		//consider a as 3rd dimension (z-axis)
		gridValue = 0;
		for(i = 1; i <= a; i++){
			for(j = 1; j <= b; j++){
				for(k = 1; k <= c; k++){
					scanf("%d", &value[i][j][k]);
					gridValue += value[i][j]k];
					if(j>1) value[i][j][k] += value[i][j-1][k];
					if(k>1) value[i][j][k] += value[i][j][k-1];

					if(j>1 && k>1)	value[i][j][k] -= value[i][j-1][k-1];
					} } }

		int running_sum = -127*100*100, ans = 0;

		for(i = 1; i <= a; i++){
			for(j = 1; j <= b; j++){
				for(k = 1; k <=c; k++){
					for(l=1; l<=j; l++){
						for(m=1; m<=k; m++){
							running_sum = value[i][j][k];

							if(l > 1) running_sum -= value[i][l-1][m];
							if(m > 1) running_sum -= value[i][l][m-1];
							if(l > 1 && m > 1)
								running_sum += value[i][l-1][m-1]

							ans = max(ans, running_sum);
						}
					}
				}
			}
		}



	}	
}*/