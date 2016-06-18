#include <bits/stdc++.h>
using namespace std;

struct point{
	double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y): x(_x), y(_y){}

};

double dist(point a, point b){
	return hypot(a.x - b.x, a.y - b.y);
}

typedef pair<point, point> pp;
typedef vector<point> vp;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<point, double> pd;
typedef vector<pd> vpd;
vector<vpd> adj;

vi P,R;

void init(int p){
	P.clear(); R.clear();
	int i,j;
	R.assign(p, 1);
	P.assign(p, 0);
	for(i=0; i<p; i++) P[i] = i;
}

int findp(int x){
	return P[x] == x ? x : P[x] = findp(P[x]);
}

bool isSameSet(int x, int y){
	return findp(x) == findp(y);
}

void unionSet(int x, int y){
	x = findp(x), y = findp(y);

	if(isSameSet(x, y))
		return;
	if(R[x] > R[y]){
		P[y] = x; R[x] += R[y];
	}
	else{
		P[x] = y; R[y] += R[x];
	}
}

double max(double a, double b){
	if(fabs(a - b) > 0.0) return a;
	else return b;
}

int main(){
	int n; scanf("%d", &n);
	while(n--){
		int s, p;
		scanf("%d %d", &s, &p);
		//remove s largest edges and then perform mst
		int i,j;
		vector< pair< double, ii> > Edgelist;
		vp data;
		point pt;
		init(p);

		for(i=0; i<p; i++){
			scanf("%lf %lf", &pt.x, &pt.y);
			data.push_back(pt);
		}

		for(i=0; i<p; i++){
			for(j=i+1; j<p && (i!=j); j++){
				double d = dist(data[i], data[j]);
			//	adj[i].push_back(pd(data[j], d));
			//	adj[j].push_back(pd(data[i], d));
				Edgelist.push_back(make_pair(d, ii(i,j)));
			}
		}

		sort(Edgelist.begin(), Edgelist.end());

		/*for(i=0; i<s;){
			pair<double, ii> front = Edgelist.back(); 
			Edgelist.pop_back();
			int p1, p2; double wt;
			p1 = front.second.first; p2 = front.second.second;
			wt = front.first;
			if(!isSameSet(p1,p2)){
				unionSet(p1, p2);
				i++;
			}
		}*/

		double maxd = -1.0;
		int cnt=0;
		for(i=0; i<Edgelist.size();i++){
			pair<double, ii> front = Edgelist[i];
			int p1, p2; double wt;
			p1 = front.second.first; p2 = front.second.second;
			wt = front.first;
			if(!isSameSet(p1, p2)){
				unionSet(p1, p2);
				cnt++;
				maxd = max(wt, maxd); 
			}
			if(cnt == p-s)
				break;
		}

		printf("%.2lf\n", maxd);
	}
}