#include <bits/stdc++.h>
using namespace std;

int g[128], rg;
double v[1024];

int main(){
	int f, r; 
	while(scanf("%d", &f), f){
		scanf("%d", &r);
		int vc = 0;
		double maxspread = 0;
		for(int i = 0; i<f; scanf("%d", &g[i++]));
		for(int i = 0; i<r; i++){
			scanf("%d", &rg);
			for(int j = 0; j<f; j++) v[vc++] = rg / (double)g[j];
		}
		sort(v, v+vc);
		for(int i = 1; i < vc; i++){
			double spread = v[i] / v[i-1];
			if(spread > maxspread) maxspread = spread;
		}
		printf("%.2lf\n", maxspread);
	}
	return 0;
}