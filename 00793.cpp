#include <cstdio>
using namespace std;

int p[1048576];

int root(int a){
	return p[a] = (p[a]==a ? a : root(p[a]));
}

void union_find(int a, int b){
	p[root(a)] = root(b);
}

int main(){

	char corq, line[1024]; // c or q, 
	int t;
	scanf("%d", &t);
	while(t--){
		int n, s = 0, u = 0;
		scanf("%d\n", &n);

		for(int i=1; i<=n; i++) p[i] = i;
		for(int a,b; fgets(line, 1024, stdin) && sscanf(line, "%c %d %d", &corq, &a, &b)==3; ){
			if(corq == 'c')
				union_find(a,b);
			else{
				if(root(a)== root(b)) ++s;
				else ++u;
			}
		}
		printf("%d,%d\n", s,u);
		if(t) printf("\n");
	}
}

/*//union find ds
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

#include <cstring>
using namespace std;

//1-based indexing
typedef vector<int> vi;

class UnionFind{
private:
	vi p,rank, setSize;
	int numSets;
public:
	UnionFind(){}
	UnionFind(int N){

		rank.assign(N+1, 0);
		setSize.assign(N+1, 1);
		numSets = N;
		p.assign(N+1, 0);
		for(int i=1; i<=N; i++)
			p[i] = i;
	}

	int findSet(int i){
		return (p[i]==i ? i : (p[i] = findSet(p[i])));
	}

	bool isSameSet(int i, int j){
		return findSet(i)==findSet(j);
	}

	void setUnion(int i, int j){

		if(!isSameSet(i, j)){
			int x = findSet(i);
			int y = findSet(j);

			if(rank[x] > rank[y]){
				p[y] = x;	setSize[x] += setSize[y];
			}
			else{
				p[x] = y;	setSize[y] += setSize[x];
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}

};

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		cin.ignore();
		int n_comp;
		int a,b,q;
		int succ=0, unsucc=0;
		char input[1000];
		scanf("%d",&n_comp);
		UnionFind uf(n_comp);
		while(true){


			gets(input);

			if(strcmp(input,"")==0 || feof(stdin))	break;	
			sscanf(input,"%c %d %d",&q, &a, &b);			
			if(q=='c')
				uf.setUnion(a,b);
			else{
				if(uf.isSameSet(a,b))
					succ++;
				else
					unsucc++;
			}
		}
		/*
		scanf("%c ", &query);
		printf("query = %c here\n", query );
		while(query != '\n'){

			scanf("%d %d\n", &a, &b);

			printf("query = %c, a = %d, b = %d\n", query, a, b );
			if(query == 'c')
				uf.setUnion(a,b);

			else if(query=='q'){
				if(uf.isSameSet(a,b))
					succ++;
				else
					unsucc++;
			}
			scanf("%c",&query);
		}
		*/
/*		printf("%d,%d\n",succ, unsucc );
	}
	if(t)
		printf("\n");
}*/