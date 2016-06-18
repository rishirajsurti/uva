#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	map<int, int> c; //connections
	vector<bool> wake;
	wake.assign(26, false);
	string s;
	cin>>s;
	wake[s[0]-'A'] = true;
	wake[s[1]-'A'] = true;
	wake[s[2]-'A'] = true;

	c[s[0]-'A'] = 3;
	c[s[1]-'A'] = 3;
	c[s[2]-'A'] = 3;

	int i,j,k;
	adj.assign(26, vi());
	for(i=0; i<m; i++){
		cin>>s; cout<<s<<endl;
		adj[s[0]-'A'].push_back(s[1]-'A');
		adj[s[1]-'A'].push_back(s[0]-'A');
		c[s[0]-'A'] = 0;
		c[s[1]-'A'] = 0;
	}

	int ans = 0;
	bool ok=false;

	for(k=0; k<4*n && !ok; k++){
		ok = true;
		for(map<int,int>::iterator it = c.begin(); it!=c.end(); it++)
			if(it->second < 3)
				ok = false;

		for(i=0; i<n; i++){
			for(j=0; j<adj[i].size(); j++){
				if(wake[adj[i][j]])
					++c[i]; // increase connections with woken up areas
			}
			if(c[i] >=3) wake[i] = true;
		}
		ans++;
	}
	
	if(ok == false)
		printf("THIS BRAIN NEVER WAKES UP\n");
	else
		printf("WAKE UP IN, %d, YEARS\n", ans-1);
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;
map<int, bool> woken;




int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		adj.assign(n, vi());
		vi visited(n, 0);
		int m; scanf("%d", &m);
		string s;
		//store as adj list;
		//store woken up in vector
		// if can wake up- do dfs with woken up nodes
		// if any node left out.. cannot awake
		//else
		// for each node.. if >=3 woken adj nodes -> wake it up.
		// for each adj node check if it is woken O(1)
		
		int i,j; 
		for(i=0; i<26; i++) woken[i] = false;
		cin>>s;
		queue<int> q;
		woken[s[0]-'A'] = woken[s[1]-'A'] = woken[s[2]-'A'] = true;
	
		visited[s[0]-'A'] = 3;
		visited[s[1]-'A'] = 3;
		visited[s[2]-'A'] = 3;

		q.push(s[0]-'A');
		q.push(s[1]-'A');
		q.push(s[2]-'A');

		for(i=0; i<m; i++){
			cin>>s;
			adj[s[0]-'A'].push_back(s[1]-'A');
			adj[s[1]-'A'].push_back(s[0]-'A');
			
		}
		int vis = 0;
		
		while(!q.empty()){
			int front = q.top(); q.pop();
			++vis;
			for(i = 0; i < adj[front].size(); i++){
				++visited[adj[front][i]];
				if(visited[adj][front][i] == 3)
					q.push(adj[front][i]);
			}
		}
	}
}*/

/*#include <cstdio>
#include <queue>
using namespace std;
struct edge {
	int next, to;
} e[10048];

int ecnt, next[32], vis[32];

void add_edge(int from, int to){

	edge &E = e[ecnt];
	E.next = next[from]; 
	E.to = to;
	next[from] = ecnt++; 
//	printf("from %d, to %d, e[%d].next = %d, e[%d].to = %d next[%d] = %d\n",from, to, ecnt, E.next, ecnt, E.to,from, ecnt );
}

int main(){
	queue< pair<int, int> > q;
	char a,b,c;

	for(int m, n; scanf("%d %d", &n, &m) == 2;){

		int at, d, v, visited = ecnt = 0;
		
		for(int i = 0; i<26; i++) vis[i] = 0, next[i] = -1;
		scanf(" %c%c%c",&a, &b, &c);

		q.push(make_pair(a - 'A', 0)); vis[a-'A'] = 3;
		q.push(make_pair(b - 'A', 0)); vis[b-'A'] = 3;
		q.push(make_pair(c - 'A', 0)); vis[c-'A'] = 3;

		while(m--){
			scanf(" %c%c", &a,&b);
			add_edge(a-'A', b-'A');
			add_edge(b-'A', a-'A');
		}

/*		for(int i =0; i<ecnt; i++)
			printf("e[%d].next = %d, e[%d].to= %d\n",i, e[i].next, i,e[i].to);

		for(int i = 0; i<26; i++)
			printf("%d\n",next[i] );
*/
	/*	while(!q.empty()){
			at = q.front().first;
			d = q.front().second;
			
			q.pop();
			++visited;
			for(at = next[at]; at != -1; at = e[at].next)
				if(++vis[v = e[at].to] == 3) q.push(make_pair(v, d+1));
		}

		if(visited == n) printf("WAKE UP IN, %d, YEARS\n", d);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}*/