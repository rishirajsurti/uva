#include <stdio.h>
#include <algorithm>
using namespace std;
struct edg {
    int x, y, v, enable;
};
edg E[10005];
bool cmp(edg a, edg b) {
    return a.v < b.v;
}
int P[105], R[105];
void init(int n) {
    static int i;
    for(int i = 0; i <= n; i++)
        P[i] = i, R[i] = 1;
}
int findp(int x) {
    return x == P[x] ? x : P[x]=findp(P[x]);
}
int joint(int x, int y) {
    x = findp(x), y = findp(y);
    if(x != y) {
        if(R[x] > R[y])
            R[x] += R[y], P[y] = x;
        else
            R[y] += R[x], P[x] = y;
        return 1;
    }
    return 0;
}
int main() {
    int t, n, m, x, y, v;
    int i, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &v);
            E[i].x = x, E[i].y = y, E[i].v = v;
            E[i].enable = 0;
        }
        sort(E, E+m, cmp);
        int cost = 0, ontree[n+1], idx = 0;
        init(n);
        for(i = 0; i < m; i++) {
            if(joint(E[i].x, E[i].y)) {
                cost += E[i].v;
                ontree[idx++] = i;
            }
        }
        printf("%d ", cost);
        int mincost = 0xfffffff;
        for(i = 0; i < idx; i++) {
            cost = 0;
            E[ontree[i]].enable = 1;
            init(n);
            int cnt = 0;
            for(j = 0; j < m; j++) {
                if(!E[j].enable && joint(E[j].x, E[j].y)) {
                    cost += E[j].v;
                    cnt++;
                }
            }
            E[ontree[i]].enable = 0;
            if(mincost > cost && cnt == n-1) // cnt important
                mincost = cost;
        }
        printf("%d\n", mincost);
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adj;
vi P,R, included;

void init(int n){
	P.clear(); R.clear();
	int i;
	R.assign(n, 1);
	P.assign(n, 0);
	for(i=0; i<n; i++) P[i] = i;
}

int findp(int x){
	return P[x] == x ? x : P[x]=findp(P[x]);
}

bool isSameSet(int x, int y){
	return findp(x) == findp(y);
}

void unionSet(int x, int y){
	x= findp(x), y = findp(y);
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
	int t; scanf("%d", &t);
	while(t--){
		int n,m; scanf("%d %d", &n, &m);
		int i,j,a,b,wt;
		adj.assign(n, vii());
		init(n);
		included.assign(m, 0);
		vi ontree;
		ontree.assign(n, 0);

		vector< pair<int, ii> > Edgelist;

		for(i=0; i<m; i++){
			scanf("%d %d %d", &a, &b, &wt);
			--a; --b;
			adj[a].push_back(ii(b, wt));
			adj[b].push_back(ii(a, wt));
			Edgelist.push_back(make_pair(wt, ii(a,b)));
		}
		
		sort(Edgelist.begin(), Edgelist.end());
		priority_queue<int> pq;
		int mst_cost = 0;
		int idx = 0;
		for(i=0; i<m; i++){
			included[i] = 0;
			pair<int, ii> front = Edgelist[i];
			a = front.second.first;
			b = front.second.second;
			wt = front.first;
		//	printf("wt %d\n", wt);
			if(!isSameSet(a,b)){
				unionSet(a,b);
				pq.push(wt);
				mst_cost += wt;
				ontree[idx++] = i;
			}
		}
		
		printf("%d ",mst_cost);
		int cnt;
		
		int mincost = 1e6;
		for(i=0; i<idx; i++){
			int k = ontree[i];
			init(n);
			mst_cost = 0;
			cnt = 0;
			for(j=0; j<m && j!=k; j++){
				if(!isSameSet(Edgelist[j].second.first, Edgelist[j].second.second)){
					unionSet(Edgelist[j].second.first, Edgelist[j].second.first);
					mst_cost += Edgelist[j].first;
					cnt++;
				}
			}
			included[i] = 0;
			if(mincost > mst_cost && cnt == n-1)
				mincost = mst_cost;
		}
		printf("%d\n", mincost);
	}
	return 0;
}*/