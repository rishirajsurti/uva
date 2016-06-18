#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <cstring>
using namespace std;

#define MAX 3005

bool seq[MAX];
int main(){

	int n;
	while(scanf("%d",&n)!=EOF){
	
	int pre, currentNum, total;
	scanf("%d",&currentNum);
	pre = currentNum;
	bool es = true;
	memset( seq, false, sizeof seq);

	for(int i = 1; i < n; i++){
		scanf("%d", &currentNum);
		total = abs( pre-currentNum);
		if(total <= 0 || total > n-1){
			es = false;
		}else if(seq[total]){
			es = false;
		}
		seq[total] = true;
		pre = currentNum;
	}

	if(es)
		printf("Jolly\n");
	else
		printf("Not jolly\n");
	}

}