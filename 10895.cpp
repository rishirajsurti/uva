#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;

int main(){
	int m,n;
	scanf("%d %d", &m, &n); //m rows n cols given
	AdjList.assign(n+1, vi()); // n rows m cols to be obtained

	int i,j;
	for(i=0; i<=n; i++)
		AdjList[i].assign(m+1,0); //m cols

	for(i=1; i<=m; i++){
		//row wise input
		//take as column wise for transpose
		int non_zero_elements;
		vi nze_indices;
		scanf("%d", &non_zero_elements);
		nze_indices.assign(non_zero_elements+1, 0);
		for(j=1; j<=non_zero_elements; j++)
			scanf("%d", &nze_indices[j]);

		for(j=1; j<=non_zero_elements; j++)
			scanf("%d", &AdjList[nze_indices[j]][i]);

	}

	printf("%d %d\n", n,m);
	for(i=1; i<=n; i++){

		int nz_elements=0;
		vi nz_indices;
		for(j=1; j<=m; j++)
			if(AdjList[i][j] != 0){
				nz_elements++;
				nz_indices.push_back(j);
			}
		printf("%d ",nz_elements );
		for(j=0; j<nz_indices.size(); j++){
			if(j>0)
				printf(" ");
			printf("%d",nz_indices[j] );
		}
		printf("\n");
		for(j=0; j<nz_indices.size(); j++){
			if(j>0)
				printf(" ");
			printf("%d",AdjList[i][nz_indices[j]] );
		}
		printf("\n");
	}
	return 0;
}