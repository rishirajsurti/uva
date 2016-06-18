#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
	int n,m;
	while(scanf("%d %d", &n, &m), (n||m)){
		vector<vi> a(n);
		int i,j;
		for(i=0; i<n; i++){
			a[i].assign(m,0);
			for(j=0; j<m; j++) scanf("%d", &a[i][j]);
		}
		int q; scanf("%d", &q);
		int x,y,k;

		

		for(k=0; k<q; k++){
			scanf("%d %d", &x, &y);
			int ans = -1;
			int tl, tr, bl, br; //top left/right, bottom l/r

			for(i=0; i<n; i++){
				tl = lower_bound(a[i].begin(), a[i].end(), x)-a[i].begin();
				tr = upper_bound(a[i].begin(), a[i].end(), y)-a[i].begin();
				--tr;
				
				int cur_size;
				int ttl, ttr;
				ttl = tl; ttr = tr;
				while(ttl<=ttr){

				int len = ttr-ttl+1;
				//1 4
				bl = ttl+len;
				br = bl+len-1;
				if(br<m && a[i][br]<=y){
					cur_size = len;
					ans = max(ans, cur_size);
					}
				ttl++;
				}

				ttl = tl; ttr = tr;
				while(ttl<=ttr){

				int len = ttr-ttl+1;
				//1 4
				bl = ttl+len;
				br = bl+len-1;
				if(br<m && a[i][br]<=y){
					cur_size = len;
					ans = max(ans, cur_size);
					}
				ttr--;
				}
			}
			printf("ans %d\n", ans-1);
		}

	}
	return 0;
}
/*#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

int n,m,i,j,l,h,u,q;

typedef vector<int> vi;

vector<vi> grid;

int main(){
	while(scanf("%d %d", &n, &m), (n||m)){

		grid.assign(n, vi());
		for(i=0; i<n; i++)
			grid[i].assign(m,0);

		for(i=0; i<n; i++){
			for(j=0; j<m; j++)
				scanf("%d", &grid[i][j]);
		}

		scanf("%d", &q);
		while(q--){

			scanf("%d %d", &l, &u);
			int row;
			int s = 0, final_s;

		for(row=0; row<n; row++){
			vi& row_data = grid[row];
			//find where the lower limit starts
			vi::iterator lo_it = lower_bound(row_data.begin(), row_data.end(), l);
			//find the column number of that point
			int col = distance(row_data.begin(), lo_it);
			//enumerate the sizes starting from s+1 (=0+1)
			//update s;
			//then start from s+1
			int new_s;
			//00 01
			//10 11
			//row = 0, col = 0, s =2
			//row = 1, col =1, s = 1
			for(new_s = (s+1); ((row + new_s - 1 < m) && (col + new_s - 1 < n)); new_s++ ){
				printf("inside %d %d %d %d\n", s, new_s, row, col);
				int diag_row = row + new_s -1;
				int diag_col = col + new_s -1;
				if(grid[diag_row][diag_col] <= h){
					final_s = new_s;
					printf("changes\n");
				}
				else{
					break;
					}
				}
			}
			printf("%d\n",s );
		}
		printf("-\n");
	}
}

/*void count(){

	int row;
	s = 0;

	for(row=0; row<n; row++){
		vi& row_data = grid[row];
		//find where the lower limit starts
		vi::iterator lo_it = lower_bound(row_data.begin(), row_data.end(), l);
		//find the column number of that point
		int col = distance(row_data.begin(), lo_it);
		//enumerate the sizes starting from s+1 (=0+1)
		//update s;
		//then start from s+1
		int new_s;
		//00 01
		//10 11
		//row = 0, col = 0, s =2
		//row = 1, col =1, s = 1
		for(new_s = (s+1); (row + new_s - 1 < n) && (col + new_s - 1 < m); new_s++ ){

			int diag_row = row + new_s -1;
			int diag_col = col + new_s -1;
			if(grid[diag_row][diag_col] <= h)
				s = new_s;
			else
				break;
			}
		}
}
*/