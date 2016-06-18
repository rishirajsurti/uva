#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	int n,i,j,maxN; 
	
	while(scanf("%d",&n),n){

		map<string, int> mapper;
		maxN = -1;

		for(i=0; i<n; i++){

			string x[5];
			string code;
			cin>> x[0] >> x[1] >> x[2] >> x[3] >> x[4];

			sort(x, x+5);
			for(j=0; j<5; j++)
				code += x[j];

			if( !mapper.count(code) ){ //if doesn't exist
				mapper[code] = 1;
				maxN = max(maxN, 1);
			}
			else{
				int m = mapper[code] + 1;
				mapper[code] = m;
				maxN = max(maxN, m);
			}
		}
		int count = 0;
		for(map<string, int>::iterator it = mapper.begin(); it != mapper.end(); it++){
			if((it->second) == maxN)
				count += it->second;
		}
		printf("%d\n", count);
	}
	return 0;
}