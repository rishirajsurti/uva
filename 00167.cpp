#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int row[8], max_sum, grid[8][8];

bool place(int r, int c){
	int prev;
	for(prev = 0; prev < c; prev++)
		if(row[prev] == r || (abs(row[prev]-r) == abs(prev-c)))
			return false;
	return true;
}

void backtrack(int c){

	if(c==8){
		int i, sum=0;
		for(i=0; i<8 ;i++){
			sum += grid[row[i]][i];
		//	printf("%d ",row[i]);
		}
		if(sum > max_sum)
			max_sum = sum;
		//printf("\n");
	}
	for(int r = 0; r < 8; r++){
		if(place(r,c)){
			row[c] = r;
			backtrack(c+1);
		}
	}
}
int main(){
	int k,i,j;
	scanf("%d", &k);
	while(k--){
		
		for(i=0; i<8; i++)
			for(j=0; j<8; j++)
				scanf("%d",&grid[i][j]);

		max_sum = -1;	
		backtrack(0);
		printf("%5d\n",max_sum );
	}
	return 0;
}