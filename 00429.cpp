#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e6
typedef vector<string> vs;
typedef vector<int> vi;

bool ok(string s1, string s2){
	int sz1 = s1.size(), sz2 = s2.size();
	if(sz1 != sz2)
		return false;
	int cnt = 0;
	int i=0;
	while(i < sz1){
		if(s1[i] != s2[i])
			cnt++;
		i++;
	} 

	return (cnt == 1);
}

vector<string> dict;
vector<vi> adj;
vi dist;
vi visited;

void init(){
	dict.clear();
	adj.clear();
	dist.clear();
	visited.clear();
}

int bfs(string from, string to){
	int u = find(dict.begin(), dict.end(), from) - dict.begin();
	int v = find(dict.begin(), dict.end(), to)- dict.begin();
	queue<int> q;
	dist[u] = 0;

	int i,j;
	q.push(u);

	while(!q.empty()){
		int front = q.front(); q.pop();
		if(front == v) break;

		for(i=0; i<adj[front].size(); i++){
			//cout<<dict[adj[front][i]]<<" ";
			if(dist[adj[front][i]] > dist[front]+1){
				dist[adj[front][i]] = dist[front]+1;
				q.push(adj[front][i]);
			}
		}
	}

	return dist[v];
}
int main(){
	int n; scanf("%d",&n);
	while(n--){
		init();
		cin.ignore();
		string key;
		
		while(cin>>key && key!="*")
			dict.push_back(key);

		int sz = dict.size();
		adj.assign(sz, vi());
		sort(dict.begin(), dict.end());
		int i,j;

		for(i=0; i<sz; i++){
			for(j=0; j<sz && (i!=j); j++){
				if(ok(dict[i], dict[j])){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		/*for(i=0; i<sz; i++){
			cout<<dict[i]<<": ";
			for(j=0; j<adj[i].size(); j++){
				cout<<dict[adj[i][j]]<<" ";
			}
			cout<<endl;
		}*/
		string from, to,line;
		stringstream ss;
//		cin>>from>>to;
		char c;
		char s[101];
		while(1){
			gets(s);
			cout<<
			/*
			visited.assign(sz, 0);
			dist.assign(sz, INF);
			int ans = bfs(from, to);
			cout<<from<<" "<<to<<" "<<ans<<endl;
			cin>>from>>to;
*/		}
	}
	return 0;
}