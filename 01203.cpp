#include <queue>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;


int main(){
	int k,i,j;
	string input;
	int query, period;
	priority_queue< pair<int, int> > pq;
	pair<int, int> result;
	map<int, int> mapper;
	while(cin>>input){
		if(input == "#")
			break;

		cin>> query >> period;
		query = -query;
		period = -period;
		pq.push( make_pair(period, query));
		
		if(!mapper.count(query))
			mapper[query] = period;

	}

	scanf("%d",&k);
	

	//priority_queue< pair<int, int> >::iterator it;
	//for(it = pq.begin(); it != pq.end(); it++)
	//	printf("%d %d\n", it.first, it.second);

	for(i=1; i<=k; i++){
		result = pq.top();
		printf("%d\n",-result.second);
		pq.pop();
		result.first += mapper[result.second];
		pq.push(result);	

	}
	
}