#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string input, target;
	
	while(cin>>input){
		cin>>target;
//		cout<<input<<" "<<target<<endl;
		vector<char> operations;
		
		int i;
		for(i=0; i<input.size(); i++)
			operations.push_back('i');
		
		for(i=0; i<input.size(); i++)
			operations.push_back('o');

		printf("[\n");
		do{

			int j = 0;
			int count = 0;
			bool ok = true;
			for(j=0; j<operations.size() && ok; j++){
				if(operations[j] == 'i') count++;
				else count--;
				if(count<0) ok = false; 
			}
			if(!ok) continue;
			j=0;
			string output="";
			stack<char> s;

			for(i=0 ; i<operations.size(); i++){
//				printf("%c ",operations[i] );
				if(operations[i] == 'i' && j < input.size()){
					s.push(input[j]);
					j++;
				}
				else if(operations[i] == 'o' && !s.empty()){
					output += s.top();
					s.pop();
				}
			}
//			cout<<" "<<output<<endl;
			if(output == target){
				for(i=0; i<operations.size(); i++){
					if(i>0)
						printf(" ");
					printf("%c",operations[i]);
				}
				printf("\n");
			}
		}while(next_permutation(operations.begin(), operations.end()));

		printf("]\n");
	}
	return 0;
}