#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define P 1048576

bool busy[P];
int l[128], r[128];
int b[128], d[128], p[128];
int n, m;

int conflict(){

	int i,j;
	int begin, end;

	for(i=0; i<n; i++){
		begin = l[i];	end= r[i];
		for(j = begin; j<end; j++){ //note j "<" end, not "<="
			if(busy[j]) return true;
			busy[j] = true;
		}
	}

	for(i=0; i<m; i++){
		//continue till large times
		// 5 8 1000
		//5 1005 2005
		for( j = 0; b[i] + j*p[i] < P; j++){

			begin = b[i] + j*p[i];
			end = begin + (d[i] - b[i]); // begin + (duration);
			for(int k = begin; k < end && k < P; k++){
				if(busy[k]) return true;
				busy[k] = true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d %d",&n, &m), (n||m)){
		
		memset(busy, false, sizeof busy);
		int i,j;
		
		for(i=0; i<n; i++)
			scanf("%d %d", &l[i], &r[i]);

		for(j=0; j<m; j++)
			scanf("%d %d %d", &b[j], &d[j], &p[j]);

		puts("NO CONFLICT" + 3*conflict());
	}
	return 0;
}