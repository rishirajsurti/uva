#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int grid[101][101];
bool water[101][101];
bool visited[101][101];
queue<pair <int, int> > q;
int main(){
	int t, tc;

	scanf("%d", &t);
	for(tc = 1; tc<=t ;tc++){
		int r, c, m, n, i,j, x,y, k;
		scanf("%d %d %d %d", &r, &c, &m, &n);
		
		int dr[8] = {+m, +m, -m, -m, +n, +n, -n, -n};
		int dc[8] = {+n, -n, +n, -n, +m, -m, +m, -m};

		memset(grid, 0, sizeof grid);
		memset(water, false, sizeof water);
		memset(visited, false, sizeof visited);

		int w; scanf("%d", &w);

		for(i=0; i<w; i++){
			scanf("%d %d", &x, &y);
		//	grid[x][y] = -1;
			water[x][y] = true;
		}
		int odd=0, even=0;
		q.push(make_pair(0,0));

		while(!q.empty()){
		i = q.front().first;
		j = q.front().second;
		q.pop();
		visited[i][j] = true;

			int reachable = 0;
			for(k=0; k<8; k++){
				if(i+dr[k] >= 0 && i+dr[k] <r && j+dc[k] >= 0 && j+dc[k] < c && !water[i+dr[k]][j+dc[k]]){
					reachable++;
					if(!visited[i+dr[k]][j+dc[k]]){
						q.push(make_pair(i+dr[k], j+dc[k]));
						visited[i+dr[k]][j+dc[k]] = true;
					}
				}
			}
			if(reachable != 0){
				grid[i][j] = reachable;
				if(reachable % 2 == 0) even++;
				else	odd++;

			}
	}
	printf("Case %d: %d %d\n", tc, even, odd);
	}
}