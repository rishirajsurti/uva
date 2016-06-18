#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string input;
	while(cin>>input){
		if(input == "#")
			break;

		cout<<next_permutation(input.begin(), input.end())<<endl;

	}
	return 0;
}