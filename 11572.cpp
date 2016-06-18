#include <bits/stdc++.h>
using namespace std;

int main(){
	int cases, n; 
	int snowflake;
	int *snowflakes = new int[1000001];
	int first, current, result, counter;

	cin>> cases;
	while(cases--){
		first = current = result = counter = 0;
		map<int, bool> taken;
		cin>> n;
		while(n--){
			cin>>snowflake;
			snowflakes[current++] = snowflake;

			if(taken.find(snowflake) != taken.end()){
				//if element is found before
				if(counter > result) result = counter;
				while(true){
					//while obtain the repeated item
					//erase from map
					//reduce the counter
					if(snowflakes[first] == snowflake) break;
					taken.erase(snowflakes[first]);
					counter--;
					first++;
				}
				first++;
			} else{
				//if element is not found before;
				counter++;
				taken[snowflake] = true;
			}
			
		}
		if(counter > result) result = counter;
		cout<<result <<endl;
	}
	delete snowflakes;
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		vector<int> a(n);
		int i;
		for(i=0; i<n; scanf("%d", &a[i++]));
		int low, high;
		map<int, int> m;

		low = high = 0;
		int cursize, maxsize= -1;
		for(i=0; i<n; i++){
			
			if(m.find(a[i]) == m.end()){
				//if element not encountered before
				// it is unique
				// put it in bag;
				high++;
				m[a[i]] = i;
			}
			else{
				//element found before;
				// remove the previous element;
				//check if size is bigger
				maxsize = max(maxsize, high - low);
				int old_low = m[a[i]];
				low = old_low+1;
				m[a[i]] = i; // new index;
				//remove all elements previously inserted;
				int j = old_low-1;
				while(j>=0) m[a[j--]]=0;
				//high remains as it is;
			}
		}
		printf("%d\n", maxsize);
	}
	return 0;
}

/*#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int t,n,i,snow;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int N = n;
		map<int, int> mapper;
		int max_items = 0, items = 0;
		while(n--){
			
			scanf("%d",&snow);
		
			if(!mapper.count(snow)){
				items++;
				++mapper[snow];
				max_items = max(max_items, items);
			} 
			else{
	//			int m = mapper[snow] + 1;
				++mapper[snow];

			}
			
		}
		printf("%d\n", max_items > N ? N : max_items);
	}
	return 0;
}*/