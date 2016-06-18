#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adj;
vi P, R;


void init(int n){
	int i;
	R.assign(n, 1);
	P.assign(n, 0);
	for(i=0; i<n; i++){
		P[i] = i;
	}
}

int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}

bool isSameset(int x, int y){
	return findp(x) == findp(y);
}

void unionSet(int x, int y){
	if(isSameset(x,y))
		return;

	x = findp(x); y = findp(y);
	if(R[x] > R[y]){
		P[y] = x; R[x] += R[y];
	}
	else{
		P[x] = y; R[y] += R[x];
	}

}
int main(){
	int m,n;
	while(scanf("%d %d", &m, &n), (n||m)){
		//adj.assign(m, vii());
		P.clear();
		R.clear();
		int i,j,x,y,wt, total_length = 0;
		
		vector< pair<int, ii> > Edgelist;

		for(i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &wt);
		//	adj[x].push_back(ii(y,wt));
		//	adj[y].push_back(ii(x,wt));
			total_length += wt;
			Edgelist.push_back(make_pair(wt, ii(x,y)));
		}

		sort(Edgelist.begin(), Edgelist.end());
		int mst_cost = 0;
		init(m);
		int E = Edgelist.size();
		for(i=0; i < E; i++){
			pair<int, ii> front = Edgelist[i];
			if(!isSameset(front.second.first, front.second.second)){
				mst_cost += front.first;
				unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", total_length-mst_cost);
	}
	return 0;
}