#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000
int young[26][26], old[26][26], ans[26][26];
int incy[26], inco[26]; //included in young/old;

void initial(){
	int i,j;
	for(i=0; i<26; i++){
		for(j=0; j<26; j++){
			young[i][j] = INF;
			old[i][j] = INF;
			ans[i][j] = INF;
		}
		young[i][i] = 0;
		old[i][i] = 0;
		ans[i][i] = 0;
		incy[i] = 0;
		inco[i] = 0;
	}
}

int main(){
	int n;
	char u;
	while(scanf("%d%c",&n, &u), n){
		int i,j,k, wt;
		char x,y,z,w;
		initial();
		for(i=0; i<n; i++){
			scanf("%c %c %c %c %d%c",&x, &y, &z, &w, &wt, &u);
		//	printf("print %c %c %c %c %d %c",x,y,z, w, wt, u );
			if(x == 'Y'){
				young[z-'A'][w-'A'] = wt;
				
				if(y=='B')
					young[w-'A'][z-'A'] = wt;
				incy[z-'A'] = 1; 
				incy[w-'A'] = 1;

			} else if(x=='M'){

				old[z-'A'][w-'A'] = wt;
				
				if(y=='B')
					old[w-'A'][z-'A'] = wt;
				
				inco[z-'A'] = 1; 
				inco[w-'A'] = 1;
			}
		}
		
		
		for(k = 0; k < 26; k++)
			for(i=0; i < 26; i++)
				for(j=0; j<26; j++)
					young[i][j] = min(young[i][j], young[i][k] + young[k][j]);

		for(k = 0; k < 26; k++)
			for(i=0; i < 26; i++)
				for(j=0; j<26; j++)
					old[i][j] = min(old[i][j], old[i][k] + old[k][j]);


		scanf("%c %c%c", &x, &y, &u);
		//printf("print %c %c", x, y);
		int cost=INF, place;
		i = x-'A';
		j = y-'A';

		/*for(k=0; k<26; k++){

			if(young[i][k] == INF || old[j][k] == INF)
				continue;
			else{

				if((young[i][k] + old[j][k]) < cost){
					cost = young[i][k] + old[j][k];
					place = k;
				}
				if(young[i][j] < cost){
					cost = young[i][j];
					place = j;
				}
				if(old[j][i] < cost){
					cost = old[j][i];
					place = i;
				}

			}
		}*/

		for(k = 0 ; k < 26; k++){
			if(young[i][k] == INF || old[j][k] == INF)
				continue;

			if(young[i][k] + old[j][k] < cost){
				cost = young[i][k] + old[j][k];
			}
		}

		if(cost == INF)
			printf("You will never meet.\n");
		else{
			printf("%d", cost);
			for(place = 0; place < 26; place++){
				if(young[i][place]+old[j][place] == cost)
					printf(" %c", place+'A');
			}
			printf("\n");
		}
		/*for(k=0; k<26; k++){
			if(incy[k] && inco[k])
			for(i=0; i<26; i++){//young
				if(incy[i])
				for(j=0; j<26; j++){//old
					if(inco[j])
						ans[i][j] = min(young[i][k] + old[j][k], min(young[i][j], old[j][i]));
				}
			}
		}*/

		
		

	}
	return 0;
}