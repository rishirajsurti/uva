#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;
typedef unsigned long long llu;
#define INF INT_MAX
#define MAX 2002

int w[MAX][26];

vector< vector<iii> > words;
map<string, int> language_index;

int dijkstra(int start, int finish){

	int i,j;
	for(i=0; i<MAX; i++){
		for(j=0; j<26; j++)
			w[i][j] = INF;
	}

	int best = INF;
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	w[start][0] = 0;
	w[start][1] = 0;
	pq.push(iii(0, start, 0));
	pq.push(iii(0, start, 1));

	while(!pq.empty()){
		int d= get<0>(pq.top());
		int u = get<1>(pq.top());
		int a = get<2>(pq.top());
		pq.pop();
		if(w[u][a] != d) continue;
		if(d >= best) continue;

		for(auto e : words[u]){
			auto va = get<2>(e);
			if(va == a) continue;
			auto v = get<1>(e);
			auto ew = get<0>(e);
			if(w[v][va] <= d + ew) continue;
			w[v][va] = d+ew;
			if(v== finish){
				best = min(best, w[v][va]);
			}
			pq.push(iii(w[v][va], v, va));
		}
	}
	return best;
}


int get_index(string a){
	if(language_index.count(a) == 0){
		language_index[a] = words.size();
		words.resize(words.size() + 1);
	}
	return language_index[a];
}

int main(){
	int n;
	while(cin>>n, n){
		language_index.clear();
		words.clear();
		string a, b, c;
		cin >> a >> b;
		int start = get_index(a);
		int finish = get_index(b);
		while(n--){
			cin >> a>> b >> c;
			int u = get_index(a);
			int v = get_index(b);
			int f = c[0] - 'a';
			int w = c.size();

			words[u].push_back(iii(w, v, f));
			words[v].push_back(iii(w, u, f));
		}
		int result = dijkstra(start, finish);

	}
}

/*#include <bits/stdc++.h>
using namespace std;

#define INF 1e6

typedef pair<string, string> ss;
typedef pair<int, ss> iss; //int for length of word; ll push in pq;
typedef pair<string, ss> sss;

typedef vector<iss> viss;
typedef pair<int, string> is;
vector<viss> adj;


int main(){
	int m;
	while(scanf("%d", &m), m){
		adj.assign(m, viss());
		vector<string> e; //elements;
		vector<sss> data;
		string from, to, word;
		string s, t;
		cin>>s>>t;
		int i,j;
		for(i=0; i<m; i++){
			cin>>from>>to>>word;

			if(find(e.begin(), e.end(), from) == e.end())
				e.push_back(from);
			if(find(e.begin(), e.end(), to) == e.end())
				e.push_back(to);

			data.push_back(make_pair( word, ss(from, to)));
		}
		sort(e.begin(), e.end());

		for(i=0; i<data.size(); i++){
			word = data[i].first;
			from = data[i].second.first;
			to = data[i].second.second;
			int idf, idt;
			idf = find(e.begin(), e.end(), from) - e.begin();
			idt = find(e.begin(), e.end(), to) - e.begin();
			adj[idf].push_back(make_pair(word.length(), ss(to, word)));
			adj[idt].push_back(make_pair(word.length(), ss(from, word)));
		}
		//adj[idf] list of words reachable from language e[idf]


		vector<int> visited(m, 0);
		vector<string> dist(e.size(), INF);
		dist[from] = 0;
		priority_queue<iss, vector<iss>, greater<iss> > pq;

		int idx = find(e.begin(), e.end(), s) - e.begin();

		for(i=0; i<adj[idx].size(); i++){
			pq.push(adj[idx][i].first, ss(adj[idx][i].second.first, adj[idx][i].second.second));
		}

		while(!pq.empty()){
			iss front = pq.top(); pq.pop();

			if(dist[from] + front.first < dist[front.second.first]){
				dist[front.second.first] = dist[from]+from.first;
				for(i=0; i<adj[front.second.first].size(); i++){
					pq.push(adj[front.second.first][i].second.second.size(), ss(adj[front.second.first][i].second.first,adj[front.second.first][i].second.first ));
				}
			}
		}
		printf("%d\n", dist[t]);
	}
	return 0;
}*/