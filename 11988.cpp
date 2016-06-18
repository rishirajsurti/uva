#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
	
		vector<char> a;
		int i;
		vector<char>::iterator it = a.end();
		
		for(i=0; s[i]; i++){
			if(s[i] == '[') it = a.begin();
			else if(s[i] == ']') it = a.end();
			else it = a.insert(it, s[i]), it++;
		}
		for(i=0; i<a.size(); i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}
/*#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	
	for(char c, line[1048576]; gets(line);){
		//printf("%s\n", line);
		string current;
		bool home = false;
		deque< string > deq;

		for(int i = 0; c = line[i]; i++){
			switch(c){
				case '[':
					if(home) deq.push_front(current);
					else deq.push_back(current);
					home = true; 
					current = "";
					break;
				case ']':
					if(home && current!=""){
						deq.push_front(current);
						current = "";
					}
					home = false;
					break;
				default:
					current.push_back(c);
					break;
			}
		}
		if(current != ""){
			if(home) deq.push_front(current);
			else deq.push_back(current);
		}
		while(!deq.empty()){
			printf("%s", deq.front().c_str());
			deq.pop_front();
		}
		printf("\n");	
	}
	return 0;
}
/*#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void printList(list<char> l){
	list<char>::iterator it;
	for(it = l.begin(); it != l.end(); it++)
		printf("%c", *it);

	printf("\n");
}
int main(){
	string input;
	int i;
	list<char> output;
	list<char>::iterator itl;
	itl = output.end();
	
	while(getline(cin, input)){
		
		for(i=0; i<input.size(); i){

			if(input[i] == "["){
				itl = output.begin();
				i++;
			}
			else if(input[i] == "]"){
				itl = output.end();
			}

		}

	}
	return 0;
}*/