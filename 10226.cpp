
#include <cstdio>
#include <map>
#include <string>
using namespace std;

map< string, int > m;
char name[32];
int main(){

	int t;
	scanf("%d\n", &t);
	while(t--){

		int total_trees = 0;
		m.clear();
		while(gets(name) && *name){
			++total_trees;
			++m[name];
		}

		for(map<string, int>::iterator it = m.begin(); it!= m.end(); it++)
			printf("%s %.4lf\n",it->first.c_str(), (100.0*it->second)/total_trees );
		if(t)
			printf("\n");
	}
	return 0;
}

/*#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int t;
	char c;
	string input;
	map< string, int> trees;
	scanf("%d", &t);
	scanf("%c",&c);
	while(t--){

			cin >> input;
			
			while(input != "\n"){

			if(trees.find(input) != trees.end())
				trees[input]++;
			else
				trees[input] = 1;
			
			cin >> input;
			}	
	
	for(map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
		printf("%s %d\n", ((string)it->first).c_str(), it->second);
			
	}

	
	return 0;
}*/