#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct {
	int i,j, v;
} E;
E D[1000000];
int R[1005], P[1005];

int cmp(const void *i, const void *j){
	static E *a, *b; 
	a = (E *)i, b = (E *)j;
	return a->v - b->v;
}

void init(int n){
	int i;
	for(i=0; i<n; i++){
		R[i] = 1;
		P[i] = i;
	}
}

int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}

int joint(int x, int y){
	x = findp(x), y = findp(y);
	if(x != y){
		if(R[x] > R[y])
			R[x] += R[y], P[y] = x;
		else
			R[y] += R[x], P[x] = y;
		return 1;
	}
	return 0;
}

int main(){
	int t, n,m, r, i,j, cases = 0;
	int x[1005], y[1005];
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &r);

		for(i=0; i<n; i++)
			scanf("%d %d", &x[i], &y[i]);

		init(n);
		m = 0;

		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				D[m].i = i, D[m].j = j;
				D[m].v = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				m++;
			}
		}

		qsort(D, m, sizeof(E), cmp);

		int ac = 0, state = 1;
		double road = 0, rail = 0;

		r = r*r;
		for(i=0; i<m; i++){
			if(joint(D[i].i, D[i].j)){
				if(D[i].v > r){
					rail += sqrt(D[i].v), state++;
				}
				else{
					road += sqrt(D[i].v);
				}
				ac++;
				if(ac == n-1) break;
			}
		}
		printf("Case #%d: %d %.lf %.lf\n", ++cases, state, road, rail);
	}
}
/*#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


struct point{
	double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {};
	bool operator < (point other) const{
		return x < other.x;
	}
};

typedef vector<int> vi;
typedef pair<point, int> pi;
typedef pair<int, point> ip;
typedef pair<int, int> ii;
typedef pair<int, pair<point, point> > ipp;
typedef pair<int, pair<int, int> > iii;
typedef pair<point, point> pp;
typedef vector<point> vp;
typedef vector<pi> vpi;
vector<vpi> adj;
vi taken;
vi R,P;

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

void clearall(){
	adj.clear();
	taken.clear();
	R.clear();
	P.clear();
}

int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}
int joint(int x, int y){
	x = findp(x), y = findp(y);
	if(x != y){
		if(R[x] > R[y])
			R[x] += R[y], P[y] = x;
		else
			R[y] += R[x], P[x] = y;
		return 1;
	}
	return 0;
}

int main(){
	int t; scanf("%d", &t);
	int cases = 1;
	while(t--){

		clearall();
		int n,r;
		scanf("%d %d", &n, &r);
		adj.assign(n, vpi());
		R.assign(n, 1);
		P.assign(n, 1);
		int i,j;
		for(i=0; i<n; i++) P[i] = i;
		vp data;
		point pt;
		
		for(i=0; i<n; i++){
			scanf("%lf %lf", &pt.x, &pt.y);
			data.push_back(pt);
		}

		priority_queue<iii, vector<iii>, greater<iii> > pq; // increasing order

		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
					int d = dist(data[i], data[j]);
					adj[i].push_back(pi(data[j], d));
					pq.push(make_pair(d, make_pair(i,j)));
				
			}
		}

		taken.assign(n, 0);
		int ac = 0, state = 1;
		double road = 0, rail = 0;
		while(ac <= n-1){
			iii k = pq.top(); pq.pop();
			ii cities = k.second;
			int wt = k.first;
			if(joint(cities.first, cities.second)){
				if(wt > r)
					rail += wt, state++;
				else
					road += wt;
				ac++;
			}

		}
		printf("Case #%d: %d %.lf %.lf\n",cases++, state, road, rail);
	}
}*/