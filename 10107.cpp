#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int main(){
	int n, size=0;;
	vi a;
	while(scanf("%d", &n) != EOF){
		a.push_back(n);
		size++;
		sort(a.begin(), a.end());
		if(a.size() % 2 == 0){
			printf("%d\n", (a[a.size()/2] + a[a.size()/2 - 1])/2);
		}
		else
			printf("%d\n", a[a.size()/2]);
	}
	return 0;
}