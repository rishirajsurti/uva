#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vi P, R;

void init(int v){
	R.assign(v, 1);
	P.assign(v, 0);
	int i;
	for(i=0; i<v; i++) P[i] = i;
}

int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}

bool isSameSet(int x, int y){
	return findp(x) == findp(y);
}

void unionSet(int x, int y){
	x = findp(x), y = findp(y);
	if(isSameSet(x,y))
		return;
	if(R[x] > R[y]){
		P[y] = x; R[x] += R[y];
	}
	else{
		P[x] = y; R[y] += R[x];
	}
}

int main(){
	int v,e;
	while(scanf("%d %d", &v, &e), (v||e)){
		int i, x,y, wt;
		P.clear(); R.clear();
		vector< pair<int, ii> > Edgelist;
		for(i=0; i<e; i++){
			scanf("%d %d %d", &x, &y, &wt);
			Edgelist.push_back(make_pair(wt, ii(x,y)));
		}
		init(v);
		sort(Edgelist.begin(), Edgelist.end());
		bool forest = true;
		bool first = false;
		for(i=0; i<e; i++){
			pair<int, ii> front = Edgelist[i];

			if(!isSameSet(front.second.first, front.second.second)){
				unionSet(front.second.first, front.second.second);
			}
			else{
				forest = false;
				if(!first){
					printf("%d", front.first);
					first = true;
				}
				else{
					printf(" %d",front.first );
				}
			}
		}
		if(forest)
			printf("forest\n");
		else
			printf("\n");

	}	
	return 0;
}