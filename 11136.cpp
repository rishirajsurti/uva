#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main(){

	int n;
	multiset<int> bills;
	multiset<int>::iterator it1;
	multiset<int>::reverse_iterator it2;

	while(cin >> n){
		if(n==0)
			break;
		int i;
		unsigned long long cost=0;
		bills.clear();
		for(i=0; i<n; i++){

		int k,bill;
		cin>>k;
		while(k--){
			//scanf("%d",&bill);
			cin>>bill;
			bills.insert(bill);
		}

		it1 = bills.begin();
		it2 = bills.rbegin();

		cost += *it2 - *it1;

		bills.erase(it1);
		bill = *it2;
		it1 = bills.find(bill);
		bills.erase(it1);
		}
		cout<<cost<<endl;
	}
	return 0;
}

/*#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		int b, cost = 0, k;
		set<int> min,max;
		int j,l;
		for(j=0; j<n; j++){
		//while(scanf("%d",&b), b){
		scanf("%d", &b);
		for(l = 0; l <b; l++){
			for(int i =0; i<b; i++){
				scanf("%d", &k);
				max.insert(k);
				min.insert(k);
			}
//			printf("%d %d\n",*max.rbegin(), *min.begin() );
			if(!max.empty() && !min.empty()){
				cost += *max.rbegin() - *min.begin();
				set<int>::reverse_iterator it = max.rbegin();
				max.erase(*it);
				min.erase(*min.begin());
			//} 
			}else if(max.empty()){
				cost += *min.rbegin() - *min.begin();
				set<int>::reverse_iterator it = min.rbegin();
				min.erase(*it);
				min.erase(*min.begin());
			}else if(min.empty()){
				cost += *max.rbegin() - *max.begin();
				set<int>::reverse_iterator it = max.rbegin();
				max.erase(*it);
				max.erase(*max.begin());
			}

			}
		}
		printf("%d\n", cost);
	}
	return 0;
}*/