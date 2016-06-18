#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<string> elements;

typedef pair<string, string> ss;
typedef vector<int> vi;

vector<ss> data;
vector<vi> adj;
vi dfs_num, dfs_low, visited;
int dfsNumberCounter, numSCC;
vector<vi> ans;
vi row;
vi S;

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	visited[u] = 1;
	S.push_back(u);
	int j;
	for(j=0; j < adj[u].size(); j++){
		int v = adj[u][j];

		if(dfs_num[v] == DFS_WHITE)
			tarjanSCC(v);

		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if(dfs_low[u] == dfs_num[u]){
		row.clear();
		++numSCC;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			row.push_back(v);
			if(u == v) break;
		}
		ans.push_back(row);
	}
}

int main(){
	int n, m;
	int dataset = 1;
	while(scanf("%d %d", &n, &m), (n||m)){

		data.clear();
		elements.clear();
		adj.clear();
		string a, b;
		int i,j;
		for(i=0; i < m; i++){
			cin>> a >> b;
			data.push_back(ss(a,b));
			if(find(elements.begin(), elements.end(), a) == elements.end()){
				elements.push_back(a);				
			}
			if(find(elements.begin(), elements.end(), b) == elements.end()){
				elements.push_back(b);				
			}
		}

		//sort(elements.begin(), elements.end());
		adj.assign(elements.size(), vi());
		for(i=0; i<data.size(); i++){
			ss result = data[i];
			int from, to;
			from = find(elements.begin(), elements.end(), result.first) - elements.begin();
			to = find(elements.begin(), elements.end(), result.second) - elements.begin();
			adj[from].push_back(to);
		}
		
		/*for(i=0; i<n; i++){
			cout<<elements[i]<<": ";
			for(j = 0; j < adj[i].size(); j++){
				cout<<elements[adj[i][j]]<<" ";
			}
			cout<<endl;
		}*/
		
		dfs_num.assign(n, DFS_WHITE);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumberCounter = numSCC = 0;
		ans.clear();
		row.clear();
		S.clear();
		for(i=0; i < n; i++){
			if(dfs_num[i] == DFS_WHITE)
				tarjanSCC(i);
		}

		int sz = ans.size();
		printf("Calling circles for data set %d:\n", dataset++);
		for(i=0; i<sz; i++){
			for(j = 0; j < ans[i].size()-1; j++){
				cout<<elements[ans[i][j]];
				printf(", ");
			}
			cout<<elements[ans[i][j]];
			printf("\n");
		}

		printf("\n");
	}
	return 0;
}