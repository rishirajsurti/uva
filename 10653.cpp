#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1e5

int dr[4] = {+1, 0, -1, 0};
int dc[4] = {0, +1, 0, -1};

typedef pair<int, int> ii;

static int a[1000][1000];
static int t[1000][1000]; //time
int main(){
	int r, c; 
	while(scanf("%d %d", &r, &c), (r||c)){
	//memset(a, 0, sizeof a);
	
	int num_row; scanf("%d", &num_row);
	int i,j, x,y;

	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			a[i][j] = 0;
			t[i][j] = INF;
		}
	}

	for(i=0; i<num_row; i++){
		int nr, nb, nc;
		scanf("%d %d", &nr, &nb);
		for(j=0; j<nb; j++){
			scanf("%d", &nc);
			a[nr][nc] = -1;
		}
	}

	ii start, end;
	scanf("%d %d", &x, &y);
	start.first = x; start.second = y;
	scanf("%d %d", &x, &y);
	end.first = x; end.second = y;

	queue<ii> q;
	q.push(start);
	t[start.first][start.second] = 0;

	while(!q.empty()){
		ii v = q.front(); q.pop();

		for(i=0; i<4; i++){
			x = v.first+dr[i];
			y = v.second+dc[i];
			if(x >= 0 && x <r && y>=0 && y<c){
			if(a[x][y] != -1){
				if(t[v.first][v.second] + 1 < t[x][y]){
					t[x][y] = t[v.first][v.second]+1;
					q.push(ii(x,y));
				}
			}
			}
		}
	}
	printf("%d\n", t[end.first][end.second]);
	
	}
	return 0;
}	