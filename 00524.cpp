#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
//#include <cstring>
using namespace std;
vector<int> a;

int prime[33]={ 0, 1, 1, 1, 0, 1, 0, 1, 
				0, 0, 0, 1, 0, 1, 0, 0,
				0, 1, 0, 1, 0, 0, 0, 1, 
				0, 0, 0, 0, 0, 1, 0, 1, 0};

bool satisfies(){
	int i;
	bool ok = true;
	//printf("a[0] = %d\n",a[0] );
	for(i = 1; i<a.size()-1; i++){
		int num1 = a[i]+a[i-1];
		int num2 = a[i]+a[i+1];
		//printf("%d %d,  %d %d\n",num1, prime[num1], num2, prime[num2] );
		if(!prime[num1] || !prime[num2]){

			ok = false; break;
		}
	}	
	return ok;
}

int main(){
	int n, j=1;
	while(scanf("%d", &n)!= EOF){
		printf("Case %d:\n",j );
		
		a.clear(); a.push_back(1);
		int i;
		for(i=2; i<=n; i++)
			a.push_back(i);
		a.push_back(1);
		//1 2 3 4 5 6 1
		vector<int>::iterator it1 = a.begin();
		vector<int>::iterator it2 = a.end();
		vector<int>::iterator it;
		it1++; it2--;
		do{
			if(satisfies()){
				for(i=0; i<a.size()-1; i++){
					if(i>0) printf(" ");
					printf("%d",a[i] );
				}
				printf("\n");

			}
		} while(next_permutation(++(a.begin()), --(a.end())));

		printf("\n");
		j++;
	}
	return 0;
}