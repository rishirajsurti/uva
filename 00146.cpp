#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char str[50];
char strrev[50];
int main(){
	int size,i,j;
	while(scanf("%s", str) && str[0]!='#'){

		size=0;
		i=0;
		while(str[i]!='\0'){
			size++;
			strrev[i] = str[i];
			i++;
		}

		//printf("%d\n", size);
		next_permutation(str, str+size);
		reverse(strrev, strrev+size);
		//printf("%s %s %d\n",str, strrev, strcmp(str,strrev) );
		
		if(strcmp(str, strrev)==0)
			printf("No Successor\n");
		else
			printf("%s\n", str);

		memset(&str[0], 0, sizeof str);
		memset(&strrev[0], 0, sizeof strrev);
		
	}
	return 0;
}