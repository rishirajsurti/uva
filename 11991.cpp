#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

//use idea of adjacency list
typedef vector<int> vi;

int main(){
	int i,j,temp,n,m, k,v;
	vector<vi> AdjList;
	while(scanf("%d %d", &n, &m) != EOF){
	//	printf("%d %d\n", n, m);
		AdjList.assign(1000005, vi());

		for(i=1; i<=n; i++){
			scanf("%d",&temp);
			AdjList[temp].push_back(i);
		}
		for(i=1; i<=m; i++){
			scanf("%d %d", &k, &v);
	
			if(k > AdjList[v].size())
				printf("0\n");
			else
				printf("%d\n", AdjList[v][k-1]); //k-th occurence, index adjustment
		}
	}
	return 0;
}