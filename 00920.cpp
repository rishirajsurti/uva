#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0);

struct point{
	double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y): x(_x), y(_y) {}
	bool operator < (point other) const{
		return x < other.x;
	}
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct line{
	double a, b, c; // ax + by + c = 0;
};

void pointsToLine(point p1, point p2, line &l){
	if(fabs(p1.x - p2.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		vector<point> a;
		point p;
		int i,j;
		for(i=0; i<n; i++){
			scanf("%lf %lf", &p.x, &p.y);
			a.push_back(p);
		}

		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		double ans = 0.0;
/*		for(i=0; i<a.size(); i++){
			printf("%lf %lf->\n", a[i].x, a[i].y);
		}*/

		point curr, prev;
		prev = a[0];
		for(i=1; i<a.size(); i++){
			if(a[i].y <= prev.y) continue;

			//now a[i] is point higher than prev;
			line l;
			pointsToLine(a[i], a[i-1], l);
			//l : ax + by + c =0;
			point ip;
			ip.y = prev.y;
			ip.x = -(double)(l.b*ip.y + l.c) / l.a;
			ans += dist(a[i], ip);
			prev = a[i];
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}