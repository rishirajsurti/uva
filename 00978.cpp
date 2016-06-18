#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;

void printset( multiset<int, greater<int> > s){
	multiset<int, greater<int> >::iterator it;
	for(it = s.begin(); it != s.end(); it++)
		printf("%d ", *it );
	printf("\n");

}

int main(){
	int N,i,j,k;
	scanf("%d",&N);
	while(N--){

		int b,sg, sb;

		multiset<int, greater<int> > green, blue;
		vector<int> survivors;

		scanf("%d %d %d", &b, &sg, &sb);

		for(i=0; i<sg; i++){
			scanf("%d",&k);
			green.insert(k);
		}

		for(i=0; i<sb; i++){
			scanf("%d",&k);
			blue.insert(k);
		}
//		printset(green); printset(blue);

		while(!green.empty() && !blue.empty()){
			
			for(i=0; i<b && !green.empty() && !blue.empty(); i++){

				survivors.push_back(*green.begin() - *blue.begin());
				green.erase(green.begin());	blue.erase(blue.begin());
			}
			
//			printset(green); printset(blue);			
			for(i = 0; i < survivors.size(); i++){
				if(survivors[i] > 0 )
					green.insert(survivors[i]);
				else if(survivors[i] < 0)
					blue.insert(-survivors[i]);
			}
			survivors.clear();			
		}

		if(green.empty() && blue.empty())
			printf("green and blue died\n");
		else{
			multiset<int, greater<int> > *winner;
			if(green.empty()){
				printf("blue wins\n");
				winner = &blue;
			}
			else if(blue.empty()){
				printf("green wins\n");
				winner = &green;
			}
			for(multiset<int, greater<int> >::iterator it = winner->begin(); it != winner->end(); it++)
				printf("%d\n",*it );
		}

		
		if(N)	
			printf("\n");
	}	
	return 0;
}