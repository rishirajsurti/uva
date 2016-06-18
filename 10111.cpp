#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;
typedef unsigned long long llu;
const int INF = INT_MAX;

void mark(vi &d, int i, int j, int c){
	d[i] = d[i] | c;
	d[j+4] = d[j+4] | c;
	if(i == j) d[4+4] = d[4+4] | c;
	if(i+j == 3) d[4+4+1] = d[4+4+1] | c;

}

iii backtrack( mi &m, vi &d, int c, int level){
	
}


int main(){
	string s;
	while(ci>> s, s == "?"){
		vi d(10, 0);
		mi m(4);
		for(int i =0; i<4; i++){
			m[i].resize(4,0);
			cin>>s;
			for(int j = 0; j < 4; j++){
				switch(s[j]){
					case 'x': m[i][j] = 1; mark(d, i, j, 1); break;
					case 'o': m[i][j] = 2; mark(d, i, j, 2); break;
				}
			}
		}
		auto r = backtrack(m, d, 1, 0);
	}
}