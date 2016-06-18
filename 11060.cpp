#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector<string> elements;

vector< vector<int> > adj;
map<int, bool> vis;
vector<int> toposort;

void dfs(int b){
//	printf("%d->", b);
	for(int i = 0; i < adj[b].size(); i++){
		if(!vis[adj[b][i]])
			dfs(adj[b][i]);
	}
	vis[b] = true;
	toposort.push_back(b);
}

int main(){
	int N, M, tc = 1;
	while(scanf("%d\n", &N) != EOF){
		elements.clear();
		adj.clear();
		toposort.clear();
		vis.clear();
		int i,j;
		//adj.assign(n, vector<string>());
		adj.assign(N, vector<int>());
		string bvg;
		for(i=0; i<N; i++){
			cin>>bvg;
			elements.push_back(bvg);
		}

		sort(elements.begin(), elements.end());
		scanf("%d\n", &M);
		string low, high;
		for(i=0; i<M; i++){
			cin >> low >> high;
			int lowi = find(elements.begin(), elements.end(), low) - elements.begin();
			int highi = find(elements.begin(), elements.end(), high) - elements.begin();
			adj[lowi].push_back(highi);
		}
	/*	for(i=0; i< N; i++){
			cout<<i<<" "<<elements[i]<<" ";
			for(j=0; j<adj[i].size(); j++){
				cout<<adj[i][j]<<" "<<elements[adj[i][j]]<<" ";
			}
			cout<<endl;
		}
	*/
		for(i=0; i<N; i++){
			if(!vis[i])
				dfs(i);
		}
		
		reverse(toposort.begin(), toposort.end());
		printf("Case #%d: Dilbert should drink beverages in this order:",tc++ );
		for(i=0; i<toposort.size(); i++){
			cout<<" "<<elements[toposort[i]];
		}
		printf(".\n\n");
	}
	return 0;
}