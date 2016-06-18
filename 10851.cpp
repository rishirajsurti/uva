#include <cstdio>
#include <string.h>

using namespace std;

int main(){
	char str[100], input[20][100];
	int i,j,k,t;
	gets(str);
	sscanf(str, "%d", &t);
	while(t--){
		int n = 0;
		while(gets(input[n]) && input[n][0])
			n++;
		/*for(i=0; i<10; i++)
			gets(input[i]);*/

		int len = strlen(input[0]) - 2; // m+2 cols, m len string

		for(j=1; j<=len; j++){ //column wise
			for(k=32; k<128; k++){
				for(i=1; i<=8; i++){ // 0, 9 are irrelevant
					if(input[i][j] == '\\'){
						if(k/(1<<(i-1)) % 2 == 0)
							break;
					} else{
						if(k / (1<<(i-1)) %2)
							break;
					}
				}
				if(i==9) printf("%c", k);
			}
		}
		printf("\n");
		}
		return 0;
}
/*#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

char b(int i, char ch){
	int powr = 1<<i;
	int asc = (int) ch;
	int ans;
	if(ch == '/'){
		ans = powr * 2;
	}
	else if(ch == '\\'){

	}
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
	
	int i,j;
	string row[10];
	string ans;

	}
}*/