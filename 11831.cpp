#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m,s;
char grid[105][105];
char ins[50005];
int posi, posj;

typedef enum {N, E, S, W} dir_enum;
dir_enum cur_dir;

int di[4] = {-1, 0 , +1, 0};
int dj[4] = { 0, +1, 0, -1};

/*int di[4] = {0 , -1, 0, +1};
int dj[4] = {+1, 0, -1, 0};
*/

/*int di[4] = {+1, 0 , -1, 0};
int dj[4] = { 0, -1, 0, +1};
*/
void printgrid(){
	int i,j;
	for(i=0; i<n; i++){
	for(j=0; j<m; j++){
		if(i==posi && j==posj)
			printf("N");
		else
			printf("%c",grid[i][j] );
	}
	printf("\n");
	}

	printf("======\n");
}

int main(){
	while(scanf("%d %d %d", &n, &m, &s), (n||m||s)){
		int i,j;
		cin.ignore();
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				scanf("%c", &grid[i][j]);
				if(grid[i][j] == 'N' || grid[i][j]=='S' || 
					grid[i][j]=='L' || grid[i][j]=='O'){
				
				posi = i; posj = j;
				switch(grid[i][j]){
					case('N'):
						cur_dir = N; break;
					case('S'):
						cur_dir = S; break;
					case('L'):
						cur_dir = E; break;
					case('O'):
						cur_dir = W; break; }
				}
			}
			cin.ignore();
		}

		for(i=0; i<s; i++)
			scanf("%c",&ins[i]);
		cin.ignore();
		int ans=0;
		bool inside =true;
		i=0;
		while(inside && i <s){
			
			if(ins[i] == 'F'){
				posi += di[cur_dir];
				posj += dj[cur_dir];
			}else if(ins[i] == 'D'){ //turn right
				if(cur_dir == W) cur_dir = N;
				else cur_dir = (dir_enum)(cur_dir+1);
			}else if(ins[i] == 'E'){ //turn left
				if(cur_dir== N) cur_dir = W;
				else cur_dir = (dir_enum)(cur_dir -1);
			}

			if(posi < 0 || posi > n || posj < 0 || posj > m)
				inside = false;

/*			if(grid[posi][posj]=='#')
				inside = false;
*/
			if(grid[posi][posj] =='*')
				ans++;

			i++; //next instruction
//			printgrid();
		}
		printf("ans = %d\n", ans);
	}
}