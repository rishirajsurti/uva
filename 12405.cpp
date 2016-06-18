#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;



int main(){
	int t,i,j;

	scanf("%d", &t);
	for(j=1; j<=t; j++){
	int n;
	scanf("%d", &n);
	vector<char> field(n+2, '#');

	for(i=0; i<n; i++)
		cin>>field[i];

	int count = 0;
	for(i=0; i<n; i++){
		if(field[i] == '.'){
			field[i] = field[i+1] = field[i+2] = '#';
			count++;
			//greedily make scarecrow coever all field
		}
	}
	printf("Case %d: %d\n",j,count );
	}
	return 0;
}