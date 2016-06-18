/*
Number of connected components: V-E
for vertices which have an edge use vector<bool>
acorns: subtract <above line> from V-E

ASCII CHARS
A-65
Z-90
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string input;
		int edges = 0, n_vertices=0; // CC= V-E
		int vertices_which_have_edges = 0;
		int acorns;
		vector<bool> vertices;
		vertices.assign(26, false); //initially no vertex incident
		//as edges encountered set to true;

		while(cin >> input){
			if((int)input[0] == 42)
				break;
			
			edges++;
			//(A,B)
			//01234 (input string index)
			//input[1], input[3]

			if(!vertices[((int)input[1])-65]){
				
				vertices[((int)input[1])-65] = true;
				vertices_which_have_edges++;
			}

			if(!vertices[((int)input[3])-65]){
				
				vertices[((int)input[3])-65] = true;
				vertices_which_have_edges++;
			}

		}
		cin>>input;
		n_vertices = (input.size()+1)/2;
		int trees = n_vertices - edges;
		//trees include acorns

		//acorns: n_vertices - vertices which have edges;
		acorns = n_vertices - vertices_which_have_edges;
		printf("There are %d tree(s) and %d acorn(s).\n",trees - acorns, acorns );
	}

	return 0;
}