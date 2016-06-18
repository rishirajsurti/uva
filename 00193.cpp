#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define BLACK 0

typedef vector<int> vi;
vector<vi> adj;
vi color;
int v, e;

bool moreBlack(){
	int wc=0, bc=0; //white, black count
	int i;
	for(i=0; i<v; i++){
		if(color[i] == WHITE)
			wc++;
		else if(color[i] == BLACK)
			bc++;
	}
	return (bc>wc);
}	

bool valid(int u, int c){
	if(c==WHITE) return true;
	int i;
	for(i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(color[v] == c)
			return false;
	}
	return true;
}

bool graphColor(int u, int c){
	printf("vtx %d color %d\n", u, c);
	color[u] = c;
	int i;
	for(i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		if(valid(v, WHITE) && graphColor(v, WHITE))
			return true;
		else if (valid(v, BLACK) && graphColor(v, BLACK))
			return true;
	}
	color[u] = -1;
}

void solve(){
	int i;
	for(i=0; i<v; i++){
		if(graphColor(i, WHITE) && moreBlack())
			return;
		else if(graphColor(i, BLACK) && moreBlack())
			return;
	}
}

int main(){

	int t; scanf("%d", &t);
	
	while(t--){
		
		scanf("%d %d", &v, &e);
		adj.assign(v, vi());
		color.assign(v, -1);
		int i, a, b;
		for(i=0; i<e; i++){
			scanf("%d %d", &a, &b);
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		solve();	

		int cnt = 0;
		vi bv; //black vertices
		for(i=0; i<v; i++){
			if(color[i] == BLACK){
				cnt++; bv.push_back(i);
			}
		}
		printf("%d\n", cnt);
		for(i=0; i<bv.size(); i++){
			if(i>0) printf(" ");
			printf("%d", bv[i]);
		}
	}
	return 0;
}