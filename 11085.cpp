d#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int row[8];
int minMoves;
int initial[8];

int calc_moves(){
	/*int moves = 0,i;
	for(i=0; i<8; i++){
		moves += abs(row[i] - initial[i]);
		printf("%d %d %d %d\n",row[i], initial[i], abs(row[i]-initial[i]), moves );
	}
	return moves;*/
	int moves = 0,i;
	for(i = 0; i < 8; i++)
		if(row[i] != initial[i])
			moves++;
	return moves;
}

bool place(int r, int c){

	int prev;
	for(prev = 0; prev < c; prev ++){
		if(row[prev] == r || abs(row[prev] - r) == abs(prev - c))
			return false;
	}
	return true;
}

void backtrack(int c){

	if(c==8){
	/*	for(int i = 0; i < 8; i++)
			printf("%d ",row[i] );
		printf("\n");
	*/	minMoves = min(minMoves, calc_moves());
	//	printf("minmoves %d, calc_moves %d\n",minMoves, calc_moves()  );
	}
	else{
		for(int r = 0; r < 8; r++){
			if(place(r,c)){
				row[c]=r;
				backtrack(c+1);
			}
		}
	}
}

int main(){

	int i,k, j = 1;
	while(scanf("%d", &k) != EOF){
		
		initial[0] = --k;
		for(i = 1; i< 8; i++){
			scanf("%d", &k);
			initial[i] = --k;
		}
		minMoves = 99999999;
		backtrack(0);
		printf("Case %d: %d\n",j++, minMoves );
	}
	

	return 0;
}