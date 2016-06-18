#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
	int d, k;
	while(scanf("%d %d", &d, &k), (d||k)){
		vi hd, hk;
		hd.assign(d,0); hk.assign(k,0);
		for(int i = 0; i < d; i++)
			scanf("%d", &hd[i]);

		for(int i =0 ; i < k; i++)
			scanf("%d", &hk[i]);

		sort(hd.begin(), hd.end());
		sort(hk.begin(), hk.end());
		int cost = 0;

		while(!hd.empty() && !hk.empty()){
			if(hk[0] >= hd[0]){ //knight can kill dragon
				cost+=hk[0];
				hd.erase(hd.begin());
				hk.erase(hk.begin()); //knight can kill only one dragon
			}
			else{
				//knight is smaller, remove it
				hk.erase(hk.begin());
			}
		}

		if(!hd.empty())
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", cost);
	}
	return 0;
}