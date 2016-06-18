#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	int pos = find(a.begin(), a.end(), 2) - a.begin() ;
	printf("%d\n", pos);
	return 0;
}

/*#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	//printf("putc(32, stdout)\n");
	//putc(32, stdout);
	cout<< (5<<1)<<endl;
//	printf("%d\n", __builtin_popcount(5));
	char c;
	int nc;
	scanf("%c",&c);
	printf("%d\n", c);
	return 0;
}*/