#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int m,n, n2;
char grid[21][42];
char c1, c2;
int dr[] = {1,1, 0,-1,-1,-1, 0, 1};
int dc[] = {0,1, 1,1, 0,-1, -1, -1};

void printgrid(){
	printf("==============\n");
	int i,j;
	for(i=0; i<m; i++){
		for(j=0; j<n2; j++)
			printf("%c",grid[i][j] );
		printf("\n");
	}
	printf("==============\n");

}
int floodfill(int x, int y, char c1, char c2){

	if(x < 0 || x >= m || y <0 || y >= n2) return 0;

	if(grid[x][y] != c1) return 0;
	grid[x][y] = c2;
	int i;
	int ans = 1;
	for(i=0; i<7; i++)
		ans += floodfill(x+dr[i], y+dc[i], c1, c2);

	return ans;
}

int main(){
	
	while(scanf("%d %d", &m, &n) != EOF){
		char c;
		cin.ignore();
		int i,j;
		n2 = 2*n;
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				scanf("%c", &grid[i][j]);
				grid[i][n2-1-j] = grid[i][j];
			}
			cin.ignore();
		}
		int x,y;
		scanf("%d %d", &x, &y);
		c1 = grid[x][y];
		for(i=0; i<m; i++) for(j=0; j<n; j++){
			if(grid[i][j] != c1){
				c2 = grid[i][j];
				break;
			}
		}
		int cur_size = floodfill(x,y,c1, c2);	
		int next_size, max_size = -1;
		
		for(i=0; i<m; i++){
			for(j=0; j<n2; j++){
				if(grid[i][j]!=c2){
			//		printgrid();
					next_size = floodfill(i,j,c1, c2);
				}

				max_size = max(max_size, next_size);
			}
		}
		printf("%d\n", max_size);
		cin.igore();
	}
	return 0;
}