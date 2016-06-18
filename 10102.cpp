#include <bits/stdc++.h>
using namespace std;

const char DEST_COLOR = '3';
const char START_COLOR = '1';
const int MAX_SIZE = 600;
#define NUM_DIRECTION 4

const int COORD_OFFSET[NUM_DIRECTION][2] = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

const int UNVISITED = -1;

bool isValidCell(int r, int c, int numR, int numC){

	if(r < 0 || c < 0 || r >= numR || c >= numC)
		return false;
	return true;
}

int getDist(char colorGrid[][MAX_SIZE+1], int mSize){
	int distFromDest[mSize][mSize];

	for(int r = 0; r < mSize; r++)
		for(int c = 0; c < mSize; c++)
			distFromDest[r][c] = UNVISITED;

	queue<pair<int, int> > vQueue;

	for(int r = 0; r < mSize; r++){
		for(int c = 0; c < mSize; c++){
			if(colorGrid[r][c] == DEST_COLOR){
				vQueue.push(pair<int, int> (r,c));
				distFromDest[r][c] = 0;
			}
		}
	}

	while(!vQueue.empty()){
		int curR = vQueue.front().first;
		int curC = vQueue.front().second;
		vQueue.pop();
		for(int direction = 0; direction < NUM_DIRECTION; direction++){
			int nextR = curR + COORD_OFFSET[direction][0];
			int nextC = curC + COORD_OFFSET[direction][1];
			if(isValidCell(nextR, nextC, mSize, mSize) && distFromDest[nextR][nextC] == UNVISITED){
				distFromDest[nextR][nextC] = distFromDest[curR][curC] +1;
				vQueue.push(pair<int, int> (nextR, nextC));
			}
		}
	}

	int maxMinDist = 0;
	for(int r = 0; r < mSize; r++){
		for(int c = 0; c < mSize; c++){
			if(colorGrid[r][c] == START_COLOR && maxMinDist < distFromDest[r][c])
				maxMinDist = distFromDest[r][c];

		}
	}
	return maxMinDist;
}


int main(){
	char colorGrid[MAX_SIZE][MAX_SIZE+1];
	int mSize;

	while(scanf("%d", &mSize) != EOF){
		for(int r=0; r < mSize; r++)
			scanf("%s", colorGrid[r]);

		printf("%d\n", getDist(colorGrid, mSize));
	}
	return 0;
}